#ifndef TRANSFORMATION_HEADER
#define TRANSFORMATION_HEADER

#include "TextProcessor.h"
class Transformation :
	public TextProcessor
{
private:
	char* transformed;
	unsigned transformedSize;

public:
	Transformation();
	Transformation(const char*, TransformationType[4]);
	Transformation(const Transformation&);
	Transformation& operator=(const Transformation&);
	bool operator==(const Transformation&);
	void operator+(const TransformationType);
	friend std::ostream& operator<<(std::ostream& os, const Transformation& dt);
	void operator-();
	char operator()(int);
	const char* getTransformedText();
	~Transformation();

private:
	void copyObject(const char*);
	void clearObject();
	void toCapital();
	void toLower();
	void changeSymbol(const char, const char);
	void changeWord(const char*, const char*);
	void makeTransformation(TransformationType);
	

};

#endif // !TRANSFORMATION_HEADER