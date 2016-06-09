#pragma once
#include "shape.h"
#include "myRect.h"
class Circle :
	public Shape
{
	unsigned int radius;

	double x;
	double y;
public:
	void WhereAmI() override ;
	void Inflate(int i)override;
	Circle(double m_x = 0 , double m_y = 0, unsigned int m_radius =0, myColor m_color = myColor::BLUE);
	Circle(const Rect& someRect);
	~Circle() override;
};

