#include "mySimpleComputer.h"

#include <iostream>

int main() {
	int adress = 2;
	int value = 1;
	short int command = 10, operand = 10;
	short int result;
	char filename[] = "example.bin";
	sc_memoryInit();
	sc_memorySet(adress, value);
	sc_memoryGet(adress, &value);
	sc_memorySave(filename);
	sc_memoryLoad(filename);
	std::cout << std::endl;
	regInit();
	sc_regSet(adress, value);
	std::cout << sc_regGet(value) << std::endl;
	sc_commandEncode(command, operand, result);
	sc_commandDecode(command, operand, result);
	std::cout << result << std::endl;
	return 0;
}