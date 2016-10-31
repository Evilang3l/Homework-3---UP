#include "TextProcessor.h"
#include "Transformation.h"

using namespace std;

int main()
{
	TextProcessor a = TextProcessor("asd");
	a += "sad";
	-a;
	-a;

	TransformationType arr[4] = { Lower, Capital, Symbol, Word };

	TextProcessor* b = new Transformation("potato tomato apple", arr);
	
	return 0;
}