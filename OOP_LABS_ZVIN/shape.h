#include <iostream>
#pragma once
#define stop __asm nop

enum myColor
{
	RED,
	BLUE,
	GREEN
};

class Shape{
protected:
	myColor color;
public:
	Shape(const Shape& someshape);
	virtual void Inflate(int val)=0;
	Shape(myColor m_color = myColor::BLUE);
	virtual void WhereAmI();
	void SetColor(myColor m_color);
	myColor getColor();
	virtual ~Shape();
};

