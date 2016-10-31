#include "Dot.h"

Dot::Dot()
{
	x = 0;
	y = 0;
	z = 0;
}

Dot::Dot(const float x, const float y, const float z)
{
	copyObject(x, y, z);
}

Dot::Dot(const Dot& other)
{
	copyObject(other.x, other.y, other.z);
}

Dot& Dot::operator=(const Dot& other)
{
	copyObject(other.x, other.y, other.z);
	return *this;
}

void Dot::copyObject(const float x, const float y, const float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Dot::~Dot()
{
}
