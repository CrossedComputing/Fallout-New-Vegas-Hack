#include "InternalFunctions.h"
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <vector>
#include <Psapi.h>



uintptr_t InternalFunctions::resolvePointerChain(uintptr_t modBaseAdressPlusOffset, std::vector<unsigned int> offsets)
{
	uintptr_t resolvedAddress = modBaseAdressPlusOffset;

	for (size_t i = 0; i < offsets.size(); i++) {
		// Dereference Pointer
		resolvedAddress = *(uintptr_t*)resolvedAddress;
		// Add offset
		resolvedAddress += offsets[i];
	}
	return resolvedAddress;
}

FILE* InternalFunctions::createConsole()
{
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);
	Beep(800, 400);
	return f;
}

void InternalFunctions::removeConsole(FILE* file)
{
	Beep(555, 444);
	fclose(file);
	FreeConsole();
}

MODULEINFO InternalFunctions::getModuleInfo(char* processName)
{
	if (processName == NULL) {
		throw std::invalid_argument("moduleName cannot be null.");
	}

	MODULEINFO moduleInfo = { 0 };
	HMODULE moduleHandle = GetModuleHandle(processName);

	GetModuleInformation(GetCurrentProcess(), moduleHandle, &moduleInfo, sizeof(MODULEINFO));
	return moduleInfo;
}

uintptr_t InternalFunctions::sigFinder(MODULEINFO game, char* signature, char* mask) {
	uintptr_t memoryBase = (uintptr_t)game.EntryPoint;
	int imageSize = game.SizeOfImage;
	bool found = true;

	for (uintptr_t i = 0; i < (imageSize - strlen(mask)); i++) {
		found = true;
		for (uintptr_t j = 0; j < strlen(mask); j++) {
			if (mask[j] != '?' && signature[j] != *(char*)(memoryBase + i + j)) {
				found = false;
				break;
			}
		}
		if (found) {
			return memoryBase + i;
		}
	}
	return 0xDEADC0DE;
}

void InternalFunctions::printBytes(uintptr_t address, int length) {
	std::cout << "[PRINTING BYTES! REMEMBER ENDIAN-NESS!]" << std::endl;
	for (int i = 0; i < length; i++) {
		std::cout << std::hex << "Bytes at address: " << *(int*)(address + i) << std::endl;
	}
}

void InternalFunctions::nopBytes(uintptr_t* address, int length) {
	DWORD oldProtection = 0x1; 
	VirtualProtect(address, length, PAGE_EXECUTE_READWRITE, &oldProtection);
	memset(address, 0x90, length);
	VirtualProtect(address, length, oldProtection, NULL);
}

void InternalFunctions::overwriteBytes(uintptr_t* address, char* newBytes, size_t length) {
	DWORD oldProtection = 0x1;
	VirtualProtect(address, length, PAGE_EXECUTE_READWRITE, &oldProtection);
	memcpy(address, newBytes, length);
	VirtualProtect(address, length, oldProtection, NULL);
}

void InternalFunctions::x64Detour(uintptr_t detourAddress, uintptr_t hackAddress, uintptr_t opCodeLength, uintptr_t& jumpBack) {
	// Create a place for your detour to jump back to to continue execution after your jump.
	jumpBack = detourAddress + opCodeLength;

	// If your jump overwrites 16 bytes, you'll need to nop the last two 
	int bytesToNop = opCodeLength - 14;

	// FF25000000000000 (6 bytes = jmp qword ptr)
	// Last four bytes are for an address to jump to (destinationAddress)
	char jump[14] = { 0xFF, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

	// Overwrite the last 8 bytes of jump with the bytes at the address of hackAddress. (So hackAddress)
	memcpy(jump + 6, &hackAddress, 8);

	// Write the jump to the detourAddress
	overwriteBytes((uintptr_t*)detourAddress, jump, opCodeLength);
	nopBytes((uintptr_t*)(detourAddress + 14), bytesToNop);
}