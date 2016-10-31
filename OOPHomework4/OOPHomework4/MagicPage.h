#ifndef MAGICPAGE_HEADER
#define MAGICPAGE_HEADER

#include "Spell.h"
class MagicPage :
	public Spell
{
private:
	Spell* spells;
	unsigned size;

	void copyObject(const Spell*, const unsigned);
	void clearObject();
public:
	MagicPage();
	MagicPage(const Spell*, const unsigned, const char*, const SpellType, const unsigned);
	MagicPage(const MagicPage&);
	MagicPage& operator=(const MagicPage&);
	~MagicPage();
	virtual void addSpell(const Spell&);
};

#endif // !MAGICPAGE_HEADER
