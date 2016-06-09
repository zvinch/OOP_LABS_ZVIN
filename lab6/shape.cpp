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

myColor Shape::getColor()const
{
	return color;
}
bool Shape::areaCompare(const Shape * first, const Shape * second)
{
	return first->Area()<second->Area();
}
bool Shape::colorCompare(const Shape * first, const Shape * second)
{
	return first->getColor() < second->getColor();
}
bool Shape::coordCompare(const Shape * first, const Shape * second)
{
	return first->closestToZero() < second->closestToZero();
}
Shape::~Shape()
{
	//std::cout << "Shape destructor" << std::endl;
}