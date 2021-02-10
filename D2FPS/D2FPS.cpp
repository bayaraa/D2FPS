#include "D2FPS.h"
#include <Shlwapi.h>
#include <psapi.h>

HINSTANCE D2FPS::instance;
bool D2FPS::initialized;
WNDPROC D2FPS::OldWNDPROC;

Patch* patches[] = {
	// cpu Patch
	new Patch(NOP, D2CLIENT, { 0x3CB7C, 0x2770C }, 0, 9),
	// fps Patch
	new Patch(NOP, D2CLIENT, { 0x44E51, 0x45EA1 }, 0, 8),
};

unsigned int index = 0;
bool D2FPS::Startup(HINSTANCE instance, VOID* reserved) {
	initialized = false;
	Initialize();
	return true;
}

void D2FPS::Initialize() {
	for (int n = 0; n < (sizeof(patches) / sizeof(Patch*)); n++) {
		patches[n]->Install();
	}
	initialized = true;
}

bool D2FPS::Shutdown() {
	if (initialized) {
		for (int n = 0; n < (sizeof(patches) / sizeof(Patch*)); n++) {
			delete patches[n];
		}
	}
	return true;
}