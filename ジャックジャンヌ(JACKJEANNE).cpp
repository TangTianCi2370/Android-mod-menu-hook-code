#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include "Includes/Logger.h"
#include "Includes/obfuscate.h"
#include "Includes/Utils.h"
#include "KittyMemory/MemoryPatch.h"
#include "Menu.h"

struct My_Patches {
    MemoryPatch unlocked;
} hexPatches;

bool feature2 = false;

#define targetLibName OBFUSCATE("libil2cpp.so")


#if defined(__aarch64__) //Compile for arm64 lib only

 hexPatches.unlocked = MemoryPatch::createWithHex(targetLibName,string2Offset(OBFUSCATE_KEY("0xDB8928", '1')),OBFUSCATE("20 00 80 D2 C0 03 5F D6"));
                                                   
                                                   
#else //Compile for armv7 lib only. Do not worry about greyed out highlighting code, it still works

 hexPatches.unlocked = MemoryPatch::createWithHex(targetLibName,string2Offset(OBFUSCATE_KEY("0x87C924", '1')),OBFUSCATE("01 00 A0 E3 1E FF 2F E1"));
    LOGI(OBFUSCATE("Done"));
#endif

    return NULL;
}


JNIEXPORT jobjectArray
JNICALL
Java_uk_lgl_modmenu_FloatingModMenuService_getFeatureList(JNIEnv *env, jobject context) {
    jobjectArray ret;
    const char *features[] = {



            OBFUSCATE("1_Toggle_Unlock full content"),
         
    };





void *hack_thread(void *) {
    LOGI(OBFUSCATE("pthread created"));

    //Check if target lib is loaded
    do {
        sleep(1);
    } while (!isLibraryLoaded(targetLibName));


switch (featNum) {



        case 1:
            feature2 = boolean;
            if (feature2) {
                
                hexPatches.unlocked.Modify();

                
            } else {
                hexPatches.unlocked.Restore();

              
            }
            break;

    }
}
