#ifndef TEXT_PROCESSOR_HEADER
#define TEXT_PROCESSOR_HEADER

#include "TansformationsEnum.h"

class TextProcessor
{
protected:
	char* text;
	unsigned size;
	char* originalText;
	unsigned originalSize;
	bool transform;

public:
	TextProcessor();
	TextProcessor(const char*);
	TextProcessor(const TextProcessor&);
	TextProcessor& operator+=(const char*);
	char operator [](unsigned);
	virtual void operator-();
	virtual TextProcessor& operator=(const TextProcessor&);
	virtual ~TextProcessor();

protected:
	const unsigned Lenght(const char*);

private:
	void copyObject(const char*, const char*);
	void clearObject();

};

#endif // ! TEXT_PROCESSOR_HEADER