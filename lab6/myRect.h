#pragma once
#include <iostream>
#include "shape.h"
#define _USE_MATH_DEFINES // for C++
#include <math.h>

#define stop __asm nop
 
class Rect:public Shape{
	

public:
	int m_left, m_right, m_top, m_bottom;
	// �����������
	Rect(int m_leftp = 0, int m_rightp = 0, int m_topp = 0, int m_bottomp = 0, myColor m_color = myColor::BLUE);
	// ���������� 
	void InflateRect(int infl, int inft, int infr, int infb);
	// COPY
	Rect(const Rect & other);
	// inf second
	void InflateRect(int dhor = 1, int dver = 1);
	void Inflate(int i)override;
	void SetAll(int l, int r, int t, int b);
	void WhereAmI() override;
	void GetAll(int* l, int* ri, int* t, int* b) const;
	Rect BoundingRect(const Rect & other);
	Rect BoundingRect(Rect r, Rect rr);
	friend std::ostream& operator<<(std::ostream& ostr, const Rect& mRect);
	friend std::ofstream& operator<<(std::ofstream& ostr, const Rect& mRect);
	double Area() const;
	operator const Shape*();
	Shape * clone()const;
	virtual ~Rect();
	virtual Point closestToZero() const;

private:	
	// ������������
	void normalize();
	
	
};

Rect BoundingRect(Rect first, Rect second);
Rect BoundingRect2(const Rect & first, const Rect & second);
