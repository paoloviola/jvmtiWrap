#pragma once
#include <jni.h>
#include <jvmti.h>

namespace converter {

	/// <summary>
	/// Converts object of Lme/paolo/jvmti/jvmtiClassDefinition; to an actual jvmtiClassDefinition struct
	/// </summary>
	jvmtiClassDefinition to_classdef
	(JNIEnv* jenv, jobject& jclass_definition);

	/// <summary>
	/// Converts a jvmtiCapabilities struct to an Lme/paolo/jvmti/jvmtiCapabilities; object
	/// </summary>
	jobject to_jcapab
	(JNIEnv* jenv, jvmtiCapabilities& capabilities);

	/// <summary>
	/// Converts a Lme/paolo/jvmti/jvmtiCapabilities; object to a jvmtiCapabilities struct
	/// </summary>
	jvmtiCapabilities to_capab
	(JNIEnv* jenv, jobject& capabilities);

	/// <summary>
	/// Converts an jvmtiError enum into an Lme/paolo/jvmti/jvmtiError; enum
	/// </summary>
	jobject to_jerror
	(JNIEnv* jenv, jvmtiError& error);

};
