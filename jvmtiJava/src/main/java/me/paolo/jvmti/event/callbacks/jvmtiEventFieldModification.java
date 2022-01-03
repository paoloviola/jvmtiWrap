package me.paolo.jvmti.event.callbacks;

public interface jvmtiEventFieldModification extends jvmtiEventCallback
{
    void FieldModification(
            Thread thread,
            long method,
            long location,
            Class<?> fieldKlass,
            Object object,
            long field,
            char signatureType,
            Object newValue
    );
}
