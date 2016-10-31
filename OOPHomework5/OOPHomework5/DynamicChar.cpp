#include "DynamicChar.h"
#include <iostream>

DynamicChar::DynamicChar()
{
	pArr = nullptr;
	size = 0;
}

DynamicChar::~DynamicChar()
{
	delete[] pArr;
}

DynamicChar& DynamicChar::operator=(const char* otherArr)
{
	if (strcmp(pArr, otherArr))
	{
		delete[] pArr;
		size = 0;
		char* tmpArr = new char[strlen(otherArr) + 1];
		strcpy(pArr, otherArr);
		size = strlen(otherArr) + 1;
	}

	return *this;
}

DynamicChar& DynamicChar::operator+=(const char* otherArr)
{
	appendCharSeq(otherArr);

	return *this;
}

DynamicChar& DynamicChar::operator+=(const int num)
{
	char* numArr = new (nothrow) char[32];
	sprintf(numArr, "%d", num);
	appendCharSeq(numArr);
	delete[] numArr;

	return *this;
}

DynamicChar& DynamicChar::operator+=(const float num)
{
	char* numArr = new (nothrow) char[32];
	sprintf(numArr, "%.2f", num);
	appendCharSeq(numArr);
	delete[] numArr;

	return *this;
}

DynamicChar& DynamicChar::operator+=(const char other)
{
	int newSize = 0;
	newSize = size + 2;

	char* tmpArr = new char[newSize];

	for (int i = 0; i < size; i++)
	{
		tmpArr[i] = pArr[i];
	}

	tmpArr[newSize - 2] = other;

	tmpArr[newSize - 1] = '\0';
	size = strlen(tmpArr);
	pArr = tmpArr;
	tmpArr = nullptr;

	return *this;
}

int DynamicChar::getSize()
{
	return size;
}

char* DynamicChar::getChar() const
{
	return pArr;
}

void DynamicChar::appendCharSeq(const char* otherArr)
{
	int newSize = 0;
	newSize = size + strlen(otherArr) + 1;

	char* tmpArr = new char[newSize];

	for (int i = 0; i < size; i++)
	{
		tmpArr[i] = pArr[i];
	}

	for (int i = size; i < newSize - 1; i++)
	{
		tmpArr[i] = otherArr[i - size];
	}

	tmpArr[newSize - 1] = '\0';
	size = strlen(tmpArr);
	pArr = tmpArr;
	tmpArr = nullptr;
}