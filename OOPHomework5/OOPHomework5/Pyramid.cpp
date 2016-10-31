#include "Pyramid.h"

Pyramid::Pyramid()
	:Shape()
{
	type = pyramid;
	a = Dot(0, 0, 0);
	b = Dot(0, 0, 0);
	c = Dot(0, 0, 0);
	d = Dot(0, 0, 0);
}

Pyramid::Pyramid(const Dot a, const Dot b, const Dot c, const Dot d)
	:Shape(pyramid)
{
	copyObject(a, b, c, d);
}

Pyramid::Pyramid(const Pyramid& other)
	: Shape(other)
{
	copyObject(other.a, other.b, other.c, other.d);
}

bool Pyramid::isDotIn(Dot dot)
{
	float m0[4][4] =
	{
		{ a.getX(), a.getY(), a.getZ(), 1.0f },
		{ b.getX(), b.getY(), b.getZ(), 1.0f },
		{ c.getX(), c.getY(), c.getZ(), 1.0f },
		{ d.getX(), d.getY(), d.getZ(), 1.0f }
	};

	float m1[4][4] =
	{
		{ dot.getX(), dot.getY(), dot.getZ(), 1.0f },
		{ b.getX(), b.getY(), b.getZ(), 1.0f },
		{ c.getX(), c.getY(), c.getZ(), 1.0f },
		{ d.getX(), d.getY(), d.getZ(), 1.0f }
	};

	float m2[4][4] =
	{
		{ a.getX(), a.getY(), a.getZ(), 1.0f },
		{ dot.getX(), dot.getY(), dot.getZ(), 1.0f },
		{ c.getX(), c.getY(), c.getZ(), 1.0f },
		{ d.getX(), d.getY(), d.getZ(), 1.0f }
	};

	float m3[4][4] =
	{
		{ a.getX(), a.getY(), a.getZ(), 1.0f },
		{ b.getX(), b.getY(), b.getZ(), 1.0f },
		{ dot.getX(), dot.getY(), dot.getZ(), 1.0f },
		{ d.getX(), d.getY(), d.getZ(), 1.0f }
	};

	float m4[4][4] =
	{
		{ a.getX(), a.getY(), a.getZ(), 1.0f },
		{ b.getX(), b.getY(), b.getZ(), 1.0f },
		{ c.getX(), c.getY(), c.getZ(), 1.0f },
		{ dot.getX(), dot.getY(), dot.getZ(), 1.0f }
	};

	float d0 = calculateDet(m0);
	float d1 = calculateDet(m1);
	float d2 = calculateDet(m2);
	float d3 = calculateDet(m3);
	float d4 = calculateDet(m4);

	bool result = false;

	if (d0 < 0 && d1 < 0 && d2 < 0 && d3 < 0 && d4 < 0)
	{
		result = true;
	}

	if (d0 >= 0 && d1 >= 0 && d2 >= 0 && d3 >= 0 && d4 >= 0)
	{
		result = true;
	}

	return result;
}

float Pyramid::calculateDet(float m[4][4])
{
	return
		m[0][3] * m[1][2] * m[2][1] * m[3][0] - m[0][2] * m[1][3] * m[2][1] * m[3][0] -
		m[0][3] * m[1][1] * m[2][2] * m[3][0] + m[0][1] * m[1][3] * m[2][2] * m[3][0] +
		m[0][2] * m[1][1] * m[2][3] * m[3][0] - m[0][1] * m[1][2] * m[2][3] * m[3][0] -
		m[0][3] * m[1][2] * m[2][0] * m[3][1] + m[0][2] * m[1][3] * m[2][0] * m[3][1] +
		m[0][3] * m[1][0] * m[2][2] * m[3][1] - m[0][0] * m[1][3] * m[2][2] * m[3][1] -
		m[0][2] * m[1][0] * m[2][3] * m[3][1] + m[0][0] * m[1][2] * m[2][3] * m[3][1] +
		m[0][3] * m[1][1] * m[2][0] * m[3][2] - m[0][1] * m[1][3] * m[2][0] * m[3][2] -
		m[0][3] * m[1][0] * m[2][1] * m[3][2] + m[0][0] * m[1][3] * m[2][1] * m[3][2] +
		m[0][1] * m[1][0] * m[2][3] * m[3][2] - m[0][0] * m[1][1] * m[2][3] * m[3][2] -
		m[0][2] * m[1][1] * m[2][0] * m[3][3] + m[0][1] * m[1][2] * m[2][0] * m[3][3] +
		m[0][2] * m[1][0] * m[2][1] * m[3][3] - m[0][0] * m[1][2] * m[2][1] * m[3][3] -
		m[0][1] * m[1][0] * m[2][2] * m[3][3] + m[0][0] * m[1][1] * m[2][2] * m[3][3];
}

void Pyramid::scale(Dot vec, float s)
{
	Dot tmpDot;
	tmpDot = Dot(a.getX()*s + vec.getX(), a.getY()*s + vec.getY(), a.getZ()*s + vec.getZ());
	a = tmpDot;
	tmpDot = Dot(b.getX()*s + vec.getX(), b.getY()*s + vec.getY(), b.getZ()*s + vec.getZ());
	b = tmpDot;
	tmpDot = Dot(c.getX()*s + vec.getX(), c.getY()*s + vec.getY(), c.getZ()*s + vec.getZ());
	c = tmpDot;
	tmpDot = Dot(d.getX()*s + vec.getX(), d.getY()*s + vec.getY(), d.getZ()*s + vec.getZ());
	d = tmpDot;
}

void Pyramid::printShape()
{
	std::cout << function::typeToStr(type) << " ";
	std::cout << a.getX() << " " << a.getY() << " " << a.getZ() << " ";
	std::cout << b.getX() << " " << b.getY() << " " << b.getZ() << " ";
	std::cout << c.getX() << " " << c.getY() << " " << c.getZ() << " ";
	std::cout << d.getX() << " " << d.getY() << " " << d.getZ();
	std::cout << std::endl;
}

Pyramid::~Pyramid()
{
}

void Pyramid::copyObject(const Dot a, const Dot b, const Dot c, const Dot d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}