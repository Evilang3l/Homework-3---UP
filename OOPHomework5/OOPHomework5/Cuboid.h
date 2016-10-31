#pragma once
#include "Shape.h"
#include "Dot.h"

class Cuboid :
	public Shape, public Dot
{
private:
	Dot a1, b1;

	void copyObject(const Dot, const Dot);

public:
	Cuboid();
	Cuboid(const Dot, const Dot);
	Cuboid(const Cuboid&);
	~Cuboid();
	bool isDotIn(Dot);
	void scale(Dot, float);
	void printShape();
};