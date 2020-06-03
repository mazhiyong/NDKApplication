#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ndkapplication_MainActivity_stringFromJNI2(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";


    //获取java传递的参数
    //const char *strCont = env->GetStringUTFChars(str, JNI_FALSE);
    //通过反射获取java类
    jclass ccallj = env->FindClass("com/example/ndkapplication/MainActivity");
    //实例化该类
    jobject jobj = env->AllocObject(ccallj);
    //得到方法id
    //参数列表：反射类，方法名称，方法签名
    jmethodID methodId = env->GetMethodID(ccallj, "cUsetoJava","(Ljava/lang/String;)V");

    //调用方法
    env->CallVoidMethod(jobj, methodId,env->NewStringUTF(hello.c_str()));



    return env->NewStringUTF(hello.c_str());
}
