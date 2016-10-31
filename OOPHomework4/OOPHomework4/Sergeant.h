#ifndef SERGEANT_HEADER
#define SERGEANT_HEADER

#include "Soldier.h"
class Sergeant :
	public Soldier
{
private:
	char* squadDescr;
	Soldier* squad;
	unsigned squadSize;

	void copyObject(const char*, const Soldier*, const unsigned);
	void clearObject();
public:
	Sergeant();
	Sergeant(const char*, const Soldier*, const unsigned, const char*, const unsigned, const unsigned, const unsigned);
	Sergeant(const Sergeant&);
	~Sergeant();
};

#endif // !SERGEANT_HEADER