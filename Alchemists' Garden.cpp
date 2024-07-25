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
    MemoryPatch enemyattack;
} hexPatches;

#define targetLibName OBFUSCATE("libil2cpp.so")


bool feature2 = false;

int atk = 1;
int (*old_baseatk)(void *instance);
int baseatk(void *instance) {
  if(instance != NULL && atk > 1){

     return  (*old_baseatk)(instance) * atk;
  }
    return (*old_baseatk)(instance);
}


void *hack_thread(void *) {
    LOGI(OBFUSCATE("pthread created"));

    //Check if target lib is loaded
    do {
        sleep(1);
    } while (!isLibraryLoaded(targetLibName));






const char *features[] = {


            OBFUSCATE("0_SeekBar_damage multiplier_1_100"),
            OBFUSCATE("1_Toggle_enemy not attack"),
        
    };



        case 0:
            if(value >= 1){
                atk = value;
            }
      
            break;
            case 1:
            feature2 = boolean;
            if (feature2) {

                hexPatches.enemyattack.Modify(); // on
 
   } else {
                hexPatches.enemyattack.Restore(); // off
         }
                  
            break;
 

    }


    MSHookFunction((void *) getAbsoluteAddress(targetLibName,string2Offset(OBFUSCATE_KEY("0x117BBB0", '?'))),(void *) baseatk, (void **) &old_baseatk); 
    hexPatches.enemyattack = MemoryPatch::createWithHex(targetLibName,string2Offset(OBFUSCATE_KEY("0xFFE038", '-')),OBFUSCATE("00 00 A0 E3 1E FF 2F E1"));
