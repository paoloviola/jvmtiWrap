package me.paolo.jvmti.event.callbacks;

public interface jvmtiEventException extends jvmtiEventCallback
{
    void Exception(
            Thread thread,
            long method,
            long location,
            Throwable exception,
            long catchMethod,
            long catchLocation
    );
}
