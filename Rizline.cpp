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




bool isopen = false;
void (*old_getjudge)(void *instance,int a,float b);
void getjudge(void *instance,int a,float b) {
    
    if (instance != NULL) {
      if (isopen) {
       a = 1;   //perfect,0 = Miss,RizTimeEarlyPerfect = 2,RizTimeLatePerfect = 3,RizTimeMaxPerfect = 4,RizTimeMiss = 5;
	    }
    }
		 return old_getjudge(instance,a,b);
}




void *hack_thread(void *) {
    LOGI(OBFUSCATE("pthread created"));

    //Check if target lib is loaded
    do {
        sleep(1);
    } while (!isLibraryLoaded(targetLibName));


#if defined(__aarch64__) //To compile this code for arm64 lib only. Do not worry about greyed out highlighting code, it still works
  
    HOOK_LIB("libil2cpp.so", "0x0", getjudge, old_getjudge);
    
#else //To compile this code for armv7 lib only.


    LOGI(OBFUSCATE("Done"));
#endif

    return NULL;
}


const char *features[] = {
          //  OBFUSCATE("Category_The Category"), //Not counted
            OBFUSCATE("1_Toggle_Enable auto dabce"),

    };

switch (featNum) {
        case 1:
				isopen = boolean;
				break;
    }
}
