#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include "InternalFunctions.h"
#include "Address.h"


DWORD WINAPI mainThread(LPVOID moduleHandle)
{
    FILE* f = InternalFunctions::createConsole();

    FloatAddress writableX(0x1873FFE0);



    while (true)
    {
        writableX.printValue();

        // So we can break from the infinite loop
        if (GetAsyncKeyState(VK_INSERT) & 1) break;

        Sleep(10);
    }

    // Free the DLL, Close the console
    InternalFunctions::removeConsole(f);
    FreeLibraryAndExitThread((HMODULE)moduleHandle, NULL);
    return NULL;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(0, 0, mainThread, hModule, 0, 0)); // Create a thread that runs hackthread function
        // Create thread creates a thread within the virtual address space of the CALLING PROCESS (so the game you're injecting in)
        // Wrapping it in closeHandle() closes the handle to the module (CreateThread returns a handle to thread created)
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}