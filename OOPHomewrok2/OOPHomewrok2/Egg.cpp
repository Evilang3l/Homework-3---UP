#include "Egg.h"

Egg::Egg()
{
	name = nullptr;
	size = 0;
}

Egg::Egg(const Egg& other)
{
	setName(other.getName());
	size = other.size;
}

Egg::Egg(const char* nameTmp, unsigned sizeTmp)
{
	copyData(nameTmp, sizeTmp);
}

Egg& Egg::operator=(const Egg& other)
{
	if (this != &other)
	{
		clearObject();
		copyData(other.name, other.size);
	}

	return *this;
}

bool Egg::operator==(const Egg& other) const
{
	bool result = false;

	if (!strcmp(name, other.name))
	{
		if (size == other.size)
		{
			return result = true;
		}
	}

	return result;
}

Egg::~Egg()
{
	clearObject();
}

const char* Egg::getName() const
{
	return name;
}

void Egg::setName(const char* nameTmp)
{
	name = nullptr;
	delete[] name;
	int sizeTmp = strlen(nameTmp) + 1;
	name = new (std::nothrow) char[sizeTmp];
	strcpy(name, nameTmp);
	size = sizeTmp;
}

int Egg::getSize() const
{
	return size;
}

void Egg::clearObject()
{
	delete[] name;
}

void Egg::copyData(const char* nameTmp, unsigned sizeTmp)
{
	int sizeOfTmpName = strlen(nameTmp) + 1;
	if (sizeTmp != sizeOfTmpName)
	{
		sizeTmp = sizeOfTmpName;
	}
	name = new (std::nothrow) char[sizeTmp];

	for (unsigned i = 0; i < sizeTmp; i++)
	{
		name[i] = nameTmp[i];
	}

	name[sizeTmp - 1] = '\0';

	size = sizeTmp;
}