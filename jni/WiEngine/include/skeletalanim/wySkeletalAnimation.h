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
#ifndef __wySkeletalAnimation_h__
#define __wySkeletalAnimation_h__

#include "wyObject.h"
#include "wyTransform.h"

class wySpineLoader;

/**
 * general model of skeletal animation
 */
class WIENGINE_API wySkeletalAnimation : public wyObject {
	friend class wySpineLoader;
	
public:
	/// transform list
	typedef vector<wyTransform*> TransformPtrList;
	
private:
	/// list of transform
	TransformPtrList m_transList;
	
	/// duration time of this animation
	float m_duration;
	
protected:
	wySkeletalAnimation();
	
public:
	virtual ~wySkeletalAnimation();
	static wySkeletalAnimation* make();
	
	/// add transform
	void addTransform(wyTransform* t);
	
	/// get list of transform
	TransformPtrList& getTransformList() { return m_transList; }
	
	/// get duration time
	float getDuration() { return m_duration; }
	
	/// dump info, for debug purpose
	void dump();
};

#endif // __wySkeletalAnimation_h__
