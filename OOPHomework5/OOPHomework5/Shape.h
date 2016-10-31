#ifndef SHAPE_HEADER
#define SHAPE_HEADER

#include "ShapeType.h"
#include "Dot.h"
#include <math.h>
#include <iostream>

class Shape
{
protected:
	ShapeType type;

private:
	static unsigned totalShapes;
	unsigned currentShape;
	unsigned short groupIndex;
	bool isGroup;

public:
	Shape();
	Shape(const ShapeType);
	Shape(const Shape&);
	const ShapeType getType();
	const unsigned getTotalShapes();
	const unsigned getCurrShape();
	void setGroup(bool);
	const bool getGRoup();
	void setGroupIndex(const unsigned short);
	const unsigned short getGroupIndex();
	virtual ~Shape();
	virtual bool isDotIn(Dot);
	virtual void scale(Dot, float);
	virtual void printShape();
	virtual Shape& operator=(const Shape&);
};

#endif // !SHAPE_HEADER