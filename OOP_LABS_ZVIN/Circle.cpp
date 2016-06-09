#include "Circle.h"


Circle::Circle(const Rect& somerect) :Shape(somerect)
{
	this->x = (somerect.m_right - somerect.m_left) / 2 + somerect.m_left;
	this->y = (somerect.m_top - somerect.m_bottom) / 2 + somerect.m_bottom;
		
	
}



Circle::Circle(double m_x, double m_y, unsigned int m_radius, myColor m_color):Shape(m_color)
{
	x = m_x;
	y = m_y;
	radius = m_radius;
}

Circle::~Circle()
{
	std::cout << "Circle destructor" << std::endl;
}

void Circle::WhereAmI()
{
	//std::cout << "I'm in Circle" << std::endl;
}

void Circle::Inflate(int i)
{
	radius += i;
}