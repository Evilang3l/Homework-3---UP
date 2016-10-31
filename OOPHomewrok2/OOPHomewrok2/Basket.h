#ifndef BASKET_H
#define BASKET_H

#include "Egg.h"
#include <fstream>
using std::istream;
using std::ostream;

class Basket
{
private:
	char* owner;
	Egg* eggs;
	unsigned size;
	unsigned capacity;

public:
	Basket();
	Basket(const Basket&);
	Basket(const char*, const Egg*, unsigned, unsigned);
	Basket& operator= (const Basket&);
	~Basket();

public:
	void setOwner(const char*);
	const char* getOwner() const;
	void pushEgg(const char*);
	void popEgg(const char*);
	void serializeBasket();
	void deserializeBasket(const char*);
	void reportBasket();

private:
	void copyObject(const char*, const Egg*, unsigned, unsigned);
	void clearObject();
	int eggExists(const Egg);
	void copyEggs(unsigned, unsigned);
	void addEgg(const Egg);
	void removeEgg(const Egg);
	void saveBasket(const Basket&);
	Basket loadBasket(const char*);

};

#endif // !BASKET_H
