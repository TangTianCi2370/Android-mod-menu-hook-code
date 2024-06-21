bool isgod = false;
void (*old_MonsterAI_Attack)(void *instance);
void MonsterAI_Attack(void *instance) {
    instanceBtn = instance;
    if (instance != NULL) {
        if (isgod) {
           return;
        }
    }
    return MonsterAI_Attack(instance);
}

HOOK_LIB("libil2cpp.so", "0x37B048", MonsterAI_Attack, old_MonsterAI_Attack);
