#pragma once

#include <string>

enum INSTRUCTION { SET, DRV, DRH };
struct Instruction
{
public:
	INSTRUCTION cmd;
	int arg1, arg2;
	unsigned int numArg;
	Instruction(INSTRUCTION cmd, int arg1);
	Instruction(INSTRUCTION cmd, unsigned int arg1, unsigned int arg2);
	std::string ToString();
};

class instruction
{
public:
	instruction();
	~instruction();
};
