#pragma once
#include "Shape.h"
#include "Dot.h"
class Pyramid :
	public Shape, public Dot
{
private:
	Dot a, b, c, d;

	void copyObject(const Dot, const Dot, const Dot, const Dot);
	float calculateDet(float[4][4]);

public:
	Pyramid();
	Pyramid(const Dot, const Dot, const Dot, const Dot);
	Pyramid(const Pyramid&);
	~Pyramid();
	bool isDotIn(Dot);
	void scale(Dot, float);
	void printShape();

};

