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

#if defined(__aarch64__) //Compile for arm64 lib only
#include <And64InlineHook/And64InlineHook.hpp>
#else //Compile for armv7 lib only. Do not worry about greyed out highlighting code, it still works

#include <Substrate/SubstrateHook.h>
#include <Substrate/CydiaSubstrate.h>

#endif

// fancy struct for patches for kittyMemory
struct My_Patches {
    // let's assume we have patches for these functions for whatever game
    // like show in miniMap boolean function
    MemoryPatch attack,godmode,attackX2,attackX3;
} hexPatches;

bool feature1 = false, feature2 = false, featureHookToggle = false;
int sliderValue = 1;
void *instanceBtn;

// Function pointer splitted because we want to avoid crash when the il2cpp lib isn't loaded.
// If you putted getAbsoluteAddress here, the lib tries to read the address without il2cpp loaded,
// will result in a null pointer which will cause crash
// See https://guidedhacking.com/threads/android-function-pointers-hooking-template-tutorial.14771/
void (*AddMoneyExample)(void *instance, int amount);

//Target lib here
#define targetLibName OBFUSCATE("libil2cpp.so")

// we will run our patches in a new thread so our while loop doesn't block process main thread
// Don't forget to remove or comment out logs before you compile it.

//KittyMemory Android Example: https://github.com/MJx0/KittyMemory/blob/master/Android/test/src/main.cpp
//Use ARM Converter to convert ARM to HEX: https://armconverter.com/
//Note: We use OBFUSCATE_KEY for offsets which is the important part xD

// Hooking example



float (*old_GetAttackPower)(void *instance);
float getAttackPower(void *instance) {
    if (instance != NULL && sliderValue > 1) {
        return old_GetAttackPower(instance) * (int) sliderValue;
    }
    return old_GetAttackPower(instance);
}

void (*old_Update)(void *instance);
void Update(void *instance) {
    instanceBtn = instance;
    old_Update(instance);
}

void *hack_thread(void *) {
    LOGI(OBFUSCATE("pthread created"));

    //Check if target lib is loaded
    do {
        sleep(1);
    } while (!isLibraryLoaded(targetLibName));

    //Anti-lib rename
    /*
    do {
        sleep(1);
    } while (!isLibraryLoaded("libYOURNAME.so"));*/

    LOGI(OBFUSCATE("%s has been loaded"), (const char *) targetLibName);

#if defined(__aarch64__) //Compile for arm64 lib only
    // New way to patch hex via KittyMemory without need to  specify len. Spaces or without spaces are fine
    // ARM64 assembly example
    // MOV X0, #0x0 = 00 00 80 D2
    // RET = C0 03 5F D6

    // Offset Hook example
    //A64HookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(OBFUSCATE_KEY("0x123456", 'l'))), (void *) get_BoolExample,
    //                (void **) &old_get_BoolExample);

    // Function pointer splitted because we want to avoid crash when the il2cpp lib isn't loaded.
    // See https://guidedhacking.com/threads/android-function-pointers-hooking-template-tutorial.14771/
    //AddMoneyExample = (void(*)(void *,int))getAbsoluteAddress(targetLibName, 0x123456);

#else //Compile for armv7 lib only. Do not worry about greyed out highlighting code, it still works

    // New way to patch hex via KittyMemory without need to specify len. Spaces or without spaces are fine
    // ARMv7 assembly example
    // MOV R0, #0x0 = 00 00 A0 E3
    // BX LR = 1E FF 2F E1

    MSHookFunction((void *) getAbsoluteAddress(targetLibName,string2Offset(OBFUSCATE_KEY("0x157FA70", '0'))),(void *) getAttackPower, (void **) &old_GetAttackPower); // public float get_hpNowP
    hexPatches.godmode = MemoryPatch::createWithHex(targetLibName,string2Offset(OBFUSCATE_KEY("0x6DC624", '1')),OBFUSCATE("00 00 A0 E3 1E FF 2F E1"));    //public ObscuredFloat get_hp






    //Can apply patches directly here without need to use switch
    //hexPatches.GodMode.Modify();
    //hexPatches.GodMode2.Modify();

    // Offset Hook example
    //MSHookFunction((void *) getAbsoluteAddress(targetLibName,
    //               string2Offset(OBFUSCATE_KEY("0x123456", '?'))),
    //               (void *) get_BoolExample, (void **) &old_get_BoolExample);

    // Symbol hook example (untested). Symbol/function names can be found in IDA if the lib are not stripped. This is not for il2cpp games
    //MSHookFunction((void *) ("__SymbolNameExample"), (void *) get_BoolExample, (void **) &old_get_BoolExample);

    // Function pointer splitted because we want to avoid crash when the il2cpp lib isn't loaded.
    // See https://guidedhacking.com/threads/android-function-pointers-hooking-template-tutorial.14771/
    AddMoneyExample = (void (*)(void *, int)) getAbsoluteAddress(targetLibName, 0x123456);

    LOGI(OBFUSCATE("Done"));
#endif

    return NULL;
}

//JNI calls
extern "C" {
// Note:
// Do not change or translate the first text unless you know what you are doing
// Assigning feature numbers is optional. Without it, it will automatically count for you, starting from 0
// Assigned feature numbers can be like any numbers 1,3,200,10... instead in order 0,1,2,3,4,5...
// ButtonLink, Category, RichTextView and RichWebView is not counted. They can't have feature number assigned
// Toggle, ButtonOnOff and Checkbox can be switched on by default, if you add True_. Example: CheckBox_True_The Check Box
// To learn HTML, go to this page: https://www.w3schools.com/

JNIEXPORT jobjectArray
JNICALL
Java_uk_lgl_modmenu_FloatingModMenuService_getFeatureList(JNIEnv *env, jobject context) {
    jobjectArray ret;

    //Toasts added here so it's harder to remove it
    MakeToast(env, context, OBFUSCATE("Modded by tang1234"), Toast::LENGTH_LONG);
    MakeToast(env, context, OBFUSCATE("platinmods.com"), Toast::LENGTH_LONG);
    MakeToast(env, context, OBFUSCATE("platinmods.com"), Toast::LENGTH_LONG);
    const char *features[] = {


            OBFUSCATE("0_InputValue_damage"),
            OBFUSCATE("1_Toggle_god mode"),
            OBFUSCATE("RichWebView_<html><head><style>body{color: white;}</style></head><body>"
                      "<div style=\"background-color: darkblue; text-align: center;\">Join Us</div>"
                      "</body></html>"),
            OBFUSCATE("ButtonLink_PLATINMODS.COM_https://platinmods.com/") //Not counted

    };

        //Now you dont have to manually update the number everytime;
    int Total_Feature = (sizeof features / sizeof features[0]);
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));

    for (int i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    pthread_t ptid;
    pthread_create(&ptid, NULL, antiLeech, NULL);

    return (ret);
}

JNIEXPORT void JNICALL
Java_uk_lgl_modmenu_Preferences_Changes(JNIEnv *env, jclass clazz, jobject obj,
                                        jint featNum, jstring featName, jint value,
                                        jboolean boolean, jstring str) {
    //Convert java string to c++
    const char *featureName = env->GetStringUTFChars(featName, 0);
    const char *TextInput;
    if (str != NULL)
        TextInput = env->GetStringUTFChars(str, 0);
    else
        TextInput = "Empty";

    LOGD(OBFUSCATE("Feature name: %d - %s | Value: = %d | Bool: = %d | Text: = %s"), featNum,
         featureName, value,
         boolean, TextInput);

    //BE CAREFUL NOT TO ACCIDENTLY REMOVE break;

    switch (featNum) {

        case 0:
            if (value >= 1) {
                sliderValue = value;
            }
            break;

        case 1:
            feature2 = boolean;
            if (feature2) {
                
                hexPatches.godmode.Modify();

                //LOGI(OBFUSCATE("On"));
            } else {
                hexPatches.godmode.Restore();

                //LOGI(OBFUSCATE("Off"));
            }
            break;





    }
}
}

//No need to use JNI_OnLoad, since we don't use JNIEnv
//We do this to hide OnLoad from disassembler
__attribute__((constructor))
void lib_main() {
    // Create a new thread so it does not block the main thread, means the game would not freeze
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);
}

/*
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *globalEnv;
    vm->GetEnv((void **) &globalEnv, JNI_VERSION_1_6);

    return JNI_VERSION_1_6;
}
 */
