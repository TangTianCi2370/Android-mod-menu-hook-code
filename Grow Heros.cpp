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
    MemoryPatch hitkiller;
} hexPatches;

#define targetLibName OBFUSCATE("libil2cpp.so")

bool feature1 = false;
int dmg = 1;

int (*old_Power)(void *instance);
int Power(void *instance) {
    if (instance != NULL && dmg > 1) {
      
        return old_Power(instance) * dmg; // return dmg;
    }
    return old_Power(instance);
}

    hexPatches.hitkiller = MemoryPatch::createWithHex(targetLibName,
                                                   string2Offset(OBFUSCATE_KEY("0xC46B84", '0')),
                                                   OBFUSCATE("00 00 80 D2 C0 03 5F D6"));

   A64HookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(OBFUSCATE_KEY("0xCA791C", 'l'))), (void *) Power,(void **) &old_Power);


void *hack_thread(void *) {
    LOGI(OBFUSCATE("pthread created"));

    //Check if target lib is loaded
    do {
        sleep(1);
    } while (!isLibraryLoaded(targetLibName));


const char *features[] = {


      OBFUSCATE("1_SeekBar_Damage Multiple_1_100"), // OBFUSCATE("1_InputValue_Damage"),
      OBFUSCATE("2_Toggle_god mode"),
            
    };


    switch (featNum) {
        case 1:
            if (value >= 1) {
                dmg = value;
            }
            break;

        case 2:
            feature1 = boolean;
            if (feature1) {
              
                hexPatches.hitkiller.Modify(); // on

              
            } else {
                hexPatches.hitkiller.Restore(); // off
            }
            break;

    }
}
