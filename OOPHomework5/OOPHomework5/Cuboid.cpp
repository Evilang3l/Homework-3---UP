#include "Cuboid.h"

Cuboid::Cuboid()
	:Shape()
{
	type = cuboid;
	a1 = Dot(0, 0, 0);
	b1 = Dot(0, 0, 0);
}

Cuboid::Cuboid(const Dot a1, const Dot b1)
	:Shape(cuboid)
{
	copyObject(a1, b1);
}

Cuboid::Cuboid(const Cuboid& other)
	: Shape(other)
{
	copyObject(other.a1, other.b1);
}

void Cuboid::copyObject(const Dot a1, const Dot b1)
{
	this->a1 = a1;
	this->b1 = b1;
}

bool Cuboid::isDotIn(Dot d)
{
	bool result = false;
	if (d.getX() >= a1.getX() && d.getX() <= b1.getX())
	{
		if (d.getY() >= a1.getY() && d.getY() <= b1.getY())
		{
			if (d.getZ() >= a1.getZ() && d.getZ() <= b1.getZ())
			{
				result = true;
			}
		}
	}

	return result;
}

void Cuboid::scale(Dot vec, float s)
{
	Dot tmpDot;
	tmpDot = Dot(a1.getX()*s + vec.getX(), a1.getY()*s + vec.getY(), a1.getZ()*s + vec.getZ());
	a1 = tmpDot;
	tmpDot = Dot(b1.getX()*s + vec.getX(), b1.getY()*s + vec.getY(), b1.getZ()*s + vec.getZ());
	b1 = tmpDot;
}

void Cuboid::printShape()
{
	std::cout << function::typeToStr(type) << " ";
	std::cout << a1.getX() << " " << a1.getY() << " " << a1.getZ() << " ";
	std::cout << b1.getX() << " " << b1.getY() << " " << b1.getZ();
	std::cout << std::endl;
}

Cuboid::~Cuboid()
{
}