package me.paolo.jvmti.event.callbacks;

public interface jvmtiEventMethodExit extends jvmtiEventCallback
{
    void MethodExit(
            Thread thread,
            long method,
            boolean wasPoppedByException,
            Object returnValue
    );
}
