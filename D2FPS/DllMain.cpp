#include "D2FPS.h"
#include <Windows.h>

BOOL WINAPI DllMain(HMODULE instance, DWORD reason, VOID* reserved) {
	switch (reason) {
	case DLL_PROCESS_ATTACH:
		return D2FPS::Startup(instance, reserved);
		break;
	case DLL_PROCESS_DETACH:
		return D2FPS::Shutdown();
		break;
	}
}