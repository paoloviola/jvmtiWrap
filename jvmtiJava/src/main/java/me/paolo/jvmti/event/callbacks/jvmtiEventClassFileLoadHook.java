package me.paolo.jvmti.event.callbacks;

import java.security.ProtectionDomain;

public interface jvmtiEventClassFileLoadHook extends jvmtiEventCallback
{
    byte[] ClassFileLoadHook(
            Class<?> classBeingRedefined,
            ClassLoader loader,
            String name,
            ProtectionDomain protectionDomain,
            byte[] classData
    );
}
