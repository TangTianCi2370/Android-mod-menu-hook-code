bool feature1, feature2, featureHookToggle, Health;
int dmgValue = 1;
int dmgValue2 = 1;
int dmgValue3 = 1;
int dmgValue4 = 1;
int dmgValue5 = 1;
int dmgValue6 = 1;
int dmgValue7 = 1;
int dmgValue8 = 1;
int defValue = 1;
int defValue2 = 1;
int defValue3 = 1;
int defValue4 = 1;
int defValue5 = 1;
int defValue6 = 1;
int defValue7 = 1;
int defValue8 = 1;
void *instanceBtn;

bool isPistolAmmo = false;
bool isShotGunAmmo = false;
bool isLaserGunAmmo = false;
bool isBazookaAmmo = false;




void (*old_Damage)(void *instance,int a1);
void damage(void *instance,int a1) {

    if (instance != NULL && dmgValue) {
        return old_Damage(instance,a1 * dmgValue);
    }
    return old_Damage(instance,a1);
}
void (*old_Defense)(void *instance,int a1);
void defense(void *instance,int a1) {

    if (instance != NULL && defValue) {
        return old_Defense(instance,a1 / defValue);
    }
    return old_Defense(instance,a1);
}
int (*old_ShotGun)(void *instance);
int ShotGun(void *instance) {

    if (instance != NULL && isShotGunAmmo) {
        return 999;

    }
    return old_ShotGun(instance);
}

int (*old_Bazooka)(void *instance);
int Bazooka(void *instance) {

    if (instance != NULL && isBazookaAmmo) {
        return 999;

    }
    return old_Bazooka(instance);
}

int (*old_LaserGun)(void *instance);
int LaserGun(void *instance) {

    if (instance != NULL && isLaserGunAmmo) {
        return 999;

    }
    return old_LaserGun(instance);
}

int (*old_Pistol)(void *instance);
int Pistol(void *instance) {

    if (instance != NULL && isPistolAmmo) {
        return 999;

    }
    return old_Pistol(instance);
}





    HOOK_LIB("libil2cpp.so", "0x17A0AB0", damage, old_Damage);  //GetPlayerDamage
    HOOK_LIB("libil2cpp.so", "0x17A0C78", defense, old_Defense); //GetPlayerHitDamage
    HOOK_LIB("libil2cpp.so", "0x15B93F4", Pistol, old_Pistol);  //get_NowAmmoCount
    HOOK_LIB("libil2cpp.so", "0x174F2C8", ShotGun, old_ShotGun);  //get_NowAmmoCount
    HOOK_LIB("libil2cpp.so", "0x1598C3C", LaserGun, old_LaserGun);  //get_NowAmmoCount
    HOOK_LIB("libil2cpp.so", "0x16C21DC", Bazooka, old_Bazooka);                     //  get_NowAmmoCount
 PATCH_LIB_SWITCH("libil2cpp.so", " 0x15D5E8C", "01 00 A0 E3 1E FF 2F E1", boolean);  // PlayerHit 
 PATCH_LIB_SWITCH("libil2cpp.so", "0x17A0DA4", "00 00 A0 E3 1E FF 2F E1", boolean);   // GetPurchaseChapter
