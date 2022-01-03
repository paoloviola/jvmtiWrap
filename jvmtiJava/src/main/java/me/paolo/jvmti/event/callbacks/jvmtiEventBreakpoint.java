package me.paolo.jvmti.event.callbacks;

public interface jvmtiEventBreakpoint extends jvmtiEventCallback
{
    void Breakpoint(
            Thread thread,
            long method,
            long location
    );
}
