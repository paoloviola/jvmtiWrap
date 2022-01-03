package me.paolo.jvmti;

import java.util.Objects;

public class jvmtiClassDefinition
{

    private final Class<?> target;
    private final byte[] data;
    public jvmtiClassDefinition(Class<?> target, byte[] data) {
        this.target = Objects.requireNonNull(target);
        this.data = Objects.requireNonNull(data);
    }

    public Class<?> getTarget() {
        return target;
    }

    public byte[] getData() {
        return data;
    }

}
