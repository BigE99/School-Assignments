#pragma once
#include <vector>
#include <iostream>
#include "Pen.h"
#include "Instruction.h"

enum ACTION { UP, DOWN, LEFT, RIGHT, PEN_TOGGLE, STOP, PEN_POSITION, NONE };
const unsigned int INIT_DIM = 4, MAX_HORI = 50, MAX_VERTI = 18;

class Canvas
{
private:
	Pen _pen;
	std::vector<std::vector<bool>> _canvas;
	std::vector<Instruction*> _instructions;
	Instruction* _currInstruction = NULL;
	bool growHoriztontal();
	bool growVertical();
	bool processDrawAction(PEN_AXIS, int);
	void stop();
	void mark();

public:
	Canvas();
	void draw(std::ostream&, bool = true);
	unsigned int getWidth();
	unsigned int getHeight();
	unsigned int getPenX();
	unsigned int getPenY();
	bool movePen(PEN_AXIS, bool);
	void togglePen();
	void toggleShowPen();
	bool isPenDown();
	bool doCommand(ACTION);
	std::vector<Instruction*> getInstructions();
};
