#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <thread>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include "Includes/Logger.h"
#include "Includes/obfuscate.h"
#include "Includes/Utils.h"
#include "KittyMemory/MemoryPatch.h"
#include "Menu/Setup.h"

//Target lib here
#define targetLibName OBFUSCATE("libil2cpp.so")

#include "Includes/Macros.h"

int dmgValue = 1;
int defValue = 1;

int (*is_player)(void* instance);
float (*old_Attack)(void *_this); 
float attack(void *_this){
    int player = is_player(_this);
    if(_this != NULL){
      if(player != 0) {

          return old_Attack(_this) * (int)dmgValue;

        }
      else if(player == 0)
        {
return old_Attack(_this) / (int)defValue;
          
        }
    }
    return old_Attack(_this);
}



const char *features[] = {
                OBFUSCATE("2_SeekBar_Damage multiplier_1_100"),
                OBFUSCATE("3_SeekBar_Defeense multiplier_1_100"),
        };


case 2:
                if(value >= 1)
                {
                    dmgValue = value;
                   
                }
                break;
            case 3:
                if(value >= 1)
                {
                    defValue = value;
                 //   defValue2 = value;
                }
                break;



HOOK_LIB("libil2cpp.so", "0x10A4D1C", attack, old_Attack);
is_player = (int(*)(void *))getAbsoluteAddress(targetLibName, 0x1088E10);
