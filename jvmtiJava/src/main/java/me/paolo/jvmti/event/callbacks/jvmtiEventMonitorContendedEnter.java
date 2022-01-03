package me.paolo.jvmti.event.callbacks;

public interface jvmtiEventMonitorContendedEnter extends jvmtiEventCallback
{
    void MonitorContendedEnter(
            Thread thread,
            Object object
    );
}
