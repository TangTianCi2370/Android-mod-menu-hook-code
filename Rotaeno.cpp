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


int note;
bool isopen = false;
bool isoff = false;

void (*old_onhurt)(void *instance,int a,int b,bool c);
void onhurt(void *instance,int a,int b,bool c) {
    
    if (instance != NULL && note) {
    
      if (isopen) {
		  
      return old_onhurt(instance,note,b,true);  
	    }
         }
		 return old_onhurt(instance,a,b,c);
        }
     // bool isopen2 = false;
	
		
		

bool (*old_get_piadpack)(void *instance);
bool piadpack(void *instance) {
    if (instance != NULL && isoff) {
        return false;
    }
    return old_get_piadpack(instance);
}





    void *hack_thread(void *) {
        LOGI(OBFUSCATE("pthread created"));

        //Check if target lib is loaded
        do {
            sleep(1);
        } while (!isLibraryLoaded(targetLibName));


     OBFUSCATE("99_Toggle_unlock piad pick"),
	   OBFUSCATE("110_Toggle_Enable dance"),
     OBFUSCATE("112_Spinner_dance_ slideMiss,miss,good,perfect,perfectPlus,nodePerfectPlus,slidePerfectPlus"),



	case 99:
				isoff = boolean;
				break;
						case 110:
			isopen = boolean;
break;
		        case 112:
            switch (value) {
				case 0:
					note = 0; // slideMiss
                case 1:
					
					note = 2;  //  miss
          break;
                case 2:
					note = 3;   //good
                  break;
                case 3:
                money = 4;  // perfect
				case 4:
					note = 5;   //perfectPlus
                  break;
				  
				  case 5:
					  note = 6;  //slidePerfectPlus
					  break;
					  case 6:
				note = 7; // nodePerfectPlus
				
                       break;
       


HOOK_LIB("libil2cpp.so", "0x18A1C5C", onhurt, old_onhurt);
HOOK_LIB("libil2cpp.so", "0x221C384", piadpack, old_get_piadpack);		
