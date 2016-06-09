#pragma once
#include <iostream>
#include "shape.h"

#define stop __asm nop
 
class Rect:public Shape{
	

public:
	int m_left, m_right, m_top, m_bottom;
	// Конструктор
	Rect(int m_leftp = 0, int m_rightp = 0, int m_topp = 0, int m_bottomp = 0, myColor m_color = myColor::BLUE);
	// Увеличение 
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

	~Rect() override;
	

private:	
	// Нормализатор
	void normalize();
	
	
};

Rect BoundingRect(Rect first, Rect second);
Rect BoundingRect2(const Rect & first, const Rect & second);
