#ifndef EGG_H
#define EGG_H

#include <iostream>

class Egg
{
private:
	char* name;
	unsigned size;

public:
	Egg();
	Egg(const Egg&);
	Egg(const char*, unsigned);
	Egg& operator= (const Egg&);
	bool operator== (const Egg&) const;
	~Egg();

public:
	const char* getName() const;
	void setName(const char*);
	int getSize() const;

private:
	void clearObject();
	void copyData(const char*, unsigned);
};

#endif // !EGG_H