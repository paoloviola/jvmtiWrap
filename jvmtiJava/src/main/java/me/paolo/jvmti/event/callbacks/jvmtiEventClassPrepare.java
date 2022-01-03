package me.paolo.jvmti.event.callbacks;

public interface jvmtiEventClassPrepare extends jvmtiEventCallback
{
    void ClassPrepare(
            Thread thread,
            Class<?> klass
    );
}
