#include <windows.h>
#include <stdint.h>
#include <string.h>

static uint8_t fakeTicket[128] = {0};
static int dummyInt = 1;
static void* dummyPtr = &dummyInt;

// Р—Р°РіР»СѓС€РєРё С„СѓРЅРєС†РёР№ SteamAPI
extern "C" {

// Р’РѕР·РІСЂР°С‚ С„РёРєС‚РёРІРЅРѕРіРѕ AuthSessionTicket
__declspec(dllexport) uint32_t __cdecl SteamUser_GetAuthSessionTicket(void* pTicket, int cbMaxTicket, uint32_t* pcbTicket) {
    if (pcbTicket) *pcbTicket = sizeof(fakeTicket);
    if (pTicket) memcpy(pTicket, fakeTicket, sizeof(fakeTicket));
    return 1;
}

__declspec(dllexport) void __cdecl SteamAPI_RunCallbacks() {}
__declspec(dllexport) bool __cdecl SteamAPI_Init() { return true; }
__declspec(dllexport) bool __cdecl SteamAPI_InitSafe() { return true; }
__declspec(dllexport) void __cdecl SteamAPI_Shutdown() {}

__declspec(dllexport) void* __cdecl SteamUser() { return dummyPtr; }
__declspec(dllexport) void* __cdecl SteamFriends() { return dummyPtr; }
__declspec(dllexport) void* __cdecl SteamUtils() { return dummyPtr; }
__declspec(dllexport) void* __cdecl SteamApps() { return dummyPtr; }
__declspec(dllexport) void* __cdecl SteamClient() { return dummyPtr; }

}
