//Target lib here
#define targetLibName OBFUSCATE("libil2cpp.so")

#include "Includes/Macros.h"

int dmgValue = 1;
int defValue = 1;

bool (*is_player)(void* instance);
bool isskill = false;
void (*old_HP)(void *instance,int a1, int a2, int a3, int a4, int a5,int a6,int a7, int a8, int a9);
void hp(void *instance,int a1, int a2, int a3, int a4, int a5,int a6,int a7, int a8, int a9) {
    bool player = is_player(instance);

    if (instance != NULL) {
        if(player){
            return old_HP(instance,a1,a2 * dmgValue,a3,a4,a5,a6,a7,a8,a9);
        }
        else
        {
            return old_HP(instance,2, a2 / defValue,a3,a4,a5,a6,a7,a8,a9);
        }
    }
    return old_HP(instance,a1,a2,a3,a4,a5,a6,a7,a8,a9);
}

void *hack_thread(void *) {
        LOGI(OBFUSCATE("pthread created"));

        //Check if target lib is loaded
        do {
            sleep(1);
        } while (!isLibraryLoaded(targetLibName));



       const char *features[] = {
                OBFUSCATE("1_SeekBar_damage multiplier_1_100"),
                OBFUSCATE("2_SeekBar_defense multiplier_1_100"),
        };

        switch (featNum) {
            case 1:
            if(value >= 1){
                dmgValue = value;
            }
                break;
            case 2:
                if(value >= 1){
                    defValue = value;
                }
                break;
        }
}


    HOOK_LIB("libil2cpp.so", "0x22158DC", hp, old_HP);  // OnHurt
    is_player = (bool(*)(void *))getAbsoluteAddress(targetLibName, 0x21CC640);   // IsHeroAvatar
