#include "Soldier.h"

Soldier::Soldier()
{
	name = nullptr;
	years = 0;
	level = 0;
	salary = 0;
}

Soldier::Soldier(const char* name, const unsigned years, const unsigned level, const unsigned salary)
{
	copyObject(name, years, level, salary);
}

Soldier::Soldier(const Soldier& other)
{
	copyObject(other.name, other.years, other.level, other.salary);
}

Soldier& Soldier::operator=(const Soldier& other)
{
	clearObject();
	copyObject(other.name, other.years, other.level, other.salary);
	return *this;
}

Soldier::~Soldier()
{
	clearObject();
}

void Soldier::copyObject(const char* name, const unsigned years, const unsigned level, const unsigned salary)
{
	int tmpSize = strlen(name) + 1;
	this->name = new char[tmpSize];
	strcpy(this->name, name);

	this->years = years;
	this->level = level;
	this->salary = salary;
}

void Soldier::clearObject()
{
	delete[] name;
}