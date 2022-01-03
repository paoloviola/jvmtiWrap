package me.paolo.jvmti.event;

import java.util.Arrays;

public enum jvmtiEventMode
{

    JVMTI_ENABLE(1),
    JVMTI_DISABLE(0);

    private final int id;
    jvmtiEventMode(int id) {
        this.id = id;
    }

    public int getId() {
        return id;
    }

    public static jvmtiEventMode getById(int id) {
        return Arrays.stream(values())
                .filter(em -> em.getId() == id)
                .findAny().orElse(null);
    }

}
