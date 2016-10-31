#ifndef DYNAMIC_CHAR_HEADER
#define DYNAMIC_CHAR_HEADER

#include <string.h>

using namespace std;
class DynamicChar
{
public:
	DynamicChar();
	~DynamicChar();
	DynamicChar& operator= (const char*);
	DynamicChar& operator+= (const char*);
	DynamicChar& operator+= (const int);
	DynamicChar& operator+= (const float);
	DynamicChar& operator+= (const char);
	char* getChar() const;
	int getSize();

private:
	void appendCharSeq(const char*);
	char* pArr;
	int size;

};

#endif // !DYNAMIC_CHAR_HEADER