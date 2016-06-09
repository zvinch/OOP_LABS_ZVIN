#include "myRect.h"

Rect::Rect(int m_leftp, int m_rightp, int m_topp, int m_bottomp, myColor m_color):Shape(m_color) {
	m_left = m_leftp;
	m_right = m_rightp;
	m_top = m_topp;
	m_bottom = m_bottomp;
	normalize();
	std::cout << "Default constructor" << " left right bottom top " << m_left << m_right << m_top << m_bottom <<std::endl;
}

void Rect::normalize()
{
	if ( this->m_left > this->m_right )
	{
		int tmp = this->m_left;
		this->m_left = this->m_right;
		this->m_right = tmp;
	}
	if (this->m_top > this->m_bottom)
	{
		int tmp = this->m_top;
		this->m_top = this->m_bottom;
		this->m_bottom = tmp;
	}
}

void Rect::WhereAmI(){ std::cout << "I'm in Rect" << std::endl; };

void Rect::InflateRect(int infl, int inft, int infr, int infb)
{
	this->m_left -= infl;
	this->m_top -= inft;
	this->m_right += infr;
	this->m_bottom += infb;
	normalize();
}
// 2 pars
void Rect::InflateRect(int dhor, int dver)
{
//	this->m_left -= dhor;
//	this->m_top -= dver;
//	this->m_right += dhor;
//	this->m_bottom += dver;
//	normalize();
	InflateRect(dhor, dver, dhor, dver);
}
void Rect::Inflate(int i)
{
	InflateRect(i, i);
}


double Rect::Area() const
{
	return m_bottom;
}

Rect::operator const Shape*()
{
	return this;
}

Shape * Rect::clone() const 
{
	return new Rect(*this);
}


// Copy
Rect::Rect(const Rect & other):Shape(other){
	m_left = other.m_left;
	m_right = other.m_right;
	m_top = other.m_top;
	m_bottom = other.m_bottom;
	//normalize();
	std::cout << "Copy constructor" << " left right bottom top " << m_left << m_right << m_top << m_bottom << std::endl;
}

// Set All
void Rect::SetAll(int l, int r, int t, int b)
{
	this->m_left = l;
	this->m_top = t;
	this->m_right = r;
	this->m_bottom = b;
	normalize();
}
// Get All
void Rect::GetAll(int* l, int* ri, int* t, int* b) const
{
	*l = this->m_left;
	*t = this->m_top;
	*ri = this->m_right;
	*b = this->m_bottom;
	
}

// Bounding Rects
Rect Rect::BoundingRect(const Rect & other)
{
	int ret_l, ret_t, ret_r, ret_b;
	ret_t =(this->m_top < other.m_top) ?  this->m_top : other.m_top;
	ret_l = (this->m_left < other.m_left) ? this->m_left : other.m_left;
	ret_r = (this->m_right < other.m_right) ? other.m_right :  this->m_right;
	ret_b = (this->m_bottom < other.m_bottom) ? other.m_bottom :  this->m_bottom;
	//Rect bound(ret_l, ret_r, ret_t, ret_b);
	return  Rect (ret_l, ret_r, ret_t, ret_b);
}

Rect Rect::BoundingRect(Rect r, Rect rr)
{
	return Rect();
}

std::ostream & operator<<(std::ostream & ostr, const Rect & mRect)
{
	ostr <<"left = "<< mRect.m_left << ' ' <<"right = "<< mRect.m_right << ' ' <<"top = "<< mRect.m_top << ' ' <<"bottom = " << mRect.m_bottom <<" Area = " << mRect.Area();
	return ostr;
}

std::ofstream & operator<<(std::ofstream & ostr, const Rect & mRect)
{
	//ostr << mRect.m_left << ' ' << mRect.m_right << ' ' << mRect.m_top << ' ' << mRect.m_bottom << ' ' << mRect.Area();
	return ostr;
}

Rect BoundingRect(Rect first, Rect second)
{
	int ret_l, ret_t, ret_r, ret_b;
	int lf, tf, rf, bf;
	int ls, ts, rs, bs;
	first.GetAll(&lf, &rf, &tf, &bf);
	second.GetAll(&ls, &rs, &ts, &bs);
	ret_t = (tf < ts ) ?  tf: ts ;
	ret_l = (lf < ls) ? lf : ls;
	ret_r = (rf < rs) ? rs : rf;
	ret_b = (bf < bs) ? bs : bf;
	
	return  Rect(ret_l, ret_r, ret_t, ret_b);
}
// 2
Rect BoundingRect2(const Rect & first, const Rect & second)
{
	int ret_l, ret_t, ret_r, ret_b;
	int lf, tf, rf, bf;
	int ls, ts, rs, bs;
	first.GetAll(&lf, &rf, &tf, &bf); // const object const method
	second.GetAll(&ls, &rs, &ts, &bs);
	ret_t = (tf < ts) ? tf : ts;
	ret_l = (lf < ls) ? lf : ls;
	ret_r = (rf < rs) ? rs : rf;
	ret_b = (bf < bs) ? bs : bf;
	return  Rect(ret_l, ret_r, ret_t, ret_b);
}

Rect::~Rect()
{
	//std::wcout << "Rect destructor" << std::endl;
	//stop
}

Point Rect::closestToZero() const
{
	if (sqrt(m_left*m_left + m_top*m_top))
	{
		return Point(m_left, m_top);
	}
	if (sqrt(m_right*m_right + m_bottom*m_bottom))
	{
		return Point(m_right, m_bottom);
	}
}
