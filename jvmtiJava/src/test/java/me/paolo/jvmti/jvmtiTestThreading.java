package me.paolo.jvmti;

import java.io.File;
import java.util.Arrays;

public class jvmtiTestThreading
{

    public static void main(String[] args) throws Throwable {
        // Loading DLL, since it's not in the resources folder!
        System.load(new File("../jvmtiCpp/x64/Release/jvmtiCpp.dll").getAbsolutePath());

        jvmtiCapabilities capabilities = new jvmtiCapabilities();
        capabilities.can_suspend = true;
        capabilities.can_signal_thread = true;
        jvmtiEnv.AddCapabilities(capabilities);

        System.out.println(jvmtiEnv.GetCurrentThread());
        Arrays.stream(jvmtiEnv.GetAllThreads()).forEach(System.out::println);

        Thread t = new Thread(() -> {
            for(int i = 0; true; i++) {
                System.out.println(i);

                try {
                    Thread.sleep(1000);
                }
                catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });
        t.start();

        jvmtiEnv.SuspendThread(t);
        System.out.println("Suspended!");

        Thread.sleep(5000);
        jvmtiEnv.ResumeThread(t);
        System.out.println("Resumed!");

        Thread.sleep(5000);
        jvmtiEnv.InterruptThread(t);
        System.out.println("Interrupted!");

        Thread.sleep(5000);
        jvmtiEnv.StopThread(t, new NullPointerException());
        System.out.println("Stopped!");
    }

}
