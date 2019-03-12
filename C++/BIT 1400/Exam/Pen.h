#pragma once
enum PEN_AXIS { HORI, VERTI, DEPTH };
const char PEN_STATUS_UP = 'O', PEN_STATUS_DOWN = 'X';
struct Pen
{
public:

	unsigned int _x = 0, _y = 0;
	bool _down = false, _show = true;
};
