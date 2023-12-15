// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

HMODULE g_hDllMainModule = NULL;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

	g_hDllMainModule = hModule;

    return TRUE;
}

