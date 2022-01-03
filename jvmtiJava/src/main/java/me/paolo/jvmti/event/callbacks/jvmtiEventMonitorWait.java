package me.paolo.jvmti.event.callbacks;

public interface jvmtiEventMonitorWait extends jvmtiEventCallback
{
    void MonitorWait(
            Thread thread,
            Object object,
            long timeout
    );
}
