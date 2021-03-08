#include "mySimpleComputer.h"

#include <iostream>
#include <fstream>

#define errorOne 1
#define errorTwo 2
#define errorThree 3
#define errorFour 4
#define errorFive 5

using namespace std;

const int SIZE = 100;
int Arr[SIZE];
int regFlags;
int flag;


int sc_memoryInit() {

	for (int i = 0; i < SIZE; i++) {
		Arr[i] = 0;
	}
	return *Arr;
}

int sc_memorySet(int adress, int value) {
	if (adress >= 0 && adress < SIZE) {
		Arr[adress] = value;
		return 0;
	}
	else {
		cout << "Error! Out of the range of adress!" << endl;
		return 1;
	}
}

int sc_memoryGet(int adress, int* value) {
	if (adress >= 0 && adress < SIZE) {
		*value = Arr[adress];
		return 0;
	}
	else {
		cout << "Error! Out of the range of adress!" << endl;
		return 1;
	}
}

int sc_memorySave(char* filename) {
	ofstream out(filename, ios::binary);
	for (int i = 0; i < SIZE; i++) {
		out.write((char*)&Arr[i], sizeof(Arr[i]));
	}
	out.close();
	return 0;
}

int sc_memoryLoad(char* filename) {
	ifstream in(filename, ios::binary);
	for (int i = 0; i < SIZE; i++) {
		in.read((char*)&Arr[i], sizeof(Arr[i]));
		cout << Arr[i] << " ";
	}
	in.close();
	return 0;
}

int regInit(void) {
	regFlags = 0;
	return regFlags;
}

void sc_regSet(int reg, int value) {
	if (reg > 0 && reg < 5 && (value == 1 || value == 0)) {
		if (value == 1) {
			FLAG_SET(flag, reg);
		}
		else
		{
			FLAG_UNSET(flag, reg);
		}
	}
	else {
		std::cout << "Error " << std::endl;
	}
}

int sc_regGet(int reg) {
	if (reg > 0 && reg < 5) {
		return FLAG_GET(flag, reg);
	}
	std::cout << "Error " << std::endl;
	return -1;
}

int sc_commandEncode(int command, int operand, short int& value) {
	if (command >= 0 && command <= 255 && (operand >= 0 && operand < 100)) {
		short int res = command;
		res = res << 7;
		res = res | operand;
		value = res;
	}
	else {
		std::cout << "\ncommandEncode : incorrect input data" << std::endl;
		sc_regSet(errorFive, 1);
		return ERROR_CODE;
	}
	return 0;
}

int sc_commandDecode(int command, int operand, short int& value) {
	int op, com;
	if ((value >> 14) & 0x1) {
		std::cout << "commandDecode : incorrect input data (sign command)" << std::endl;
		sc_regSet(errorFive, 1);
		return ERROR_CODE;
	}
	op = value & 255;
	if (op > 99 || op < 0) {
		std::cout << "commandDecode : incorrect input data(operand)" << std::endl;
		sc_regSet(errorFive, 1);
		return ERROR_CODE;
	}
	com = (value >> 7) & 255;
	if (com > 255 || com < 0) {
		std::cout << "commandDecode : incorrect input data(command)" << std::endl;
		sc_regSet(errorFive, 1);
		return ERROR_CODE;
	}
	operand = op;
	command = com;
	return 0;
}

