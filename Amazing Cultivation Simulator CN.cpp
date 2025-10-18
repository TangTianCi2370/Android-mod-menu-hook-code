//Debug Mode
bool isopenDebug = false;

typedef const char* (*GetParamsDesc_t)(void* instance);
GetParamsDesc_t orig_GetParamsDesc = nullptr;

const char* GetParamsDesc_Hook(void* instance) {
	if (!isopenDebug) {
      
        return orig_GetParamsDesc(instance);
    }
	
   
	bool* enableGmPtr = (bool*)((uintptr_t)instance + 0x38);
    bool currentValue = *enableGmPtr;

     *enableGmPtr = true;
  //  LOGI(OBFUSCATE("GetParamsDesc called! enableGm = %d"), currentValue);
    const char* result = orig_GetParamsDesc(instance);
    
    LOGI(OBFUSCATE("GetParamsDesc returned: %s"), result);
    return result;
}






#if defined(__aarch64__) //To compile this code for arm64 lib only. Do not worry about greyed out highlighting code, it still works
  // Hook GetParamsDesc
    uintptr_t GetParamsDesc_addr = getAbsoluteAddress(targetLibName, 0x2f6ac80);
    HOOK_LIB("libil2cpp.so", "0x2f6ac80", GetParamsDesc_Hook, orig_GetParamsDesc);




    case 1:
	isopen = boolean;
           break;
