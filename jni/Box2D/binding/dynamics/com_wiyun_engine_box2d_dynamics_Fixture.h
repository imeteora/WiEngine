/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_wiyun_engine_box2d_dynamics_Fixture */

#ifndef _Included_com_wiyun_engine_box2d_dynamics_Fixture
#define _Included_com_wiyun_engine_box2d_dynamics_Fixture
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_wiyun_engine_box2d_dynamics_Fixture
 * Method:    nativeGetBody
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_nativeGetBody
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_box2d_dynamics_Fixture
 * Method:    testPoint
 * Signature: (FF)Z
 */
JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_testPoint
  (JNIEnv *, jobject, jfloat, jfloat);

/*
 * Class:     com_wiyun_engine_box2d_dynamics_Fixture
 * Method:    getShape
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_getShape
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_box2d_dynamics_Fixture
 * Method:    setSensor
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_setSensor
  (JNIEnv *, jobject, jboolean);

/*
 * Class:     com_wiyun_engine_box2d_dynamics_Fixture
 * Method:    isSensor
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_isSensor
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_box2d_dynamics_Fixture
 * Method:    setFilterData
 * Signature: (Lcom/wiyun/engine/box2d/dynamics/Filter;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_setFilterData
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_wiyun_engine_box2d_dynamics_Fixture
 * Method:    nativeGetFilterData
 * Signature: (Lcom/wiyun/engine/box2d/dynamics/Filter;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_nativeGetFilterData
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_wiyun_engine_box2d_dynamics_Fixture
 * Method:    nativeGetNext
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_nativeGetNext
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_box2d_dynamics_Fixture
 * Method:    nativeRayCast
 * Signature: (Lcom/wiyun/engine/box2d/collision/RayCastOutput;Lcom/wiyun/engine/box2d/collision/RayCastInput;I)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_nativeRayCast
  (JNIEnv *, jobject, jobject, jobject, jint);

/*
 * Class:     com_wiyun_engine_box2d_dynamics_Fixture
 * Method:    nativeGetMassData
 * Signature: (Lcom/wiyun/engine/box2d/collision/MassData;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_nativeGetMassData
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_wiyun_engine_box2d_dynamics_Fixture
 * Method:    setDensity
 * Signature: (F)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_setDensity
  (JNIEnv *, jobject, jfloat);

/*
 * Class:     com_wiyun_engine_box2d_dynamics_Fixture
 * Method:    getDensity
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_getDensity
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_box2d_dynamics_Fixture
 * Method:    getFriction
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_getFriction
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_box2d_dynamics_Fixture
 * Method:    setFriction
 * Signature: (F)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_setFriction
  (JNIEnv *, jobject, jfloat);

/*
 * Class:     com_wiyun_engine_box2d_dynamics_Fixture
 * Method:    getRestitution
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_getRestitution
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_box2d_dynamics_Fixture
 * Method:    setRestitution
 * Signature: (F)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_setRestitution
  (JNIEnv *, jobject, jfloat);

/*
 * Class:     com_wiyun_engine_box2d_dynamics_Fixture
 * Method:    nativeGetAABB
 * Signature: (Lcom/wiyun/engine/box2d/collision/AABB;I)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_nativeGetAABB
  (JNIEnv *, jobject, jobject, jint);

/*
 * Class:     com_wiyun_engine_box2d_dynamics_Fixture
 * Method:    getUserData
 * Signature: ()Ljava/lang/Object;
 */
JNIEXPORT jobject JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_getUserData
  (JNIEnv *, jobject);

/*
 * Class:     com_wiyun_engine_box2d_dynamics_Fixture
 * Method:    setUserData
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_Fixture_setUserData
  (JNIEnv *, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif