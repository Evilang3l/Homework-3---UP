#include "MagicPage.h"

MagicPage::MagicPage()
	:Spell()
{
	spells = nullptr;
	size = 0;
}

MagicPage::MagicPage(const Spell* spells, const unsigned size, const char* description, const SpellType type, const unsigned cost)
	:Spell(description, type, cost)
{
	copyObject(spells, size);
}

MagicPage::MagicPage(const MagicPage& other)
	:Spell(other)
{
	copyObject(other.spells, other.size);
}

MagicPage& MagicPage::operator=(const MagicPage& other)
{
	clearObject();
	copyObject(other.spells, other.size);

	return *this;
}

void MagicPage::addSpell(const Spell& spell)
{
	size++;
	Spell* tmpSpells = new Spell[size + 1];
	for (int i = 0; i < size - 1; i++)
	{
		tmpSpells[i] = spells[i];
	}
	tmpSpells[size] = spell;

	clearObject();

	spells = tmpSpells;
	tmpSpells = nullptr;
	delete[] tmpSpells;
}

MagicPage::~MagicPage()
{
	clearObject();
}

void MagicPage::copyObject(const Spell* spells, const unsigned size)
{
	this->size = size;
	this->spells = new Spell[size + 1];

	for (int i = 0; i < size + 1; i++)
	{
		this->spells[i] = spells[i];
	}
}

void MagicPage::clearObject()
{
	delete[] spells;
}