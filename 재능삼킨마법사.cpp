
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

#define targetLibName OBFUSCATE("libil2cpp.so")

float (*old_GetAttackPower)(void *instance);
float getAttackPower(void *instance) {
    if (instance != NULL && sliderValue > 1) {
        return old_GetAttackPower(instance) * (int) sliderValue;
    }
    return old_GetAttackPower(instance);
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




            
    MSHookFunction((void *) getAbsoluteAddress(targetLibName,string2Offset(OBFUSCATE_KEY("0x157FA70", '0'))),(void *) getAttackPower, (void **) &old_GetAttackPower); // public float get_hpNowP
    hexPatches.godmode = MemoryPatch::createWithHex(targetLibName,string2Offset(OBFUSCATE_KEY("0x6DC624", '1')),OBFUSCATE("00 00 A0 E3 1E FF 2F E1"));    //public ObscuredFloat get_hp

    LOGI(OBFUSCATE("Done"));
#endif

    return NULL;
}


    const char *features[] = {


            OBFUSCATE("0_InputValue_damage"),
            OBFUSCATE("1_Toggle_god mode"),
            
            
    };
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

