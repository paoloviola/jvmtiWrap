package me.paolo.jvmti;

public class jvmtiCapabilities
{

    public boolean can_tag_objects;
    public boolean can_generate_field_modification_events;
    public boolean can_generate_field_access_events;
    public boolean can_get_bytecodes;
    public boolean can_get_synthetic_attribute;
    public boolean can_get_owned_monitor_info;
    public boolean can_get_current_contended_monitor;
    public boolean can_get_monitor_info;
    public boolean can_pop_frame;
    public boolean can_redefine_classes;
    public boolean can_signal_thread;
    public boolean can_get_source_file_name;
    public boolean can_get_line_numbers;
    public boolean can_get_source_debug_extension;
    public boolean can_access_local_variables;
    public boolean can_maintain_original_method_order;
    public boolean can_generate_single_step_events;
    public boolean can_generate_exception_events;
    public boolean can_generate_frame_pop_events;
    public boolean can_generate_breakpoint_events;
    public boolean can_suspend;
    public boolean can_redefine_any_class;
    public boolean can_get_current_thread_cpu_time;
    public boolean can_get_thread_cpu_time;
    public boolean can_generate_method_entry_events;
    public boolean can_generate_method_exit_events;
    public boolean can_generate_all_class_hook_events;
    public boolean can_generate_compiled_method_load_events;
    public boolean can_generate_monitor_events;
    public boolean can_generate_vm_object_alloc_events;
    public boolean can_generate_native_method_bind_events;
    public boolean can_generate_garbage_collection_events;
    public boolean can_generate_object_free_events;
    public boolean can_force_early_return;
    public boolean can_get_owned_monitor_stack_depth_info;
    public boolean can_get_constant_pool;
    public boolean can_set_native_method_prefix;
    public boolean can_retransform_classes;
    public boolean can_retransform_any_class;
    public boolean can_generate_resource_exhaustion_heap_events;
    public boolean can_generate_resource_exhaustion_threads_events;

    public jvmtiCapabilities() { }

}
