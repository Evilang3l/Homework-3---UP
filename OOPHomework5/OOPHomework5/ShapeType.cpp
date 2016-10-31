#include "ShapeType.h"

char* function::typeToStr(ShapeType type)
{
	switch (type)
	{
	case sphere: return "sphere";
		break;
	case pyramid: return "pyramid";
		break;
	case cuboid: return "cuboid";
		break;
	case noShape: return "There is no shape on this figure!";
		break;
	default:  return "There is no shape on this figure!";
		break;
	}
}

ShapeType function::strToType(char* type)
{
	char* result = nullptr;

	if (!strcmp("sphere", type))
	{
		return sphere;
	}
	else if (!strcmp("pyramid", type))
	{
		return pyramid;
	}
	else if (!strcmp("cuboid", type))
	{
		return cuboid;
	}
	else
	{
		return noShape;
	}
}

