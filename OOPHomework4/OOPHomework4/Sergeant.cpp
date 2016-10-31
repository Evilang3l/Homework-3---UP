#include "Sergeant.h"

Sergeant::Sergeant()
	:Soldier()
{
	squadDescr = nullptr;
	squad = nullptr;
	squadSize = 0;
}

Sergeant::Sergeant(const char* squadDescr, const Soldier* squad, const unsigned squadSize, const char* name, const unsigned years, const unsigned level, const unsigned salary)
	:Soldier(name, years, level, salary)
{
	copyObject(squadDescr, squad, squadSize);
}

Sergeant::Sergeant(const Sergeant& other)
	:Soldier(other)
{
	copyObject(other.squadDescr, other.squad, other.squadSize);
}

Sergeant::~Sergeant()
{
	clearObject();
}

void Sergeant::copyObject(const char* squadDescr, const Soldier* squad, const unsigned squadSize)
{
	int tmpSize = strlen(squadDescr) + 1;
	this->squadDescr = new char[tmpSize];
	strcpy(this->squadDescr, squadDescr);

	this->squadSize = squadSize;
	squad = new Soldier[squadSize + 1];

	for (int i = 0; i < squadSize; i++)
	{
		this->squad[i] = squad[i];
	}
}

void Sergeant::clearObject()
{
	delete[] squadDescr;
	delete[] squad;
}