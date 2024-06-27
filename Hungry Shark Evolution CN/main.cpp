int Health = 1;
void (*old_AwardPointsHealthBoostCoinsGemsGrowth)(void *instance,int a1,float b);
void AwardPointsHealthBoostCoinsGemsGrowth(void *instance,int a1,float b) {
    if (instance != NULL && Health) {
      b * (int)Health;
       // return old_AwardPointsHealthBoostCoinsGemsGrowth(instance,a1,b * (int) Health);
    }
    return old_AwardPointsHealthBoostCoinsGemsGrowth(instance,a1,b);
}

case 1:
          if(value >= 1){
              Health = value;
          }
         break;

HOOK_LIB("libil2cpp.so", "0x9AF12C", AwardHealth, old_AwardHealth);

            
