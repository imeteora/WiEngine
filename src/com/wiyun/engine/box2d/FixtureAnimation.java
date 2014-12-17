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
package com.wiyun.engine.box2d;

import com.wiyun.engine.BaseWYObject;
import com.wiyun.engine.box2d.dynamics.Fixture;
import com.wiyun.engine.opengl.Texture2D;

/**
 * 用于在物体上播放一个动画.
 */
public class FixtureAnimation extends BaseWYObject {
	/**
	 * 可以获得动画结束事件的接口定义 
	 */
	public static interface Callback {
		/**
		 * 在动画结束时调用
		 * 
		 * @param fixturePointer fixture底层结构指针
		 */
		public void onAnimationEnd(int fixturePointer);
		
		/**
		 * 如果调用stop时，动画还未停止，这将调用此回调方法
		 * 
		 * @param fixturePointer fixture底层结构指针
		 */
		public void onAnimationAborted(int fixturePointer);
	}
	
	public static FixtureAnimation from(int pointer) {
		return pointer == 0 ? null : new FixtureAnimation(pointer);
	}
	
	private native void nativeInit();
	
	protected FixtureAnimation(int pointer) {
		super(pointer);
	}
	
	private native void nativeAddFrame(float duration, Texture2D tex);

	/**
	 * 对某个物体进行动画播放
	 * 
	 * @param fixture {@link Fixture}
	 */
	public native void start(Fixture fixture);
	
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
}
