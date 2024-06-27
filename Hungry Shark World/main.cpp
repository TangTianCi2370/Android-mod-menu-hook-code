int isHealth = 1;
void (*old_AwardHealth)(void *instance,float a1);
void AwardHealth(void *instance,float a1) {
    if (instance != NULL && isHealth) {
        return old_AwardHealth(instance,a1 * (int) isHealth);
    }
    return old_AwardHealth(instance,a1);
}


            case 1:
          if(value >= 1){
              isHealth = value;
          }

HOOK_LIB("libil2cpp.so", "0xD207D4", AwardHealth, old_AwardHealth);
