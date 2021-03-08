#pragma once

#define FLAG_SET(A, B) (A = ((A) | (1 << (B - 1))))
#define FLAG_UNSET(A, B) (A = ((A) & ~(1 << (B - 1))))
#define FLAG_GET(A, B) (((A >> (B - 1)) & 0x1))
#define ERROR_CODE -1

int sc_memoryInit();
int sc_memoryGet(int adress, int* value);
int sc_memorySet(int adress, int value);
int sc_memorySave(char* filename);
int sc_memoryLoad(char* filename);
int regInit(void);
void sc_regSet(int reg, int value);
int sc_regGet(int reg);
int sc_commandDecode(int command, int operand, short int& value);
int sc_commandEncode(int command, int operand, short int& value);