/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_winkelhagen_chess_syzygy_SyzygyBridge */

#ifndef _Included_com_winkelhagen_chess_syzygy_SyzygyBridge
#define _Included_com_winkelhagen_chess_syzygy_SyzygyBridge
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_winkelhagen_chess_syzygy_SyzygyBridge
 * Method:    init
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_winkelhagen_chess_syzygy_SyzygyBridge_init
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_winkelhagen_chess_syzygy_SyzygyBridge
 * Method:    getTBLargest
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_winkelhagen_chess_syzygy_SyzygyBridge_getTBLargest
  (JNIEnv *, jclass);

/*
 * Class:     com_winkelhagen_chess_syzygy_SyzygyBridge
 * Method:    probeWDL
 * Signature: (JJJJJJJJIZ)I
 */
JNIEXPORT jint JNICALL Java_com_winkelhagen_chess_syzygy_SyzygyBridge_probeWDL
  (JNIEnv *, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jint, jboolean);

/*
 * Class:     com_winkelhagen_chess_syzygy_SyzygyBridge
 * Method:    probeDTZ
 * Signature: (JJJJJJJJIIZ)I
 */
JNIEXPORT jint JNICALL Java_com_winkelhagen_chess_syzygy_SyzygyBridge_probeDTZ
  (JNIEnv *, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jint, jint, jboolean);

#ifdef __cplusplus
}
#endif
#endif
