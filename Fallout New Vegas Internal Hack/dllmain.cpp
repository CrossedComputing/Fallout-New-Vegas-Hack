#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include "InternalFunctions.h"
#include "Player.h"
#include "Game.h"



DWORD WINAPI mainThread(LPVOID moduleHandle) {
    
    FILE* f = InternalFunctions::createConsole();

    std::vector <Character> entityList;
    while (true) {
        system("cls");
        Player::godMode();

        entityList = Game::getEntityList();

        for (int i = 0; i < entityList.size(); i++) {
            std::cout << "Entity " << i << ": " << std::hex << entityList[i].getAddress().getAddress() << std::endl;
        }
        


        // So we can break from the infinite loop
        if (GetAsyncKeyState(VK_INSERT) & 1) break;

        Sleep(4000);
    }

    // Free the DLL, Close the console
    InternalFunctions::removeConsole(f);
    FreeLibraryAndExitThread((HMODULE)moduleHandle, NULL);
    return NULL;
}


BOOL APIENTRY DllMain( HMODULE moduleHandle,
                       DWORD  callReason,
                       LPVOID lpvReserved
                     )
{
    switch (callReason) {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(0, 0, mainThread, moduleHandle, 0, 0));
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}