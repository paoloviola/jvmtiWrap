package me.paolo.jvmti.event.callbacks;

public interface jvmtiEventClassLoad extends jvmtiEventCallback
{
    void ClassLoad(
            Thread thread,
            Class<?> klass
    );
}
