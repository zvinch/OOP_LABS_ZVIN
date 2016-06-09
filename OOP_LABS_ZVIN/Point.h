#pragma once
class Point
{
	double m_x;
	double m_y;
public:
	Point();

	Point(double x, double y);

	Point & operator+=(const Point & other);
	Point & operator+=(double inc);
	friend Point & operator-=( Point & other1, const Point& other2);
	friend Point & operator-=(Point & other1, double inc);

	~Point();
};

