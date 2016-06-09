#include "Point.h"


Point::Point()
{
	m_x = 0;
	m_y = 0;
}
Point::Point(double x, double y)
{
	m_x = x;
	m_y = y;
}

Point & Point::operator+=(const Point & other)
{
	this->m_x += other.m_x;
	this->m_y += other.m_y;
	return *this;
}
Point & Point::operator+=(double inc)
{
	this->m_x += inc;
	this->m_y += inc;
	return *this;
}
Point & operator-=(Point & other1, const Point& other2)
{
	other1.m_x -= other2.m_x;
	other1.m_y -= other2.m_y;
	return other1;
}
Point & operator-=(Point & other1, double inc)
{
	other1.m_x -= inc;
	other1.m_y -= inc;
	return other1;
}

Point::~Point()
{
}
