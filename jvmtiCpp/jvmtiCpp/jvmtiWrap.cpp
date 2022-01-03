#include "jvmtiWrap.h"

jvmtiEnv* jvmti;

JNIEXPORT jint JNICALL JNI_OnLoad
(JavaVM* jvm, void* reserved)
{
	return jvm->GetEnv((void**)&jvmti, JVMTI_VERSION_1_0) == JNI_OK ?
		JNI_VERSION_1_1 : JNI_EVERSION;
}