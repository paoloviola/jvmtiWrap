package me.paolo.jvmti.event.callbacks;

public interface jvmtiEventMonitorWaited extends jvmtiEventCallback
{
    void MonitorWaited(
            Thread thread,
            Object object,
            boolean timed_out
    );
}
