#include "Transformation.h"

Transformation::Transformation()
	:TextProcessor()
{
	transformed = nullptr;
	transformedSize = 0;
}

Transformation::Transformation(const char* text, TransformationType transformations[4])
	:TextProcessor(text)
{
	copyObject(text);

	for (size_t i = 0; i < 4; i++)
	{
		makeTransformation(transformations[i]);
	}
}

Transformation::Transformation(const Transformation& other)
	:TextProcessor(other)
{
	if (this != &other)
	{
		copyObject(other.transformed);
	}
}

const char* Transformation::getTransformedText()
{
	return transformed;
}

std::ostream& operator<<(std::ostream& out, Transformation& trans)
{
	
	out << trans.getTransformedText();

	return out;
}

Transformation& Transformation::operator=(const Transformation& other)
{
	TextProcessor::operator=(other);
	if (this != & other)
	{
		copyObject(other.transformed);
	}

	return *this;
}

char Transformation::operator()(int index)
{
	if (index > transformedSize)
	{
		std::cout << "No such index" << std::endl;
	}
	else
	{
		return transformed[index];
	}
}

bool Transformation::operator==(const Transformation& other)
{
	bool result = true;
	if (other.transformedSize != this->transformedSize)
	{
		result = false;
	}
	else
	{
		for (size_t i = 0; i < this->transformedSize; i++)
		{
			if (other.transformed[i] != this->transformed[i])
			{
				result = false;
				break;
			}
		}
	}

	return result;
}

void Transformation::operator-()
{
	if (transform)
	{
		std::cout << originalText << std::endl;
	}
	else
	{
		std::cout << transformed << std::endl;
	}
}

void Transformation::operator+(const TransformationType type)
{
	makeTransformation(type);
}

Transformation::~Transformation()
{
	clearObject();
}

void Transformation::clearObject()
{
	delete[] transformed;
}

void Transformation::copyObject(const char* transformed)
{
	transformedSize = Lenght(transformed) + 1;
	this->transformed = new char[transformedSize];

	for (size_t i = 0; i < transformedSize; i++)
	{
		this->transformed[i] = transformed[i];
	}

	this->transformed[transformedSize - 1] = '\0';
}

void Transformation::makeTransformation(TransformationType type)
{
	switch (type)
	{
	case Capital: toCapital();
		break;
	case Lower: toLower();
		break;
	case Symbol:
	{
		char symbol, change;
		std::cout << "What symbol do you want to change? ";
		std::cin >> symbol;
		std::cout << "With which symbol do you want to change it? ";
		std::cin >> change;
		changeSymbol(symbol, change);
	}
		break;
	case Word:
	{
		char* word = new char[size];
		char* change = new char[512];
		std::cout << "What word do you want to change? ";
		std::cin.getline(word, size);
		std::cout << "With which word do you want to change it? ";
		std::cin.getline(change, 512);

		changeWord(word, change);
	}
		break;
	default:
		break;
	}
}

void Transformation::toCapital()
{
	for (size_t i = 0; i < transformedSize; i++)
	{		
		if ((int)transformed[i] >= 97 && (int)transformed[i] <= 122)
		{
			transformed[i] = (char)((int)transformed[i] - 32);
		}
	}
}

void Transformation::toLower()
{
	for (size_t i = 0; i < transformedSize; i++)
	{
		if ((int)transformed[i] >= 65 && (int)transformed[i] <= 90)
		{
			transformed[i] = (char)((int)transformed[i] + 32);
		}
	}
}

void Transformation::changeSymbol(const char what, const char with)
{
	for (size_t i = 0; i < transformedSize; i++)
	{
		if (transformed[i] == what)
		{
			transformed[i] = with;
		}
	}
}

void Transformation::changeWord(const char* what, const char* with)
{
	unsigned counter = 0;
	while(transformed[counter] != '\0')
	{
		if (transformed[counter] == what[0])
		{
			bool isFound = true;
			for (size_t j = 0; j < Lenght(what); j++)
			{
				if (transformed[counter + j] != what[j])
				{
					isFound = false;
					break;
				}
			}

			if (isFound)
			{
				unsigned newSize = 0;
				Lenght(what) > Lenght(with) ? newSize = transformedSize - (Lenght(what) - Lenght(with)) : newSize = transformedSize + (Lenght(with) - Lenght(what));

				char* tmp = new char[newSize + 1];

				for (size_t i = 0; i < newSize + 1; i++)
				{
					if (i < counter)
					{
						tmp[i] = transformed[i];
					}
					else if (i >= counter && i < counter + Lenght(with))
					{
						tmp[i] = with[i - counter];
					}
					else
					{
						int mark = 0;
						mark = Lenght(what) - Lenght(with);
						tmp[i] = transformed[i + mark];
					}
				}
			}
		}
		counter++;
	}
}