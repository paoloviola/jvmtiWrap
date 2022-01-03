package me.paolo.jvmti.event.callbacks;

public interface jvmtiEventVMInit extends jvmtiEventCallback
{
    void VMInit(Thread thread);
}
