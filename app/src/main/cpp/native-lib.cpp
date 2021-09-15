#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <errno.h>
#include "PanoMaker/DPPanoMakerProDLLMain.h"

using namespace std;

extern "C" JNIEXPORT jstring JNICALL
Java_pl_theliver_nativeapplicationxphase_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    ProInitRawFileReader(reinterpret_cast<unsigned char *>('a'), 2);
    return env->NewStringUTF(hello.c_str());
}
