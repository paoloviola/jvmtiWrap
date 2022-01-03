package me.paolo.jvmti.event.callbacks;

public interface jvmtiEventThreadStart extends jvmtiEventCallback
{
    void ThreadStart(Thread thread);
}
