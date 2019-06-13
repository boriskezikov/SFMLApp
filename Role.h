#pragma once
#include <string>
#include "Field.h"

class Role
{
protected:
	std::string file;

	int leftBorder{}, rightBorder{};
public:
	Role() = default;;
	
	virtual int Work(int type) = 0;
	virtual std::string getFile() {return file;};
	void setLeftBorder(int value)  { leftBorder = value; }
	void setRightBorder(int value)  { rightBorder = value; }
	int getLeftBorder()  { return leftBorder; }
	int getRightBorder()  { return rightBorder; }
	virtual ~Role() = default;;
};

