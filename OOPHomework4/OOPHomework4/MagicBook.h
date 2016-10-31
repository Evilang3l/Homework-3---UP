#ifndef MAGICBOOK_HEADER
#define MAGICBOOK_HEADER

#include "MagicPage.h"
class MagicBook :
	public MagicPage
{
private:
	MagicPage* pages;
	unsigned size;

	void copyObject(const MagicPage*, const unsigned);
	void clearObject();
public:
	MagicBook();
	MagicBook(const MagicPage*, const unsigned);
	MagicBook(const MagicBook&);
	~MagicBook();

	void addSpell(const Spell&);
};

#endif // !MAGICBOOK_HEADER
