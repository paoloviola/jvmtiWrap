#include "jvmtiConverter.h"

jvmtiClassDefinition converter::to_classdef
(JNIEnv* jenv, jobject& jclass_definition)
{
	jclass klass = jenv->FindClass("me/paolo/jvmti/jvmtiClassDefinition");
	jbyteArray arr = (jbyteArray)jenv->GetObjectField(jclass_definition, jenv->GetFieldID(klass, "data", "[B"));

	jvmtiClassDefinition class_def;
	class_def.klass = (jclass)jenv->GetObjectField(jclass_definition, jenv->GetFieldID(klass, "target", "Ljava/lang/Class;"));
	class_def.class_byte_count = jenv->GetArrayLength(arr);
	class_def.class_bytes = (unsigned char*)jenv->GetByteArrayElements(arr, NULL);
	return class_def;
}

jobject converter::to_jcapab
(JNIEnv* jenv, jvmtiCapabilities& capabilities)
{
	jclass klass = jenv->FindClass("me/paolo/jvmti/jvmtiCapabilities");
	jobject object = jenv->NewObject(klass, jenv->GetMethodID(klass, "<init>", "()V"));
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_tag_objects", "Z"), capabilities.can_tag_objects);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_generate_field_modification_events", "Z"), capabilities.can_generate_field_modification_events);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_generate_field_access_events", "Z"), capabilities.can_generate_field_access_events);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_get_bytecodes", "Z"), capabilities.can_get_bytecodes);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_get_synthetic_attribute", "Z"), capabilities.can_get_synthetic_attribute);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_get_owned_monitor_info", "Z"), capabilities.can_get_owned_monitor_info);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_get_current_contended_monitor", "Z"), capabilities.can_get_current_contended_monitor);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_get_monitor_info", "Z"), capabilities.can_get_monitor_info);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_pop_frame", "Z"), capabilities.can_pop_frame);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_redefine_classes", "Z"), capabilities.can_redefine_classes);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_signal_thread", "Z"), capabilities.can_signal_thread);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_get_source_file_name", "Z"), capabilities.can_get_source_file_name);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_get_line_numbers", "Z"), capabilities.can_get_line_numbers);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_get_source_debug_extension", "Z"), capabilities.can_get_source_debug_extension);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_access_local_variables", "Z"), capabilities.can_access_local_variables);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_maintain_original_method_order", "Z"), capabilities.can_maintain_original_method_order);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_generate_single_step_events", "Z"), capabilities.can_generate_single_step_events);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_generate_exception_events", "Z"), capabilities.can_generate_exception_events);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_generate_frame_pop_events", "Z"), capabilities.can_generate_frame_pop_events);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_generate_breakpoint_events", "Z"), capabilities.can_generate_breakpoint_events);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_suspend", "Z"), capabilities.can_suspend);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_redefine_any_class", "Z"), capabilities.can_redefine_any_class);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_get_current_thread_cpu_time", "Z"), capabilities.can_get_current_thread_cpu_time);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_get_thread_cpu_time", "Z"), capabilities.can_get_thread_cpu_time);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_generate_method_entry_events", "Z"), capabilities.can_generate_method_entry_events);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_generate_method_exit_events", "Z"), capabilities.can_generate_method_exit_events);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_generate_all_class_hook_events", "Z"), capabilities.can_generate_all_class_hook_events);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_generate_compiled_method_load_events", "Z"), capabilities.can_generate_compiled_method_load_events);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_generate_monitor_events", "Z"), capabilities.can_generate_monitor_events);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_generate_vm_object_alloc_events", "Z"), capabilities.can_generate_vm_object_alloc_events);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_generate_native_method_bind_events", "Z"), capabilities.can_generate_native_method_bind_events);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_generate_garbage_collection_events", "Z"), capabilities.can_generate_garbage_collection_events);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_generate_object_free_events", "Z"), capabilities.can_generate_object_free_events);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_force_early_return", "Z"), capabilities.can_force_early_return);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_get_owned_monitor_stack_depth_info", "Z"), capabilities.can_get_owned_monitor_stack_depth_info);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_get_constant_pool", "Z"), capabilities.can_get_constant_pool);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_set_native_method_prefix", "Z"), capabilities.can_set_native_method_prefix);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_retransform_classes", "Z"), capabilities.can_retransform_classes);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_retransform_any_class", "Z"), capabilities.can_retransform_any_class);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_generate_resource_exhaustion_heap_events", "Z"), capabilities.can_generate_resource_exhaustion_heap_events);
	jenv->SetBooleanField(object, jenv->GetFieldID(klass, "can_generate_resource_exhaustion_threads_events", "Z"), capabilities.can_generate_resource_exhaustion_threads_events);
	return object;
}

jvmtiCapabilities converter::to_capab
(JNIEnv* jenv, jobject& capabilities) {
	jvmtiCapabilities capab;
	jclass klass = jenv->FindClass("me/paolo/jvmti/jvmtiCapabilities");
	capab.can_tag_objects = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_tag_objects", "Z"));
	capab.can_generate_field_modification_events = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_generate_field_modification_events", "Z"));
	capab.can_generate_field_access_events = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_generate_field_access_events", "Z"));
	capab.can_get_bytecodes = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_get_bytecodes", "Z"));
	capab.can_get_synthetic_attribute = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_get_synthetic_attribute", "Z"));
	capab.can_get_owned_monitor_info = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_get_owned_monitor_info", "Z"));
	capab.can_get_current_contended_monitor = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_get_current_contended_monitor", "Z"));
	capab.can_get_monitor_info = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_get_monitor_info", "Z"));
	capab.can_pop_frame = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_pop_frame", "Z"));
	capab.can_redefine_classes = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_redefine_classes", "Z"));
	capab.can_signal_thread = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_signal_thread", "Z"));
	capab.can_get_source_file_name = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_get_source_file_name", "Z"));
	capab.can_get_line_numbers = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_get_line_numbers", "Z"));
	capab.can_get_source_debug_extension = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_get_source_debug_extension", "Z"));
	capab.can_access_local_variables = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_access_local_variables", "Z"));
	capab.can_maintain_original_method_order = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_maintain_original_method_order", "Z"));
	capab.can_generate_single_step_events = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_generate_single_step_events", "Z"));
	capab.can_generate_exception_events = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_generate_exception_events", "Z"));
	capab.can_generate_frame_pop_events = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_generate_frame_pop_events", "Z"));
	capab.can_generate_breakpoint_events = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_generate_breakpoint_events", "Z"));
	capab.can_suspend = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_suspend", "Z"));
	capab.can_redefine_any_class = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_redefine_any_class", "Z"));
	capab.can_get_current_thread_cpu_time = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_get_current_thread_cpu_time", "Z"));
	capab.can_get_thread_cpu_time = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_get_thread_cpu_time", "Z"));
	capab.can_generate_method_entry_events = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_generate_method_entry_events", "Z"));
	capab.can_generate_method_exit_events = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_generate_method_exit_events", "Z"));
	capab.can_generate_all_class_hook_events = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_generate_all_class_hook_events", "Z"));
	capab.can_generate_compiled_method_load_events = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_generate_compiled_method_load_events", "Z"));
	capab.can_generate_monitor_events = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_generate_monitor_events", "Z"));
	capab.can_generate_vm_object_alloc_events = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_generate_vm_object_alloc_events", "Z"));
	capab.can_generate_native_method_bind_events = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_generate_native_method_bind_events", "Z"));
	capab.can_generate_garbage_collection_events = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_generate_garbage_collection_events", "Z"));
	capab.can_generate_object_free_events = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_generate_object_free_events", "Z"));
	capab.can_force_early_return = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_force_early_return", "Z"));
	capab.can_get_owned_monitor_stack_depth_info = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_get_owned_monitor_stack_depth_info", "Z"));
	capab.can_get_constant_pool = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_get_constant_pool", "Z"));
	capab.can_set_native_method_prefix = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_set_native_method_prefix", "Z"));
	capab.can_retransform_classes = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_retransform_classes", "Z"));
	capab.can_retransform_any_class = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_retransform_any_class", "Z"));
	capab.can_generate_resource_exhaustion_heap_events = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_generate_resource_exhaustion_heap_events", "Z"));
	capab.can_generate_resource_exhaustion_threads_events = jenv->GetBooleanField(capabilities, jenv->GetFieldID(klass, "can_generate_resource_exhaustion_threads_events", "Z"));
	return capab;
}

jobject converter::to_jerror
(JNIEnv* jenv, jvmtiError& error) {
	jclass klass = jenv->FindClass("me/paolo/jvmti/jvmtiError");
	jmethodID method = jenv->GetStaticMethodID(klass, "getById", "(I)Lme/paolo/jvmti/jvmtiError;");
	return jenv->CallStaticObjectMethod(klass, method, (jint)error);
}
