#include "jvmtiWrapThreading.h"
#include "jvmtiWrap.h"
#include "jvmtiConverter.h"

/*
 * Class:     me_paolo_jvmti_jvmtiEnv
 * Method:    GetCurrentThread
 * Signature: ()Ljava/lang/Thread;
 */
JNIEXPORT jobject JNICALL Java_me_paolo_jvmti_jvmtiEnv_GetCurrentThread
(JNIEnv* jenv, jclass jklass) {
	jthread thread;
	return jvmti->GetCurrentThread(&thread) ? 
		NULL : thread;
}

/*
 * Class:     me_paolo_jvmti_jvmtiEnv
 * Method:    GetAllThreads
 * Signature: ()[Ljava/lang/Thread;
 */
JNIEXPORT jobjectArray JNICALL Java_me_paolo_jvmti_jvmtiEnv_GetAllThreads
(JNIEnv* jenv, jclass jklass) {
	jthread* threads;
	jint thread_count;
	if (jvmti->GetAllThreads(&thread_count, &threads))
		return NULL;

	jobjectArray arr = jenv->NewObjectArray(thread_count, jenv->FindClass("java/lang/Thread"), NULL);
	for (int i = 0; i < thread_count; i++) jenv->SetObjectArrayElement(arr, i, threads[i]);
	return arr;
}

/*
 * Class:     me_paolo_jvmti_jvmtiEnv
 * Method:    SuspendThread
 * Signature: (Ljava/lang/Thread;)Lme/paolo/jvmti/jvmtiError;
 */
JNIEXPORT jobject JNICALL Java_me_paolo_jvmti_jvmtiEnv_SuspendThread
(JNIEnv* jenv, jclass jklass, jobject thread) {
	jvmtiError err = jvmti->SuspendThread((jthread)thread);
	return converter::to_jerror(jenv, err);
}

/*
 * Class:     me_paolo_jvmti_jvmtiEnv
 * Method:    ResumeThread
 * Signature: (Ljava/lang/Thread;)Lme/paolo/jvmti/jvmtiError;
 */
JNIEXPORT jobject JNICALL Java_me_paolo_jvmti_jvmtiEnv_ResumeThread
(JNIEnv* jenv, jclass jklass, jobject thread) {
	jvmtiError err = jvmti->ResumeThread((jthread)thread);
	return converter::to_jerror(jenv, err);
}

/*
 * Class:     me_paolo_jvmti_jvmtiEnv
 * Method:    StopThread
 * Signature: (Ljava/lang/Thread;Ljava/lang/Exception;)Lme/paolo/jvmti/jvmtiError;
 */
JNIEXPORT jobject JNICALL Java_me_paolo_jvmti_jvmtiEnv_StopThread
(JNIEnv* jenv, jclass jklass, jobject thread, jobject exception) {
	jvmtiError err = jvmti->StopThread((jthread)thread, exception);
	return converter::to_jerror(jenv, err);
}

/*
 * Class:     me_paolo_jvmti_jvmtiEnv
 * Method:    InterruptThread
 * Signature: (Ljava/lang/Thread;)Lme/paolo/jvmti/jvmtiError;
 */
JNIEXPORT jobject JNICALL Java_me_paolo_jvmti_jvmtiEnv_InterruptThread
(JNIEnv* jenv, jclass jklass, jobject thread) {
	jvmtiError err = jvmti->InterruptThread((jthread)thread);
	return converter::to_jerror(jenv, err);
}
