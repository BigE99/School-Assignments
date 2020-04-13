#pragma once
#include "string"

class book
{
public:
	book();
	~book();
	void settype();
	bool isover();
	void checkin();
private:
	enum type { Novel, Magazine, Graphic_Novel, Ebook, Textbook};
	bool checkedout = false;
};

void book::checkin(){
	this->checkedout = !this->checkedout;
}