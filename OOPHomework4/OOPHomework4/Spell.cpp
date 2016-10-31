#include "Spell.h"

Spell::Spell()
{
	description = nullptr;
	type = noSpell;
	cost = 0;
}

Spell::Spell(const char* description, const SpellType type, const unsigned cost)
{
	copyObject(description, type, cost);
}

Spell::Spell(const Spell& other)
{
	copyObject(other.description, other.type, other.cost);
}

Spell& Spell::operator=(const Spell& other)
{
	clearObject();
	copyObject(other.description, other.type, other.cost);

	return *this;
}

Spell::~Spell()
{
	clearObject();
}

void Spell::copyObject(const char* description, const SpellType type, const unsigned cost)
{
	int tmpSize = strlen(description) + 1;
	this->description = new char[tmpSize];
	strcpy(this->description, description);

	this->type = type;
	this->cost = cost;
}

void Spell::clearObject()
{
	delete[] description;
}