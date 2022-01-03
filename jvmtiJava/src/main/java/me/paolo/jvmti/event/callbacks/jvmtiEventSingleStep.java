package me.paolo.jvmti.event.callbacks;

public interface jvmtiEventSingleStep extends jvmtiEventCallback
{
    void SingleStep(
            Thread thread,
            long method,
            long location
    );
}
