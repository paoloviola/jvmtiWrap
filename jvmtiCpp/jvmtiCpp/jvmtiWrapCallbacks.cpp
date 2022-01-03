#include "jvmtiWrap.h"
#include "jvmtiWrapCallbacks.h"
#include "jvmtiConverter.h"

jobject oVMInit;
void JNICALL VMInit(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env,
	jthread thread) {
	static bool lock = false;
	if (!oVMInit || lock) return;

	lock = true;
	jclass klass = jni_env->GetObjectClass(oVMInit);
	jmethodID method = jni_env->GetMethodID(klass, "VMInit", "(Ljava/lang/Thread;)V");
	jni_env->CallVoidMethod(oVMInit, method, thread);
	lock = false;
}

jobject oVMDeath;
void JNICALL VMDeath(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env) {
	static bool lock = false;
	if (!oVMDeath || lock) return;

	lock = true;
	jclass klass = jni_env->GetObjectClass(oVMDeath);
	jmethodID method = jni_env->GetMethodID(klass, "VMDeath", "()V");
	jni_env->CallVoidMethod(oVMDeath, method);
	lock = false;
}

jobject oThreadStart;
void JNICALL ThreadStart(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env,
	jthread thread) {
	static bool lock = false;
	if (!oThreadStart || lock) return;

	lock = true;
	jclass klass = jni_env->GetObjectClass(oThreadStart);
	jmethodID method = jni_env->GetMethodID(klass, "ThreadStart", "(Ljava/lang/Thread;)V");
	jni_env->CallVoidMethod(oThreadStart, method, thread);
	lock = false;
}

jobject oThreadEnd;
void JNICALL ThreadEnd(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env,
	jthread thread) {
	static bool lock = false;
	if (!oThreadEnd || lock) return;

	lock = true;
	jclass klass = jni_env->GetObjectClass(oThreadEnd);
	jmethodID method = jni_env->GetMethodID(klass, "ThreadEnd", "(Ljava/lang/Thread;)V");
	jni_env->CallVoidMethod(oThreadEnd, method, thread);
	lock = false;
}

jobject oClassFileLoadHook;
void JNICALL ClassFileLoadHook(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env,
	jclass class_being_redefined,
	jobject loader,
	const char* name,
	jobject protection_domain,
	jint class_data_len,
	const unsigned char* class_data,
	jint* new_class_data_len,
	unsigned char** new_class_data) {
	static bool lock = false;
	if (!oClassFileLoadHook || lock) return;

	lock = true;
	jclass klass = jni_env->GetObjectClass(oClassFileLoadHook);
	jmethodID method = jni_env->GetMethodID(klass, "ClassFileLoadHook", "(Ljava/lang/Class;Ljava/lang/ClassLoader;Ljava/lang/String;Ljava/security/ProtectionDomain;[B)[B");
	
	jbyteArray input = jni_env->NewByteArray(class_data_len);
	jni_env->SetByteArrayRegion(input, 0, class_data_len, (jbyte*)class_data);
	jbyteArray output = (jbyteArray)jni_env->CallObjectMethod(oClassFileLoadHook, method, 
		class_being_redefined, loader, jni_env->NewStringUTF(name), protection_domain, input);
	
	if (output) {
		*new_class_data_len = jni_env->GetArrayLength(output);
		*new_class_data = (unsigned char*)jni_env->GetByteArrayElements(output, 0);
	}
	lock = false;
}

jobject oClassLoad;
void JNICALL ClassLoad(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env,
	jthread thread,
	jclass klass) {
	static bool lock = false;
	if (!oClassLoad || lock) return;

	lock = true;
	jclass klass0 = jni_env->GetObjectClass(oClassLoad);
	jmethodID method0 = jni_env->GetMethodID(klass0, "ClassLoad", "(Ljava/lang/Thread;Ljava/lang/Class;)V");
	jni_env->CallVoidMethod(oClassLoad, method0, thread, klass);
	lock = false;
}

jobject oClassPrepare;
void JNICALL ClassPrepare(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env,
	jthread thread,
	jclass klass) {
	static bool lock = false;
	if (!oClassPrepare || lock) return;

	lock = true;
	jclass klass0 = jni_env->GetObjectClass(oClassPrepare);
	jmethodID method0 = jni_env->GetMethodID(klass0, "ClassPrepare", "(Ljava/lang/Thread;Ljava/lang/Class;)V");
	jni_env->CallVoidMethod(oClassPrepare, method0, thread, klass);
	lock = false;
}

jobject oVMStart;
void JNICALL VMStart(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env) {
	static bool lock = false;
	if (!oVMStart || lock) return;

	lock = true;
	jclass klass = jni_env->GetObjectClass(oVMStart);
	jmethodID method = jni_env->GetMethodID(klass, "VMStart", "()V");
	jni_env->CallVoidMethod(oVMStart, method);
	lock = false;
}

jobject oException;
void JNICALL Exception(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env,
	jthread thread,
	jmethodID method,
	jlocation location,
	jobject exception,
	jmethodID catch_method,
	jlocation catch_location) {
	static bool lock = false;
	if (!oException || lock) return;

	lock = true;
	jclass klass0 = jni_env->GetObjectClass(oException);
	jmethodID method0 = jni_env->GetMethodID(klass0, "Exception", "(Ljava/lang/Thread;JJLjava/lang/Throwable;JJ)V");
	jni_env->CallVoidMethod(oException, method0, 
		thread, method, location, exception, catch_method, catch_location);
	lock = false;
}

jobject oExceptionCatch;
void JNICALL ExceptionCatch(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env,
	jthread thread,
	jmethodID method,
	jlocation location,
	jobject exception) {
	static bool lock = false;
	if (!oExceptionCatch || lock) return;

	lock = true;
	jclass klass0 = jni_env->GetObjectClass(oExceptionCatch);
	jmethodID method0 = jni_env->GetMethodID(klass0, "ExceptionCatch", "(Ljava/lang/Thread;JJLjava/lang/Throwable;)V");
	jni_env->CallVoidMethod(oExceptionCatch, method0,
		thread, method, location, exception);
	lock = false;
}

jobject oSingleStep;
void JNICALL SingleStep(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env,
	jthread thread,
	jmethodID method,
	jlocation location) {
	static bool lock = false;
	if (!oSingleStep || lock) return;

	lock = true;
	jclass klass0 = jni_env->GetObjectClass(oSingleStep);
	jmethodID method0 = jni_env->GetMethodID(klass0, "SingleStep", "(Ljava/lang/Thread;JJ)V");
	jni_env->CallVoidMethod(oSingleStep, method0,
		thread, method, location);
	lock = false;
}

jobject oFramePop;
void JNICALL FramePop(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env,
	jthread thread,
	jmethodID method,
	jboolean was_popped_by_exception) {
	static bool lock = false;
	if (!oFramePop || lock) return;

	lock = true;
	jclass klass0 = jni_env->GetObjectClass(oFramePop);
	jmethodID method0 = jni_env->GetMethodID(klass0, "FramePop", "(Ljava/lang/Thread;JZ)V");
	jni_env->CallVoidMethod(oFramePop, method0,
		thread, method, was_popped_by_exception);
	lock = false;
}

jobject oBreakpoint;
void JNICALL Breakpoint(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env,
	jthread thread,
	jmethodID method,
	jlocation location) {
	static bool lock = false;
	if (!oBreakpoint || lock) return;

	lock = true;
	jclass klass0 = jni_env->GetObjectClass(oBreakpoint);
	jmethodID method0 = jni_env->GetMethodID(klass0, "Breakpoint", "(Ljava/lang/Thread;JJ)V");
	jni_env->CallVoidMethod(oBreakpoint, method0,
		thread, method, location);
	lock = false;
}

jobject oFieldAccess;
void JNICALL FieldAccess(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env,
	jthread thread,
	jmethodID method,
	jlocation location,
	jclass field_klass,
	jobject object,
	jfieldID field) {
	static bool lock = false;
	if (!oFieldAccess || lock) return;

	lock = true;
	jclass klass0 = jni_env->GetObjectClass(oFieldAccess);
	jmethodID method0 = jni_env->GetMethodID(klass0, "FieldAccess", "(Ljava/lang/Thread;JJLjava/lang/Class;Ljava/lang/Object;J)V");
	jni_env->CallVoidMethod(oFieldAccess, method0,
		thread, method, location, field_klass, object, field);
	lock = false;
}

jobject oFieldModification;
void JNICALL FieldModification(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env,
	jthread thread,
	jmethodID method,
	jlocation location,
	jclass field_klass,
	jobject object,
	jfieldID field,
	char signature_type,
	jvalue new_value) {
	static bool lock = false;
	if (!oFieldModification || lock) return;

	lock = true;
	jclass klass0 = jni_env->GetObjectClass(oFieldModification);
	jmethodID method0 = jni_env->GetMethodID(klass0, "FieldModification", "(Ljava/lang/Thread;JJLjava/lang/Class;Ljava/lang/Object;JCLjava/lang/Object;)V");
	jni_env->CallVoidMethod(oFieldModification, method0, // TODO: Add new_value
		thread, method, location, field_klass, object, field, signature_type, NULL);
	lock = false;
}

jobject oMethodEntry;
void JNICALL MethodEntry(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env,
	jthread thread,
	jmethodID method) {
	static bool lock = false;
	if (!oMethodEntry || lock) return;

	lock = true;
	jclass klass0 = jni_env->GetObjectClass(oMethodEntry);
	jmethodID method0 = jni_env->GetMethodID(klass0, "MethodEntry", "(Ljava/lang/Thread;J)V");
	jni_env->CallVoidMethod(oMethodEntry, method0, thread, method);
	lock = false;
}

jobject oMethodExit;
void JNICALL MethodExit(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env,
	jthread thread,
	jmethodID method,
	jboolean was_popped_by_exception,
	jvalue return_value) {
	static bool lock = false;
	if (!oMethodExit || lock) return;

	lock = true;
	jclass klass0 = jni_env->GetObjectClass(oMethodExit);
	jmethodID method0 = jni_env->GetMethodID(klass0, "MethodExit", "(Ljava/lang/Thread;JZLjava/lang/Object;)V");
	jni_env->CallVoidMethod(oMethodExit, method0, // TODO: Add return value
		thread, method, was_popped_by_exception, NULL);
	lock = false;
}

/* ... */

jobject oMonitorWait;
void JNICALL MonitorWait(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env,
	jthread thread,
	jobject object,
	jlong timeout) {
	static bool lock = false;
	if (!oMonitorWait || lock) return;

	lock = true;
	jclass klass = jni_env->GetObjectClass(oMonitorWait);
	jmethodID method = jni_env->GetMethodID(klass, "MonitorWait", "(Ljava/lang/Thread;Ljava/lang/Object;J)V");
	jni_env->CallVoidMethod(oMonitorWait, method, thread, object, timeout);
	lock = false;
}

jobject oMonitorWaited;
void JNICALL MonitorWaited(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env,
	jthread thread,
	jobject object,
	jboolean timed_out) {
	static bool lock = false;
	if (!oMonitorWaited || lock) return;

	lock = true;
	jclass klass = jni_env->GetObjectClass(oMonitorWaited);
	jmethodID method = jni_env->GetMethodID(klass, "MonitorWaited", "(Ljava/lang/Thread;Ljava/lang/Object;Z)V");
	jni_env->CallVoidMethod(oMonitorWaited, method, thread, object, timed_out);
	lock = false;
}

jobject oMonitorContendedEnter;
void JNICALL MonitorContendedEnter(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env,
	jthread thread,
	jobject object) {
	static bool lock = false;
	if (!oMonitorContendedEnter || lock) return;

	lock = true;
	jclass klass = jni_env->GetObjectClass(oMonitorContendedEnter);
	jmethodID method = jni_env->GetMethodID(klass, "MonitorContendedEnter", "(Ljava/lang/Thread;Ljava/lang/Object;)V");
	jni_env->CallVoidMethod(oMonitorContendedEnter, method, thread, object);
	lock = false;
}

jobject oMonitorContendedEntered;
void JNICALL MonitorContendedEntered(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env,
	jthread thread,
	jobject object) {
	static bool lock = false;
	if (!oMonitorContendedEntered || lock) return;

	lock = true;
	jclass klass = jni_env->GetObjectClass(oMonitorContendedEntered);
	jmethodID method = jni_env->GetMethodID(klass, "MonitorContendedEntered", "(Ljava/lang/Thread;Ljava/lang/Object;)V");
	jni_env->CallVoidMethod(oMonitorContendedEntered, method, thread, object);
	lock = false;
}

/* ... */

jobject oVMObjectAlloc;
void JNICALL VMObjectAlloc(
	jvmtiEnv* jvmti_env,
	JNIEnv* jni_env,
	jthread thread,
	jobject object,
	jclass object_klass,
	jlong size) {
	static bool lock = false;
	if (!oVMObjectAlloc || lock) return;

	lock = true;
	jclass klass = jni_env->GetObjectClass(oVMObjectAlloc);
	jmethodID method = jni_env->GetMethodID(klass, "VMObjectAlloc", "(Ljava/lang/Thread;Ljava/lang/Object;Ljava/lang/Class;J)V");
	jni_env->CallVoidMethod(oVMObjectAlloc, method, thread, object, object_klass, size);
	lock = false;
}

/*
 * Class:     me_paolo_jvmti_jvmtiEnv
 * Method:    SetEventCallbacks
 * Signature: (Lme/paolo/jvmti/event/jvmtiEventCallbacks;)Lme/paolo/jvmti/jvmtiError;
 */
JNIEXPORT jobject JNICALL Java_me_paolo_jvmti_jvmtiEnv_SetEventCallbacks
(JNIEnv* jenv, jclass jklass, jobject event_callbacks) {
	jclass klass = jenv->FindClass("me/paolo/jvmti/event/jvmtiEventCallbacks");

	jvmtiEventCallbacks callbacks;
	{
		jobject obj;
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "VMInit", "Lme/paolo/jvmti/event/callbacks/jvmtiEventVMInit;"))) {
			oVMInit = jenv->NewGlobalRef(obj);
			callbacks.VMInit = VMInit;
		}
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "VMDeath", "Lme/paolo/jvmti/event/callbacks/jvmtiEventVMDeath;"))) {
			oVMDeath = jenv->NewGlobalRef(obj);
			callbacks.VMDeath = VMDeath;
		}
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "ThreadStart", "Lme/paolo/jvmti/event/callbacks/jvmtiEventThreadStart;"))) {
			oThreadStart = jenv->NewGlobalRef(obj);
			callbacks.ThreadStart = ThreadStart;
		}
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "ThreadEnd", "Lme/paolo/jvmti/event/callbacks/jvmtiEventThreadEnd;"))) {
			oThreadEnd = jenv->NewGlobalRef(obj);
			callbacks.ThreadEnd = ThreadEnd;
		}
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "ClassFileLoadHook", "Lme/paolo/jvmti/event/callbacks/jvmtiEventClassFileLoadHook;"))) {
			oClassFileLoadHook = jenv->NewGlobalRef(obj);
			callbacks.ClassFileLoadHook = ClassFileLoadHook;
		}
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "ClassLoad", "Lme/paolo/jvmti/event/callbacks/jvmtiEventClassLoad;"))) {
			oClassLoad = jenv->NewGlobalRef(obj);
			callbacks.ClassLoad = ClassLoad;
		}
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "ClassPrepare", "Lme/paolo/jvmti/event/callbacks/jvmtiEventClassPrepare;"))) {
			oClassPrepare = jenv->NewGlobalRef(obj);
			callbacks.ClassPrepare = ClassPrepare;
		}
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "VMStart", "Lme/paolo/jvmti/event/callbacks/jvmtiEventVMStart;"))) {
			oVMStart = jenv->NewGlobalRef(obj);
			callbacks.VMStart = VMStart;
		}
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "Exception", "Lme/paolo/jvmti/event/callbacks/jvmtiEventException;"))) {
			oException = jenv->NewGlobalRef(obj);
			callbacks.Exception = Exception;
		}
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "ExceptionCatch", "Lme/paolo/jvmti/event/callbacks/jvmtiEventExceptionCatch;"))) {
			oExceptionCatch = jenv->NewGlobalRef(obj);
			callbacks.ExceptionCatch = ExceptionCatch;
		}
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "SingleStep", "Lme/paolo/jvmti/event/callbacks/jvmtiEventSingleStep;"))) {
			oSingleStep = jenv->NewGlobalRef(obj);
			callbacks.SingleStep = SingleStep;
		}
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "FramePop", "Lme/paolo/jvmti/event/callbacks/jvmtiEventFramePop;"))) {
			oFramePop = jenv->NewGlobalRef(obj);
			callbacks.FramePop = FramePop;
		}
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "Breakpoint", "Lme/paolo/jvmti/event/callbacks/jvmtiEventBreakpoint;"))) {
			oBreakpoint = jenv->NewGlobalRef(obj);
			callbacks.Breakpoint = Breakpoint;
		}
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "FieldAccess", "Lme/paolo/jvmti/event/callbacks/jvmtiEventFieldAccess;"))) {
			oFieldAccess = jenv->NewGlobalRef(obj);
			callbacks.FieldAccess = FieldAccess;
		}
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "FieldModification", "Lme/paolo/jvmti/event/callbacks/jvmtiEventFieldModification;"))) {
			oFieldModification = jenv->NewGlobalRef(obj);
			callbacks.FieldModification = FieldModification;
		}
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "MethodEntry", "Lme/paolo/jvmti/event/callbacks/jvmtiEventMethodEntry;"))) {
			oMethodEntry = jenv->NewGlobalRef(obj);
			callbacks.MethodEntry = MethodEntry;
		}
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "MethodExit", "Lme/paolo/jvmti/event/callbacks/jvmtiEventMethodExit;"))) {
			oMethodExit = jenv->NewGlobalRef(obj);
			callbacks.MethodExit = MethodExit;
		}
		/* ... */
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "MonitorWait", "Lme/paolo/jvmti/event/callbacks/jvmtiEventMonitorWait;"))) {
			oMonitorWait = jenv->NewGlobalRef(obj);
			callbacks.MonitorWait = MonitorWait;
		}
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "MonitorWaited", "Lme/paolo/jvmti/event/callbacks/jvmtiEventMonitorWaited;"))) {
			oMonitorWaited = jenv->NewGlobalRef(obj);
			callbacks.MonitorWaited = MonitorWaited;
		}
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "MonitorContendedEnter", "Lme/paolo/jvmti/event/callbacks/jvmtiEventMonitorContendedEnter;"))) {
			oMonitorContendedEnter = jenv->NewGlobalRef(obj);
			callbacks.MonitorContendedEnter = MonitorContendedEnter;
		}
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "MonitorContendedEntered", "Lme/paolo/jvmti/event/callbacks/jvmtiEventMonitorContendedEntered;"))) {
			oMonitorContendedEntered = jenv->NewGlobalRef(obj);
			callbacks.MonitorContendedEntered = MonitorContendedEntered;
		}
		/* ... */
		if (obj = jenv->GetObjectField(event_callbacks, jenv->GetFieldID(klass, "VMObjectAlloc", "Lme/paolo/jvmti/event/callbacks/jvmtiEventVMObjectAlloc;"))) {
			oVMObjectAlloc = jenv->NewGlobalRef(obj);
			callbacks.VMObjectAlloc = VMObjectAlloc;
		}
	}
	jvmtiError err = jvmti->SetEventCallbacks(&callbacks, sizeof(jvmtiEventCallbacks));
	return converter::to_jerror(jenv, err);
}

/*
 * Class:     me_paolo_jvmti_jvmtiEnv
 * Method:    SetEventNotificationMode
 * Signature: (Lme/paolo/jvmti/event/jvmtiEventMode;Lme/paolo/jvmti/event/jvmtiEvent;Ljava/lang/Thread;)Lme/paolo/jvmti/jvmtiError;
 */
JNIEXPORT jobject JNICALL Java_me_paolo_jvmti_jvmtiEnv_SetEventNotificationMode
(JNIEnv* jenv, jclass jklass, jobject mode, jobject type, jobject thread) {
	jint jmode = jenv->GetIntField(mode, jenv->GetFieldID(jenv->FindClass("me/paolo/jvmti/event/jvmtiEventMode"), "id", "I"));
	jint jtype = jenv->GetIntField(type, jenv->GetFieldID(jenv->FindClass("me/paolo/jvmti/event/jvmtiEvent"), "id", "I"));
	jvmtiError err = jvmti->SetEventNotificationMode((jvmtiEventMode)jmode, (jvmtiEvent)jtype, (jthread)thread);
	return converter::to_jerror(jenv, err);
}
