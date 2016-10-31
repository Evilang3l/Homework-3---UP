#pragma once
class Dot
{
private:
	float x;
	float y;
	float z;
	void copyObject(const float, const float, const float);

public:
	Dot();
	Dot(const float, const float, const float);
	Dot(const Dot&);
	Dot& operator=(const Dot&);
	~Dot();
	const float getX() { return x; };
	const float getY() { return y; };
	const float getZ() { return z; };
};