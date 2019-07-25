#include "Mesh.h"

#define Quad "Quad.obj"

int main()
{
	Mesh mesh;

	mesh.loadMesh(Quad);
	
	system("pause");

}