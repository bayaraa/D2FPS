#pragma once
#include <Windows.h>
#include <thread>
#include <chrono>
#include "Patch.h"

using namespace std;

namespace D2FPS {
	extern HINSTANCE instance;
	extern WNDPROC OldWNDPROC;
	extern bool initialized;

	extern bool Startup(HINSTANCE instance, VOID* reserved);
	extern "C" __declspec(dllexport) void Initialize();
	extern bool Shutdown();
};