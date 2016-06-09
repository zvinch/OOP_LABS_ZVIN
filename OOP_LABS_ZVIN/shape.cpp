#include "shape.h"

Shape::Shape(myColor m_color)
{
	color = m_color;
}

Shape::Shape(const Shape& someshape)
{
	this->color = someshape.color;
}

void Shape::WhereAmI()
{ 
	std::cout << "I'm in Shape" << std::endl; };

void Shape::SetColor(myColor m_color)
{
	color = m_color;
}
Shape::~Shape()
{
	//std::cout << "Shape destructor" << std::endl;
}