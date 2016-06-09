#pragma once
#include <iostream>
#include "Point.h"

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
	virtual double Area()const =0;
	Shape(myColor m_color = myColor::BLUE);
	virtual void WhereAmI();
	virtual Point closestToZero()const = 0;
	void SetColor(myColor m_color) ;
	myColor getColor() const;
	virtual Shape * clone()const = 0;
	static bool areaCompare(const Shape* first, const Shape* second);
	static bool colorCompare(const Shape* first, const Shape* second);
	static bool coordCompare(const Shape* first, const Shape* second);
	virtual ~Shape();
};

