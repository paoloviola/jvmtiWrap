package me.paolo.jvmti;

import me.paolo.jvmti.event.jvmtiEvent;
import me.paolo.jvmti.event.jvmtiEventCallbacks;
import me.paolo.jvmti.event.jvmtiEventMode;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

public class jvmtiEnv
{

    private jvmtiEnv() { }

    // Threading
    public static native Thread GetCurrentThread();
    public static native Thread[] GetAllThreads();

    public static native jvmtiError SuspendThread(Thread thread);
    public static native jvmtiError ResumeThread(Thread thread);
    public static native jvmtiError StopThread(Thread thread, Throwable t);
    public static native jvmtiError InterruptThread(Thread thread);
    // Threading

    // Capabilities
    public static native jvmtiError AddCapabilities(jvmtiCapabilities capabilities);
    public static native jvmtiError RelinquishCapabilities(jvmtiCapabilities capabilities);
    public static native jvmtiCapabilities GetCapabilities();
    // Capabilities

    // Instrumentation
    public static native Class<?>[] GetLoadedClasses();
    public static native Class<?>[] GetClassLoaderClasses(ClassLoader classLoader);

    public static native jvmtiError RetransformClasses(Class<?>[] classes);
    public static native jvmtiError RedefineClasses(jvmtiClassDefinition[] classDefinitions);
    // Instrumentation

    // Event
    public static native jvmtiError SetEventCallbacks(jvmtiEventCallbacks callbacks);
    public static native jvmtiError SetEventNotificationMode(jvmtiEventMode mode, jvmtiEvent type, Thread thread);
    // Event

    static {
        try(InputStream inputStream = jvmtiEnv.class.getResourceAsStream("/jvmtiCpp.dll")) {
            if(inputStream == null) throw new IOException("jvmtiCpp.dll not found!");

            File file = File.createTempFile("jvmtiCpp", ".dll");
            try(FileOutputStream outputStream = new FileOutputStream(file)) {
                byte[] tmp = new byte[1024];

                int read;
                while((read = inputStream.read(tmp)) != -1)
                    outputStream.write(tmp, 0, read);
            }
            file.deleteOnExit();

            System.load(file.getAbsolutePath());
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }

}
