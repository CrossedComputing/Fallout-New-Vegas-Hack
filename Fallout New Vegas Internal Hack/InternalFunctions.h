#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <vector>
#include <Psapi.h>


class InternalFunctions {
public:

	/* This method returns the address at the end of a pointer chain.
	* Parameter one is the base address + the offset.
	* Parameter two is a vector containing the offsets
	*/
	static uintptr_t resolvePointerChain(uintptr_t basePlusOffset, std::vector<unsigned int> offsets);

	/* Creates the console for the game hack
	* Beeps on injection
	*/
	static FILE* createConsole();

	/* Deletes the console for the game hack
	* Beeps on ejection
	*/
	static void removeConsole(FILE* file);

	/* Returns a MODULEINFO struct with the process's information
	* First parameter is the process name.
	*	Check your task manager if you're unsure of the process's name.
	*/
	static MODULEINFO getModuleInfo(char* processName);

	/* Returns the address where your signature begins..
	*	This function iterates through the process memory until
	*	it finds the signature. It returns the address where the
	*	signature began. If no signature is found, method returns
	*	0xDEADBEEF.
	*/
	static uintptr_t sigFinder(MODULEINFO game, char* signature, char* mask);

	/* Prints the bytes at an address to the console.
	* First parameter - Address of the bytes
	* Second parameter - the length to read to
	*/
	static void printBytes(uintptr_t address, int length);

	/* Overwrites '0x90' at an address.
	* First parameter - the address to start at.
	* Second parameter - the length of bytes to nop
	*/
	static void nopBytes(uintptr_t* address, int length);

	/* Overwrites bytes at an address with the newBytes.
	* First parameter - Address to start overwriting at.
	* Second parameter - the new bytes to write.
	* Third parameter - the length of bytes to overwrite.
	*/
	static void overwriteBytes(uintptr_t* address, char* newBytes, size_t length);

	/* Installs a detour at detourAddress
	* Parameter one - where to install the detour
	* Parameter two - the address of your assembly method
	* Parameter three - the number of opcodes you need to overwrite to install the detour
	* Parmeter four - jumpBack is the varaible (passed by reference) that is at the end of your assembly function. 
	*	x64Detour calculates where your assembly function needs to jump back to and sets the value of jumpBack.
	*/
	static void x64Detour(uintptr_t detourAddress, uintptr_t hackAddress, uintptr_t opCodeLength, uintptr_t& jumpBack);
};
