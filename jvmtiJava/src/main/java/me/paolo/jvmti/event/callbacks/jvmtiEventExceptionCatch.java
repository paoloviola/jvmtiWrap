package me.paolo.jvmti.event.callbacks;

public interface jvmtiEventExceptionCatch extends jvmtiEventCallback
{
    void ExceptionCatch(
            Thread thread,
            long method,
            long location,
            Throwable exception
    );
}
