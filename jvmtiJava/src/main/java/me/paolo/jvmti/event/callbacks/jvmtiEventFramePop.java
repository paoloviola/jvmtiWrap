package me.paolo.jvmti.event.callbacks;

public interface jvmtiEventFramePop extends jvmtiEventCallback
{
    void FramePop(
            Thread thread,
            long method,
            boolean wasPoppedByException
    );
}
