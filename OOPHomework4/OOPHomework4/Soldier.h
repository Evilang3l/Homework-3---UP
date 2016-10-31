#ifndef SOLDIER_HEADER
#define SOLDIER_HEADER

#include "string.h"
class Soldier
{
private:
	char* name;
	unsigned years;
	unsigned level;
	unsigned salary;

	void copyObject(const char*, const unsigned, const unsigned, const unsigned);
	void clearObject();
public:
	Soldier();
	Soldier(const char*, const unsigned, const unsigned, const unsigned);
	Soldier(const Soldier&);
	Soldier& operator= (const Soldier&);
	~Soldier();
};

#endif //!SOLDIER_HEADER