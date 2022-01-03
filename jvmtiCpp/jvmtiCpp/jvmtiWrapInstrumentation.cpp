#include "jvmtiWrap.h"
#include "jvmtiWrapInstrumentation.h"
#include "jvmtiConverter.h"

/*
 * Class:     me_paolo_jvmti_jvmtiEnv
 * Method:    GetLoadedClasses
 * Signature: ()[Ljava/lang/Class;
 */
JNIEXPORT jobjectArray JNICALL Java_me_paolo_jvmti_jvmtiEnv_GetLoadedClasses
(JNIEnv* jenv, jclass jklass) {
	jclass* classes;
	jint class_count;
	if (jvmti->GetLoadedClasses(&class_count, &classes))
		return NULL;

	jobjectArray arr = jenv->NewObjectArray(class_count, jenv->FindClass("java/lang/Class"), NULL);
	for (int i = 0; i < class_count; i++) jenv->SetObjectArrayElement(arr, i, classes[i]);
	return arr;
}

/*
 * Class:     me_paolo_jvmti_jvmtiEnv
 * Method:    GetClassLoaderClasses
 * Signature: (Ljava/lang/ClassLoader;)[Ljava/lang/Class;
 */
JNIEXPORT jobjectArray JNICALL Java_me_paolo_jvmti_jvmtiEnv_GetClassLoaderClasses
(JNIEnv* jenv, jclass jklass, jobject class_loader) {
	jclass* classes;
	jint class_count;
	if (jvmti->GetClassLoaderClasses(class_loader, &class_count, &classes))
		return NULL;

	jobjectArray arr = jenv->NewObjectArray(class_count, jenv->FindClass("java/lang/Class"), NULL);
	for (int i = 0; i < class_count; i++) jenv->SetObjectArrayElement(arr, i, classes[i]);
	return arr;
}

/*
 * Class:     me_paolo_jvmti_jvmtiEnv
 * Method:    RetransformClasses
 * Signature: ([Ljava/lang/Class;)Lme/paolo/jvmti/jvmtiError;
 */
JNIEXPORT jobject JNICALL Java_me_paolo_jvmti_jvmtiEnv_RetransformClasses
(JNIEnv* jenv, jclass jklass, jobjectArray jklasses) {
	jint class_count = jenv->GetArrayLength(jklasses);

	jclass* classes = new jclass[class_count];
	for (int i = 0; i < class_count; i++)
		classes[i] = (jclass)jenv->GetObjectArrayElement(jklasses, i);
	jvmtiError err = jvmti->RetransformClasses(class_count, classes);
	delete[] classes;

	return converter::to_jerror(jenv, err);
}

/*
 * Class:     me_paolo_jvmti_jvmtiEnv
 * Method:    RedefineClasses
 * Signature: ([Lme/paolo/jvmti/jvmtiClassDefinition;)Lme/paolo/jvmti/jvmtiError;
 */
JNIEXPORT jobject JNICALL Java_me_paolo_jvmti_jvmtiEnv_RedefineClasses
(JNIEnv* jenv, jclass jklass, jobjectArray jclass_definitions) {
	jint class_count = jenv->GetArrayLength(jclass_definitions);

	jvmtiClassDefinition* class_definitions = new jvmtiClassDefinition[class_count];
	for (int i = 0; i < class_count; i++) {
		jobject elem = jenv->GetObjectArrayElement(jclass_definitions, i);
		class_definitions[i] = converter::to_classdef(jenv, elem);
	}
	jvmtiError err = jvmti->RedefineClasses(class_count, class_definitions);
	delete[] class_definitions;

	return converter::to_jerror(jenv, err);
}
