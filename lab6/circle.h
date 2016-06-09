#pragma once
#include "Point.h"
#include "Shape.h"

class Circle:public Shape
{
private:
	Point center;
	unsigned int radius;
public:
	Circle();
	Circle(const Point & o_point, unsigned int o_radius);
	//Circle(const Circle & other) = default;
	//Circle & operator=(const Circle & other) =default;
	int operator==(const Circle & other);
	double Area() const;
	friend std::ostream& operator<<(std::ostream& ostr, const Circle& mCircle);
	friend std::ofstream& operator<<(std::ofstream& ostr, const Circle& mCircle);
	void Inflate(int val);
	Shape * clone()const;
	operator const Shape*();
	virtual Point closestToZero() const;
	virtual ~Circle();
};

