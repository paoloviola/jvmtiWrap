package me.paolo.jvmti.event.callbacks;

public interface jvmtiEventMonitorContendedEntered extends jvmtiEventCallback
{
    void MonitorContendedEntered(
            Thread thread,
            Object object
    );
}
