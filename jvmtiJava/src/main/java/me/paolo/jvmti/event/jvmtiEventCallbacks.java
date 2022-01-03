package me.paolo.jvmti.event;

import me.paolo.jvmti.event.callbacks.*;

public class jvmtiEventCallbacks
{

    public jvmtiEventVMInit VMInit;
    public jvmtiEventVMDeath VMDeath;
    public jvmtiEventThreadStart ThreadStart;
    public jvmtiEventThreadEnd ThreadEnd;
    public jvmtiEventClassFileLoadHook ClassFileLoadHook;
    public jvmtiEventClassLoad ClassLoad;
    public jvmtiEventClassPrepare ClassPrepare;
    public jvmtiEventVMStart VMStart;
    public jvmtiEventException Exception;
    public jvmtiEventExceptionCatch ExceptionCatch;
    public jvmtiEventSingleStep SingleStep;
    public jvmtiEventFramePop FramePop;
    public jvmtiEventBreakpoint Breakpoint;
    public jvmtiEventFieldAccess FieldAccess;
    public jvmtiEventFieldModification FieldModification;
    public jvmtiEventMethodEntry MethodEntry;
    public jvmtiEventMethodExit MethodExit;
//    public jvmtiEventCallback NativeMethodBind;
//    public jvmtiEventCallback CompiledMethodLoad;
//    public jvmtiEventCallback CompiledMethodUnload;
//    public jvmtiEventCallback DynamicCodeGenerated;
//    public jvmtiEventCallback DataDumpRequest;
    public jvmtiEventMonitorWait MonitorWait;
    public jvmtiEventMonitorWaited MonitorWaited;
    public jvmtiEventMonitorContendedEnter MonitorContendedEnter;
    public jvmtiEventMonitorContendedEntered MonitorContendedEntered;
//    public jvmtiEventCallback ResourceExhausted;
//    public jvmtiEventCallback GarbageCollectionStart;
//    public jvmtiEventCallback GarbageCollectionFinish;
//    public jvmtiEventCallback ObjectFree;
    public jvmtiEventVMObjectAlloc VMObjectAlloc;

}
