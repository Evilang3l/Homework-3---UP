#include "Shape.h"
#include "Dot.h"
#include "Pyramid.h"
#include "Sphere.h"
#include "Cuboid.h"
#include "ShapeType.h"
#include <fstream>
#include "DynamicChar.h"
#include <string>

Shape** shapes = nullptr;
Dot vec;
float scaleCoef;
unsigned linesC = 0, currentC = 0;
bool isReadingGroup = false;
unsigned short currGroupIndex = 1;

void parseLine(char*);
void assShape(Shape);
void makeSphere(char*);
void makeCuboid(char*);
void makePyramid(char*);
void makeGroup(char*);
void printIndex(const unsigned short);
void printPoint(const char*);

using namespace std;
using namespace function;
int main()
{
	string line;
	ifstream file;
	file.open("file.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			linesC++;
		}

		shapes = new Shape*[linesC + 1];

		file.close();
	}

	file.open("file.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			char* str = nullptr;
			str = new (nothrow) char[line.length() + 1];
			for (unsigned i = 0; i < line.length(); i++)
			{
				str[i] = line[i];
			}
			str[line.length()] = '\0';
			parseLine(str);
			currentC++;
			delete[] str;
		}
		file.close();
	}
	else
	{
		cout << "There is no such file with that name!" << endl;
	}

	unsigned short ind = 0;

	cout << "Input shape index: ";
	cin >> ind;

	printIndex(ind);

	char* pointStr = new (nothrow) char[512];
	cout << "Input point x, y, z: ";
	cin.ignore();
	cin.getline(pointStr, 512);
	printPoint(pointStr);
	delete[] pointStr;

	return 0;
}

void parseLine(char* s)
{
	if (s[0] == 's')
	{
		makeSphere(s);
	}
	if (s[0] == 'c')
	{
		makeCuboid(s);
	}
	if (s[0] == 'p')
	{
		makePyramid(s);
	}
	if (s[0] == 'g')
	{
		if (!isReadingGroup)
		{
			currentC--;
			makeGroup(s);
		}
		else
		{
			currentC--;
			currGroupIndex++;
			isReadingGroup = false;
		}
	}
}

void makeSphere(char* s)
{
	DynamicChar strX, strY, strZ, strR;
	unsigned short c = 0;
	for (unsigned i = 7; i < strlen(s) + 1; i++)
	{
		if (s[i] != ' ' && c == 0)
		{
			strX += s[i];
		}
		else
		{
			if (c == 0)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 1)
		{
			strY += s[i];
		}
		else
		{
			if (c == 1)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 2)
		{
			strZ += s[i];
		}
		else
		{
			if (c == 2)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 3)
		{
			strR += s[i];
		}
	}

	float x = atof(strX.getChar());
	float y = atof(strY.getChar());
	float z = atof(strZ.getChar());
	float r = atof(strR.getChar());

	Shape* sph = new Sphere(Dot(x, y, z), r);
	shapes[currentC] = sph;
	if (isReadingGroup)
	{
		sph->setGroup(true);
		sph->setGroupIndex(currGroupIndex);
		sph->scale(vec, scaleCoef);
	}

	//shapes[currentC]->printShape();
}

void makeCuboid(char* s)
{
	DynamicChar strX1, strY1, strZ1, strX2, strY2, strZ2;
	unsigned short c = 0;
	for (unsigned i = 7; i < strlen(s) + 1; i++)
	{
		if (s[i] != ' ' && c == 0)
		{
			strX1 += s[i];
		}
		else
		{
			if (c == 0)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 1)
		{
			strY1 += s[i];
		}
		else
		{
			if (c == 1)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 2)
		{
			strZ1 += s[i];
		}
		else
		{
			if (c == 2)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 3)
		{
			strX2 += s[i];
		}
		else
		{
			if (c == 3)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 4)
		{
			strY2 += s[i];
		}
		else
		{
			if (c == 4)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 5)
		{
			strZ2 += s[i];
		}
		else
		{
			if (c == 5)
			{
				c++;
				continue;
			}

		}
	}

	float x1 = atof(strX1.getChar());
	float y1 = atof(strY1.getChar());
	float z1 = atof(strZ1.getChar());
	float x2 = atof(strX2.getChar());
	float y2 = atof(strY2.getChar());
	float z2 = atof(strZ2.getChar());

	Shape* cub = new Cuboid(Dot(x1, y1, z1), Dot(x2, y2, z2));
	shapes[currentC] = cub;

	if (isReadingGroup)
	{
		cub->setGroup(true);
		cub->setGroupIndex(currGroupIndex);
		cub->scale(vec, scaleCoef);
	}

	//shapes[currentC]->printShape();
}

void makePyramid(char* s)
{
	DynamicChar strX1, strY1, strZ1, strX2, strY2, strZ2, strX3, strY3, strZ3, strX4, strY4, strZ4;
	unsigned short c = 0;
	for (unsigned i = 8; i < strlen(s) + 1; i++)
	{
		if (s[i] != ' ' && c == 0)
		{
			strX1 += s[i];
		}
		else
		{
			if (c == 0)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 1)
		{
			strY1 += s[i];
		}
		else
		{
			if (c == 1)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 2)
		{
			strZ1 += s[i];
		}
		else
		{
			if (c == 2)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 3)
		{
			strX2 += s[i];
		}
		else
		{
			if (c == 3)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 4)
		{
			strY2 += s[i];
		}
		else
		{
			if (c == 4)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 5)
		{
			strZ2 += s[i];
		}
		else
		{
			if (c == 5)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 6)
		{
			strX3 += s[i];
		}
		else
		{
			if (c == 6)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 7)
		{
			strY3 += s[i];
		}
		else
		{
			if (c == 7)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 8)
		{
			strZ3 += s[i];
		}
		else
		{
			if (c == 8)
			{
				c++;
				continue;
			}

		}
		if (s[i] != ' ' && c == 9)
		{
			strX4 += s[i];
		}
		else
		{
			if (c == 9)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 10)
		{
			strY4 += s[i];
		}
		else
		{
			if (c == 10)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 11)
		{
			strZ4 += s[i];
		}
		else
		{
			if (c == 11)
			{
				c++;
				continue;
			}

		}
	}

	float x1 = atof(strX1.getChar());
	float y1 = atof(strY1.getChar());
	float z1 = atof(strZ1.getChar());
	float x2 = atof(strX2.getChar());
	float y2 = atof(strY2.getChar());
	float z2 = atof(strZ2.getChar());
	float x3 = atof(strX3.getChar());
	float y3 = atof(strY3.getChar());
	float z3 = atof(strZ3.getChar());
	float x4 = atof(strX4.getChar());
	float y4 = atof(strY4.getChar());
	float z4 = atof(strZ4.getChar());

	Shape* pyr = new Pyramid(Dot(x1, y1, z1), Dot(x2, y2, z2), Dot(x3, y3, z3), Dot(x4, y4, z4));
	shapes[currentC] = pyr;

	if (isReadingGroup)
	{
		pyr->setGroup(true);
		pyr->setGroupIndex(currGroupIndex);
		pyr->scale(vec, scaleCoef);
	}

	//shapes[currentC]->printShape();
}

void makeGroup(char* s)
{
	DynamicChar strX, strY, strZ, strS;
	unsigned short c = 0;
	for (unsigned i = 7; i < strlen(s) + 1; i++)
	{
		if (s[i] != ' ' && c == 0)
		{
			strX += s[i];
		}
		else
		{
			if (c == 0)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 1)
		{
			strY += s[i];
		}
		else
		{
			if (c == 1)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 2)
		{
			strZ += s[i];
		}
		else
		{
			if (c == 2)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 3)
		{
			strS += s[i];
		}
	}

	float x = atof(strX.getChar());
	float y = atof(strY.getChar());
	float z = atof(strZ.getChar());
	float scale = atof(strS.getChar());

	vec = Dot(x, y, z);
	scaleCoef = scale;

	isReadingGroup = true;
}

void printIndex(const unsigned short index)
{
	if (index < currentC)
	{
		if (shapes[index]->getGRoup())
		{
			unsigned short groupI = shapes[index]->getGroupIndex();

			for (size_t i = 0; i < currentC; i++)
			{
				if (groupI == shapes[i]->getGroupIndex())
				{
					shapes[i]->printShape();
				}
			}
		}
		else
		{
			shapes[index]->printShape();
		}
	}
	else
	{
		cout << "No figure with index " << index << endl;
	}
}

void printPoint(const char* s)
{
	DynamicChar strX, strY, strZ;
	unsigned short c = 0;
	for (unsigned i = 0; i < strlen(s) + 1; i++)
	{
		if (s[i] != ' ' && c == 0)
		{
			strX += s[i];
		}
		else
		{
			if (c == 0)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 1)
		{
			strY += s[i];
		}
		else
		{
			if (c == 1)
			{
				c++;
				continue;
			}

		}

		if (s[i] != ' ' && c == 2)
		{
			strZ += s[i];
		}
		else
		{
			if (c == 2)
			{
				c++;
				continue;
			}

		}
	}

	float x = atof(strX.getChar());
	float y = atof(strY.getChar());
	float z = atof(strZ.getChar());

	Dot d = Dot(x, y, z);

	unsigned short index = 0;
	for (size_t i = 0; i < currentC; i++)
	{
		if (shapes[i]->isDotIn(d))
		{
			printIndex(i);
			break;
		}
	}
}