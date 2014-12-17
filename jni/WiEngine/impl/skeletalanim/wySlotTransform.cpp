/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include "wySlotTransform.h"
#include "wySkeletalSprite.h"
#include "wyUtils.h"
#include "wyLog.h"
#include "wySpriteEx.h"
#include "wyTexture2D.h"

wySlotTransform::wySlotTransform() :
		m_slotName(NULL) {
}

wySlotTransform::~wySlotTransform() {
	if(m_slotName) {
		wyFree((void*)m_slotName);
		m_slotName = NULL;
	}
	
	for(SkinKeyFrameList::iterator iter = m_skfList.begin(); iter != m_skfList.end(); iter++) {
		wyFree((void*)iter->skinName);
	}
}

wySlotTransform* wySlotTransform::make() {
	wySlotTransform* bt = WYNEW wySlotTransform();
	return (wySlotTransform*)bt->autoRelease();
}

void wySlotTransform::setSlotName(const char* name) {
	if(m_slotName) {
		wyFree((void*)m_slotName);
		m_slotName = NULL;
	}
	m_slotName = wyUtils::copy(name);
}

void wySlotTransform::addSkinKeyFrame(SkinKeyFrame kf) {
	m_skfList.push_back(kf);
}

void wySlotTransform::addColorKeyFrame(ColorKeyFrame kf) {
	m_ckfList.push_back(kf);
}

void wySlotTransform::populateFrame(float time) {
	// process skin frame
	{
		// set time to current time
		m_currentSkin.time = time;
		m_currentSkin.valid = true;
		
		// if empty, just set to zero
		// if not, found key frame, do interpolation if needed
		if(m_skfList.empty()) {
			m_currentSkin.valid = false;
		} else {
			SkinKeyFrameList::iterator iter = m_skfList.begin();
			for(; iter != m_skfList.end(); iter++) {
				SkinKeyFrame& kf = *iter;
				if(time < kf.time) {
					if(iter == m_skfList.begin()) {
						m_currentSkin.skinName = kf.skinName;
					} else {
						SkinKeyFrame& prevKf = *(iter - 1);
						wyPoint t = getInterpolationTime(prevKf.time, kf.time, time, prevKf.interpolator);
						if(t.x >= 1)
							m_currentSkin.skinName = kf.skinName;
						else
							m_currentSkin.skinName = prevKf.skinName;
					}
					break;
				} else if(time == kf.time) {
					m_currentSkin = kf;
					break;
				}
			}
			
			// if exceed last one
			if(iter == m_skfList.end()) {
				m_currentSkin.skinName = m_skfList.rbegin()->skinName;
			}
		}
	}
	
	// process color frame
	{
		// set time to current time
		m_currentColor.time = time;
		m_currentColor.valid = true;
		
		// if empty, just set to zero
		// if not, found key frame, do interpolation if needed
		if(m_ckfList.empty()) {
			m_currentColor.valid = false;
		} else {
			ColorKeyFrameList::iterator iter = m_ckfList.begin();
			for(; iter != m_ckfList.end(); iter++) {
				ColorKeyFrame& kf = *iter;
				if(time < kf.time) {
					if(iter == m_ckfList.begin()) {
						m_currentColor.color = kf.color;
					} else {
						ColorKeyFrame& prevKf = *(iter - 1);
						wyPoint t = getInterpolationTime(prevKf.time, kf.time, time, prevKf.interpolator);
						m_currentColor.color = t.x * (kf.color - prevKf.color) + prevKf.color;
					}
					break;
				} else if(time == kf.time) {
					m_currentColor = kf;
					break;
				}
			}
			
			// if exceed last one
			if(iter == m_ckfList.end()) {
				m_currentColor.color = m_ckfList.rbegin()->color;
			}
		}
	}
}

bool wySlotTransform::applyTo(wySkeletalSprite* owner) {
	wySkeleton* s = owner->getSkeleton();
	wySlot* slot = s->getSlot(m_slotName);
	if(!slot)
		return false;
	
	// get state of this owner
	wySlot::State& state = slot->getState(owner);
	wySpriteEx* sprite = state.sprite;
	
	// check sprite
	if(!sprite)
		return false;
	
	// set skin texture
	if(m_currentSkin.valid && !slot->hasFlag(wySlot::FIXED_ATTACHMENT)) {
		state.activeAttachmentName = m_currentSkin.skinName;
        wyAttachment* attachment = slot->getAttachment(m_currentSkin.skinName);
        if(attachment) {
            wyTexture2D* tex = wySkeleton::createRelatedTexture(s, attachment->getPath());
            sprite->setTexture(tex);
        }
	}
	
	// set color
	if(m_currentColor.valid && !slot->hasFlag(wySlot::FIXED_COLOR)) {
		state.color = m_currentColor.color;
		sprite->setColor(wyc4bFromInteger(m_currentColor.color));
	}
	
	return true;
}

void wySlotTransform::dump() {
	// dump slot skin key frame
	for(SkinKeyFrameList::iterator iter = m_skfList.begin(); iter != m_skfList.end(); iter++) {
		SkinKeyFrame& kf = *iter;
		LOGD("skin key frame, time: %f, skin: %s", kf.time, kf.skinName);
	}
	
	// dump slot color key frame
	for(ColorKeyFrameList::iterator iter = m_ckfList.begin(); iter != m_ckfList.end(); iter++) {
		ColorKeyFrame& kf = *iter;
		LOGD("color key frame, time: %f, color: 0x%x", kf.time, kf.color);
	}
}