#pragma once
#include <iostream>
#include <fstream>

class Point
{
	double m_x;
	double m_y;
public:
	Point();
	Point(const Point& other);
	Point(double x, double y);

	Point & operator+=(const Point & other);
	Point & operator+=(double inc);
	friend Point & operator-=( Point & other1, const Point& other2);
	friend Point & operator-=(Point & other1, double inc);
	int operator==(const Point & other);
	Point  operator+(const Point & other);
	Point  operator+(double inc);
	friend Point operator-(Point & other1, const Point& other2);
	friend Point operator-(Point & other1, double inc);
	friend Point operator+(double inc, Point & other1 );
	Point operator+();
	Point operator-();
	friend bool operator<(const Point& lhs, const Point& rhs);
	friend std::ofstream& operator<<(std::ofstream& ostr,const Point& mPoint);
	friend std::ostream& operator<<(std::ostream& ostr,const Point& mPoint);
	~Point();
};

