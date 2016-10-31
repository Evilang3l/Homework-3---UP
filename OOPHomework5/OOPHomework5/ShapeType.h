#ifndef SHAPETYPE_HEADER
#define SHAPETYPE_HEADER

#include <string.h>

enum ShapeType
{
	sphere,
	pyramid,
	cuboid,
	noShape
};

namespace function
{
	char* typeToStr(ShapeType);
	ShapeType strToType(char*);
};


#endif // !SHAPETYPE_HEADER