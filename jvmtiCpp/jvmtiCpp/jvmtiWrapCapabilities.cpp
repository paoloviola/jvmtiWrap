#include "jvmtiWrapCapabilities.h"
#include "jvmtiWrap.h"
#include "jvmtiConverter.h"

/*
 * Class:     me_paolo_jvmti_jvmtiEnv
 * Method:    AddCapabilities
 * Signature: (Lme/paolo/jvmti/jvmtiCapabilities;)Lme/paolo/jvmti/jvmtiError;
 */
JNIEXPORT jobject JNICALL Java_me_paolo_jvmti_jvmtiEnv_AddCapabilities
(JNIEnv* jenv, jclass jklass, jobject capabilities) {
	jvmtiCapabilities capab = converter::to_capab(jenv, capabilities);
	jvmtiError err = jvmti->AddCapabilities(&capab);
	return converter::to_jerror(jenv, err);
}

/*
 * Class:     me_paolo_jvmti_jvmtiEnv
 * Method:    RelinquishCapabilities
 * Signature: (Lme/paolo/jvmti/jvmtiCapabilities;)Lme/paolo/jvmti/jvmtiError;
 */
JNIEXPORT jobject JNICALL Java_me_paolo_jvmti_jvmtiEnv_RelinquishCapabilities
(JNIEnv* jenv, jclass jklass, jobject capabilities) {
	jvmtiCapabilities capab = converter::to_capab(jenv, capabilities);
	jvmtiError err = jvmti->RelinquishCapabilities(&capab);
	return converter::to_jerror(jenv, err);
}

/*
 * Class:     me_paolo_jvmti_jvmtiEnv
 * Method:    GetCapabilities
 * Signature: ()Lme/paolo/jvmti/jvmtiCapabilities;
 */
JNIEXPORT jobject JNICALL Java_me_paolo_jvmti_jvmtiEnv_GetCapabilities
(JNIEnv* jenv, jclass jklass) {
	jvmtiCapabilities capab;
	return jvmti->GetCapabilities(&capab) ? 
		NULL : converter::to_jcapab(jenv, capab);
}