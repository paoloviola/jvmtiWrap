package me.paolo.jvmti;

import me.paolo.jvmti.event.callbacks.jvmtiEventCallback;
import me.paolo.jvmti.event.jvmtiEvent;
import me.paolo.jvmti.event.jvmtiEventCallbacks;
import me.paolo.jvmti.event.jvmtiEventMode;

import java.io.File;
import java.net.URL;

public class jvmtiTestInstrumentation
{

    public static void main(String[] args) {
        // Loading DLL, since it's not in the resources folder!
        System.load(new File("../jvmtiCpp/x64/Release/jvmtiCpp.dll").getAbsolutePath());

        jvmtiCapabilities capab = new jvmtiCapabilities();
        capab.can_retransform_classes = true;
        capab.can_retransform_any_class = true;
        capab.can_redefine_classes = true;
        capab.can_redefine_any_class = true;
        jvmtiEnv.AddCapabilities(capab);

        jvmtiEventCallbacks callb = new jvmtiEventCallbacks();
        callb.ClassFileLoadHook = newCallback((classBeingRedefined, loader, name, protectionDomain, classData) -> {
            if(name != null && name.equals("java/lang/String")) {
                // Transformed class bytes
                return classData;
            }

            // Null for non-changed data!
            return null;
        }, jvmtiEvent.JVMTI_EVENT_CLASS_FILE_LOAD_HOOK);
        jvmtiEnv.SetEventCallbacks(callb);

        System.out.println("Loaded classes count: "
                + jvmtiEnv.GetLoadedClasses().length);
        System.out.println("Loaded classes count (Classloader): "
                + jvmtiEnv.GetClassLoaderClasses(jvmtiTestInstrumentation.class.getClassLoader()).length);

        System.out.println("Redefining URL.class -> " +
                jvmtiEnv.RedefineClasses(new jvmtiClassDefinition[] {
                        new jvmtiClassDefinition(URL.class, new byte[0]) // Expected: JVMTI_ERROR_INVALID_CLASS_FORMAT
                }));

        System.out.println("Retransforming String.class -> " +
                jvmtiEnv.RetransformClasses(new Class[] { String.class }));
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
