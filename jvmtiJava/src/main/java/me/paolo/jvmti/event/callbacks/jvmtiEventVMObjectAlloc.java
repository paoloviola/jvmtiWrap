package me.paolo.jvmti.event.callbacks;

public interface jvmtiEventVMObjectAlloc extends jvmtiEventCallback
{
    void VMObjectAlloc(
            Thread thread,
            Object object,
            Class<?> object_klass,
            long size
    );
}
