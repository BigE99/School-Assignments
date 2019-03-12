#include "Instruction.h"

Instruction::Instruction(INSTRUCTION cmd, int arg1)
{
	this->cmd = cmd;
	this->arg1 = arg1;
	this->numArg = 1;
}

Instruction::Instruction(INSTRUCTION cmd, unsigned int arg1, unsigned int arg2)
{
	this->cmd = cmd;
	this->arg1 = static_cast<int>(arg1);
	this->arg2 = static_cast<int>(arg2);
	this->numArg = 2;
}

std::string Instruction::ToString()
{
	std::string r;
	switch (cmd)
	{
	case SET:
		r = "SET ";
		break;
	case DRV:
		r = "DRV ";
		break;
	case DRH:
		r = "DRH ";
		break;
	}

	r += std::to_string(arg1);
	if (numArg == 2) {
		r += " " + std::to_string(arg2);
	}
	return r;
}

instruction::instruction()
{
}


instruction::~instruction()
{
}
