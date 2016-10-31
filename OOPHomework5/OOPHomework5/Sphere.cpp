#include "Sphere.h"

Sphere::Sphere()
	:Shape()
{
	type = sphere;
	center = Dot(0, 0, 0);
	r = 0;
}

Sphere::Sphere(const Dot center, const float r)
	:Shape(sphere)
{
	copyObject(center, r);
}

Sphere::Sphere(const Sphere& other)
	: Shape(other)
{
	copyObject(other.center, other.r);
}

bool Sphere::isDotIn(Dot d)
{
	bool result = false;
	if (r <= fabsf(d.getX() - center.getX()))
	{
		if (r <= fabsf(d.getY() - center.getY()))
		{
			if (r <= fabsf(d.getZ() - center.getZ()))
			{
				result = true;
			}
		}
	}

	return result;
}

Sphere& Sphere::operator=(const Sphere& other)
{
	if (this != &other)
	{
		copyObject(other.center, other.r);
	}

	return *this;
}

void Sphere::scale(Dot vec, float s)
{
	Dot tmpDot = Dot(center.getX()*s + vec.getX(), center.getY()*s + vec.getY(), center.getZ()*s + vec.getZ());
	center = tmpDot;
	r *= s;
}

void Sphere::printShape()
{
	std::cout << function::typeToStr(type) << " ";
	std::cout << center.getX() << " " << center.getY() << " " << center.getZ() << " ";
	std::cout << r;
	std::cout << std::endl;
}

Sphere::~Sphere()
{

}

void Sphere::copyObject(const Dot center, const float r)
{
	this->center = center;
	this->r = r;
}