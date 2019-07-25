#pragma once
#include"Base.h"

class Mesh
{	
private:
	std::vector<unsigned int> vertexIndex, uvIndex, normalIndex;
	std::vector<Vertex> vertexs;
public:
	void loadMesh(std::string _path);

	std::vector<unsigned int>* getVertexsIndex() { return &vertexIndex; }
	std::vector<unsigned int>* getUvsIndex() { return &uvIndex; }
	std::vector<unsigned int>* getNormalsIndex() { return &normalIndex; }
	std::vector<Vertex>* getVertexs() { return &vertexs; }

	Mesh();
	~Mesh();
};

