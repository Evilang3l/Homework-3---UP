#ifndef SPELL_HEADER
#define SPELL_HEADER
#include "SpellType.h"
#include "string.h"

class Spell
{
private:
	char* description;
	SpellType type;
	unsigned cost;

	void copyObject(const char*, const SpellType, const unsigned);
	void clearObject();
public:
	Spell();
	Spell(const char*, const SpellType, const unsigned);
	Spell(const Spell&);
	Spell& operator= (const Spell&);
	~Spell();	
};

#endif // !SPELL_HEADER