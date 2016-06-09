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

int Point::operator==(const Point & other)
{
	if ((this->m_x == other.m_x) && (this->m_y == other.m_y))
	{
		return 1;
	}
	else
	{
		return 0;
	}
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



Point Point::operator+(const Point & other)
{
	return Point(this->m_x + other.m_x, this->m_y += other.m_y);
}

Point Point::operator+(double inc)
{
	return Point(this->m_x + inc, this->m_y + inc);
}

Point operator-(Point & other1, const Point& other2)
{
	return Point(other1.m_x - other2.m_x, other1.m_y - other2.m_y);

}
Point operator-(Point & other1, double inc)
{
	return Point(other1.m_x - inc, other1.m_y - inc);
}

Point operator+( double inc, Point & other1)
{
	return Point(other1.m_x + inc, other1.m_y + inc);
}

Point Point::operator+()
{
	return *this;

}
Point Point::operator-()
{
	return Point(-this->m_x,-this->m_y);
}
Point::~Point()
{
}

Point::Point(const Point& other)
{
	this->m_x = other.m_x;
	this->m_y = other.m_y;
}
std::ostream& operator<<(std::ostream& ostr, const Point& mPoint)
{
	ostr << "x = " << mPoint.m_x<<" "<<"y = " << mPoint.m_y;
	return ostr;
}

std::ofstream& operator<<(std::ofstream& ostr, const Point& mPoint)
{
	ostr <<  mPoint.m_x << " " << mPoint.m_y;
	return ostr;
}