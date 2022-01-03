package me.paolo.jvmti.event.callbacks;

public interface jvmtiEventMethodEntry extends jvmtiEventCallback
{
    void MethodEntry(
            Thread thread,
            long method
    );
}
