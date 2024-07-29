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


#define targetLibName OBFUSCATE("libil2cpp.so")

int addloan = 1;
void (*old_LoanAdd)(void *instance,int key,int money);
void LoanAdd(void *instance,int ley,int money) {

    if (instance != NULL && addloan) {

        return old_LoanAdd(instance,addloan,money);

    }
    return old_LoanAdd(instance,addloan,money);
}



bool isPaymentMoney = false;
int (*old_get_PaymentMoney)(void *instance);
int get_PaymentMoney(void *instance) {
    if (instance != NULL && isPaymentMoney) {
        return 0;
    }
    return old_get_PaymentMoney(instance);
}



void *hack_thread(void *) {
    LOGI(OBFUSCATE("pthread created"));

    //Check if target lib is loaded
    do {
        sleep(1);
    } while (!isLibraryLoaded(targetLibName));




            OBFUSCATE("1_InputValue_Loan Add"),
            OBFUSCATE("2_Toggle_PaymentMoney to 0"),



        case 1:
            if (value >= 1) {
               addloan = value;
            }
            break;
        case 2:
         isPaymentMoney = boolean;
            break;

    HOOK_LIB("libil2cpp.so", "0x1466ED8", LoanAdd,old_LoanAdd);
    HOOK_LIB("libil2cpp.so", "0x66B518", get_PaymentMoney,old_get_PaymentMoney);


