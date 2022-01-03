package me.paolo.jvmti;

import me.paolo.jvmti.event.callbacks.jvmtiEventCallback;
import me.paolo.jvmti.event.jvmtiEvent;
import me.paolo.jvmti.event.jvmtiEventCallbacks;
import me.paolo.jvmti.event.jvmtiEventMode;

import java.io.File;

public class jvmtiTestCallbacks
{

    public static void main(String[] args) {
        // Loading DLL, since it's not in the resources folder!
        System.load(new File("../jvmtiCpp/x64/Release/jvmtiCpp.dll").getAbsolutePath());

        jvmtiEventCallbacks callb = new jvmtiEventCallbacks();
        callb.VMInit = newCallback((thread) -> System.out.println("VMInit"), jvmtiEvent.JVMTI_EVENT_VM_INIT);
        callb.VMDeath = newCallback(() -> System.out.println("VMDeath"), jvmtiEvent.JVMTI_EVENT_VM_DEATH);
        callb.ThreadStart = newCallback((thread) -> System.out.println("ThreadStart"), jvmtiEvent.JVMTI_EVENT_THREAD_START);
        callb.ThreadEnd = newCallback((thread) -> System.out.println("ThreadEnd"), jvmtiEvent.JVMTI_EVENT_THREAD_END);
        callb.ClassLoad = newCallback((thread, klass) -> System.out.println("ClassLoad"), jvmtiEvent.JVMTI_EVENT_CLASS_LOAD);
        callb.ClassPrepare = newCallback((thread, klass) -> System.out.println("ClassPrepare"), jvmtiEvent.JVMTI_EVENT_CLASS_PREPARE);
        System.err.println("SetEventCallbacks: " + jvmtiEnv.SetEventCallbacks(callb));
    }

    private static <T extends jvmtiEventCallback> T newCallback(T callb, jvmtiEvent event) {
        jvmtiError err = jvmtiEnv.SetEventNotificationMode(jvmtiEventMode.JVMTI_ENABLE, event, null);
        switch (err) {
            case JVMTI_ERROR_NONE: break;
            case JVMTI_ERROR_NOT_AVAILABLE: {
                System.err.println("Event not available (Maybe debug mode fixes it?)");
                break;
            }
            default: {
                System.err.println("Couldn't enable event: " + err);
                break;
            }
        }

        return callb;
    }

}
