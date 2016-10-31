#ifndef SPHERE_HEADER
#define SPHERE_HEADER

#include "Shape.h"
#include "Dot.h"

class Sphere :
	public Shape, public Dot
{
private:
	Dot center;
	float r;

	void copyObject(const Dot, const float);

public:
	Sphere();
	Sphere(const Dot, const float);
	Sphere(const Sphere&);
	~Sphere();
	bool isDotIn(Dot);
	void scale(Dot, float);
	void printShape();
	Sphere& operator=(const Sphere&);
};

#endif // !SPHERE_HEADER