package me.paolo.jvmti.event.callbacks;

public interface jvmtiEventThreadEnd extends jvmtiEventCallback
{
    void ThreadEnd(Thread thread);
}
