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
package com.wiyun.engine.chipmunk;

import com.wiyun.engine.BaseWYObject;

/**
 * 用于在物体上播放一个动画，如果动画的帧大小不一样，这个物体的大小也会变化，不过
 * ShapeAnimation并不会在空间的step中进行，所以是安全的 
 */
public class ShapeAnimation extends BaseWYObject {
	/**
	 * 可以获得动画结束事件的接口定义 
	 */
	public static interface Callback {
		/**
		 * 在动画结束时调用
		 * 
		 * @param shapePointer Shape底层结构指针
		 */
		public void onAnimationEnd(int shapePointer);
		
		/**
		 * 如果调用stop时，动画还未停止，这将调用此回调方法
		 * 
		 * @param shapePointer Shape底层结构指针
		 */
		public void onAnimationAborted(int shapePointer);
	}
	
	public static ShapeAnimation from(int pointer) {
		return pointer == 0 ? null : new ShapeAnimation(pointer);
	}
	
	private native void nativeInit();
	
	protected ShapeAnimation(int pointer) {
		super(pointer);
	}

	/**
	 * 对某个物体进行动画播放
	 * 
	 * @param shape {@link Shape}
	 */
	public native void start(Shape shape);
	
	/**
	 * 强行停止动画，如果动画还未停止，会造成onAnimationAborted回调
	 * 被调用。这个方法不是线程安全的，如果不是在OpenGL线程中调用，
	 * 要注意同步问题
	 */
	public native void stop();
	
	public native boolean isLoop();

	public native void setLoop(boolean loop);

	public native float getDuration();

	public native void setDuration(float duration);

	public native void setCallback(Callback callback);

	public native boolean isAutoSize();

	public native void setAutoSize(boolean autoSize);
}
