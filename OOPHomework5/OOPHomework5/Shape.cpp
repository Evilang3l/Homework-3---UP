#include "Shape.h"

unsigned Shape::totalShapes = 0;

Shape::Shape()
{
	type = noShape;
	groupIndex = 0;
	currentShape = totalShapes;
	totalShapes++;
	isGroup = false;
}

Shape::Shape(const ShapeType type)
{
	this->type = type;
	currentShape = totalShapes;
	totalShapes++;
	isGroup = false;
}

Shape::Shape(const Shape& other)
{
	type = other.type;
	currentShape = totalShapes;
	totalShapes++;
	isGroup = other.isGroup;
}

bool Shape::isDotIn(Dot d)
{
	return false;
}

void Shape::scale(Dot vec, float s)
{

}

void Shape::printShape()
{

}

void Shape::setGroup(bool gr)
{
	isGroup = gr;
}

const bool Shape::getGRoup()
{
	return isGroup;
}

const unsigned Shape::getTotalShapes()
{
	return totalShapes;
}

const unsigned Shape::getCurrShape()
{
	return currentShape;
}

const ShapeType Shape::getType()
{
	return type;
}

const unsigned short Shape::getGroupIndex()
{
	return groupIndex;
}

void Shape::setGroupIndex(const unsigned short i)
{
	groupIndex = i;
}

Shape& Shape::operator=(const Shape& other)
{
	if (this != &other)
	{
		type = other.type;
		currentShape = totalShapes;
		totalShapes++;
		isGroup = other.isGroup;
	}

	return *this;
}

Shape::~Shape()
{

}