#include "TextProcessor.h"


TextProcessor::TextProcessor()
{
	text = nullptr;
	originalText = nullptr;
	size = 0;
	originalSize = 0;
	transform = false;
}

TextProcessor::TextProcessor(const char* text)
{
	copyObject(text, text);
}

TextProcessor::TextProcessor(const TextProcessor& other)
{
	if (this != &other)
	{
		copyObject(other.text, other.originalText);
	}
}

TextProcessor& TextProcessor::operator=(const TextProcessor& other)
{
	if (this != &other)
	{
		copyObject(other.text, other.originalText);
	}

	return *this;
}

void TextProcessor::operator-()
{
	if (transform)
	{
		transform = false;
	}
	else
	{
		transform = true;
	}
}

char TextProcessor::operator[](unsigned index)
{
	char result;
	if (index > size)
	{
		std::cout << "No such index" << std::endl;
	}
	else
	{
		result = text[index];
	}

	return result;
}

TextProcessor& TextProcessor::operator+=(const char* addition)
{
	int newSize = 0;
	newSize = size + Lenght(addition) + 1;

	char* tmpArr = new char[newSize];

	for (size_t i = 0; i < size; i++)
	{
		tmpArr[i] = text[i];
	}

	for (int i = size; i < newSize - 1; i++)
	{
		tmpArr[i] = addition[i - size];
	}

	tmpArr[newSize - 1] = '\0';
	size = Lenght(tmpArr);
	text = tmpArr;
	tmpArr = nullptr;

	return *this;
}

TextProcessor::~TextProcessor()
{
	clearObject();
}

const unsigned TextProcessor::Lenght(const char* str)
{
	unsigned result = 0;

	while (str[result] != '\0')
	{
		result++;
	}

	return result;
}

void TextProcessor::clearObject()
{
	delete[] text;
	delete[] originalText;
}

void TextProcessor::copyObject(const char* text, const char* originalText)
{
	this->size = Lenght(text);
	this->originalSize = Lenght(originalText);

	this->text = new char[this->size + 1];
	this->originalText = new char[this->originalSize + 1];

	for (size_t i = 0; i < size; i++)
	{
		this->text[i] = text[i];
	}

	this->text[this->size] = '\0';

	for (size_t i = 0; i < originalSize; i++)
	{
		this->originalText[i] = originalText[i];
	}

	this->originalText[this->originalSize] = '\0';
}