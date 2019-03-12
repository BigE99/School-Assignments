#include "Canvas.h"

bool Canvas::growHoriztontal()
{
	if (getWidth() < MAX_HORI) {
		for (unsigned int i = 0; i < getHeight(); i++) {
			_canvas[i].push_back(false);
		}
		return true;
	}
	return false;
}

bool Canvas::growVertical()
{
	if (getHeight() != MAX_VERTI) {
		_canvas.push_back(std::vector<bool>(getWidth(), false));
		return true;
	}
	return false;
}

bool Canvas::processDrawAction(PEN_AXIS plane, int extent)
{
	if (plane == DEPTH) {
		if (_currInstruction != NULL) {
			_instructions.push_back(_currInstruction);
		}
		if (extent == 1) {
			_instructions.push_back((new Instruction(SET, _pen._x, _pen._y)));
		}
	}
	else if (isPenDown()) {
		INSTRUCTION newInstruction = plane == HORI ? DRH : DRV;
		if (_currInstruction != NULL) {
			if (_currInstruction->cmd == newInstruction) {
				_currInstruction->arg1 += extent;
			}
			else {
				_instructions.push_back(_currInstruction);
				_currInstruction = new Instruction(newInstruction, extent);
			}
		}
		else {
			_currInstruction = new Instruction(newInstruction, extent);
		}
		return true;
	}
	return false;
}

void Canvas::stop()
{
	if (_currInstruction != NULL) {
		_instructions.push_back(_currInstruction);
		_currInstruction = NULL;
	}
}

void Canvas::mark()
{
	if (isPenDown())
	{
		_canvas[_pen._y][_pen._x] = true;
	}
}

Canvas::Canvas()
{
	for (unsigned int i = 0; i < INIT_DIM; i++) {
		_canvas.push_back(std::vector<bool>(INIT_DIM, false));
	}
}

void Canvas::draw(std::ostream & sout, bool showDetails)
{
	if (showDetails) {
		sout << "Pen Position: " << _pen._x << "," << _pen._y << std::endl;
		sout << "Image Size:" << getWidth() << "," << getHeight() << std::endl;
	}

	for (unsigned int y = 0; y < getHeight(); y++) {
		for (unsigned int x = 0; x < getWidth(); x++) {
			if (_pen._show && _pen._x == x && _pen._y == y) {
				sout << (_pen._down ? PEN_STATUS_DOWN : PEN_STATUS_UP);
			}
			else {
				sout << (_canvas[y][x] ? '*' : ' ');
			}
		}
		sout << std::endl;
	}
}

unsigned int Canvas::getWidth()
{
	return _canvas[0].size();
}

unsigned int Canvas::getHeight()
{
	return _canvas.size();
}

unsigned int Canvas::getPenX()
{
	return _pen._x;
}

unsigned int Canvas::getPenY()
{
	return _pen._y;
}

bool Canvas::movePen(PEN_AXIS pa, bool positive)
{
	mark();
	if (pa == HORI) {
		if (positive) {
			if (_pen._x + 1 == getWidth())
			{
				if (!growHoriztontal()) {
					return false;
				}
			}
			_pen._x++;
			processDrawAction(pa, 1);
			return true;
		}
		else {
			if (_pen._x <= 0) {
				return false;
			}
			_pen._x--;
			processDrawAction(pa, -1);
			return true;
		}
	}
	else {
		if (positive) {
			if (_pen._y + 1 == getHeight())
			{
				if (!growVertical()) {
					return false;
				}
			}
			_pen._y++;
			processDrawAction(pa, 1);
			return true;
		}
		else {
			if (_pen._y <= 0) {
				return false;
			}
			_pen._y--;
			processDrawAction(pa, -1);
			return true;
		}
	}

	return false;
}

void Canvas::togglePen()
{
	processDrawAction(DEPTH, _pen._down ? -1 : 1);
	_pen._down = !_pen._down;
}

void Canvas::toggleShowPen()
{
	_pen._show = !_pen._show;
}

bool Canvas::isPenDown()
{
	return _pen._down;
}

bool Canvas::doCommand(ACTION a)
{
	switch (a) {
	case LEFT:
		movePen(HORI, false);
		break;
	case RIGHT:
		movePen(HORI, true);
		break;
	case DOWN:
		movePen(VERTI, true);
		break;
	case UP:
		movePen(VERTI, false);
		break;
	case PEN_TOGGLE:
		togglePen();
		break;
	case PEN_POSITION:
		toggleShowPen();
		break;
	case STOP:
		stop();
		break;
	}

	return false;
}

std::vector<Instruction*> Canvas::getInstructions()
{
	return _instructions;
}