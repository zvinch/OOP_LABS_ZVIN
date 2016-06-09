#include "circle.h"
#define _USE_MATH_DEFINES // for C++
#include <math.h>

Circle::Circle()
{
	radius = 0;
}

Circle::Circle(const Point & o_point, unsigned int o_radius) :center(o_point)
{
	radius = o_radius;
}

//Circle::Circle(const Circle & other) : center(other.center)
//{
//	this->radius = other.radius;
//}
//Circle& Circle::operator=(const Circle & other)
//{
//	delete &center;
//	center = other.center;
//	radius = other.radius;
//
//	return *this;
//}

int Circle::operator==(const Circle & other){
	if (this == &other){
		return 1;
	}
	else
	{
		if ((this->center == other.center) && (this->radius == other.radius))
		{
			return 1;
		}
		return 0;
	}
}

double Circle::area()const
{
	return (double)((this->radius)*(this->radius)*M_PI);
}

Circle::~Circle()
{

}

std::ostream& operator<<(std::ostream& ostr, const Circle& mCircle)
{
	ostr << mCircle.center<< " Area = "<< mCircle.area();
	return ostr;
}
std::ofstream& operator<<(std::ofstream& ostr, const Circle& mCircle)
{
	ostr << mCircle.center<<" "<<mCircle.radius ;
	return ostr;
}