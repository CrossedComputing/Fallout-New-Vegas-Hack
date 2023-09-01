#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <vector>
#include <Psapi.h>


class InternalFunctions {
public:
	static uintptr_t resolvePointerChain(uintptr_t modBaseAdress, std::vector<unsigned int> offsets);
	static FILE* createConsole();
	static void removeConsole(FILE* file);
	static MODULEINFO getModuleInfo(char* szModule);
	static uintptr_t sigFinder(MODULEINFO game, char* signature, char* mask);
	static void printBytes(uintptr_t address, int length);
	static void nopBytes(uintptr_t* address, int length);
	static void overwriteBytes(uintptr_t* address, char* newBytes, size_t length);
	static void x64Detour(uintptr_t detourAddress, uintptr_t hackAddress, uintptr_t opCodeLength, uintptr_t& jumpBack);

	InternalFunctions() = default;
};
