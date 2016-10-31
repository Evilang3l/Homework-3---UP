#include "MagicBook.h"

MagicBook::MagicBook()
{
	pages = nullptr;
	size = 0;
}

MagicBook::MagicBook(const MagicPage* pages, const unsigned size)
{
	copyObject(pages, size);
}

MagicBook::MagicBook(const MagicBook& other)
{
	copyObject(other.pages, other.size);
}

MagicBook::~MagicBook()
{
	clearObject();
}

void MagicBook::addSpell(const Spell& spell)
{
	pages[size].addSpell(spell);

	size++;
	MagicPage* tmpPages = new MagicPage[size + 1];

	for (int i = 0; i < size; i++)
	{
		tmpPages[i] = pages[i];
	}

	clearObject();

	pages = tmpPages;
	tmpPages = nullptr;
	delete[] tmpPages;
}

void MagicBook::copyObject(const MagicPage* pages, const unsigned size)
{
	this->pages = new MagicPage[size + 1];

	for (int i = 0; i < size + 1; i++)
	{
		this->pages[i] = pages[i];
	}

	this->size = size;
}

void MagicBook::clearObject()
{
	delete[] pages;
}