#include "Mesh.h"



void Mesh::loadMesh(std::string _path)
{
	std::fstream meshHandler;

	std::vector<vector3> tempPositions, tempNormals;
	std::vector<vector2> tempUvs;

	meshHandler.open(_path, std::fstream::in);

	if (meshHandler.is_open())
	{
		while (!meshHandler.eof())
		{
			std::string tempLine;
			std::getline(meshHandler, tempLine);

			std::string tipoValor = tempLine.substr(0, tempLine.find(" "));

			if (tipoValor == "v")
			{
				int space = 1, space2;
				vector3 tempVec3;

				for (int i = 0; i < 3; i++)
				{

					space2 = tempLine.find((char)32, space + 1);

					int size = space2 - space;

					std::string val = tempLine.substr(space + 1, size);

					space = space2;

					if (i == 0)
					{
						tempVec3.x = std::stof(val);
					}
					else if (i == 1)
					{
						tempVec3.y = std::stof(val);
					}
					else if (i == 2)
					{
						tempVec3.z = std::stof(val);
					}
				}

				tempPositions.push_back(tempVec3);
			}
			else if (tipoValor == "f")
			{
				int space = 1, space2;

				unsigned int indexPositions;
				unsigned int indexUvs;
				unsigned int indexNormals;

				for (int i = 0; i < 3; i++)
				{
					space2 = tempLine.find(" ", space + 1);

					int size = space2 - space;

					std::string values = tempLine.substr(space + 1, size);

					space = space2;

					int slash = 0, slash2;

					for (int j = 0; j < 3; j++)
					{
						slash2 = values.find("/", slash + 1);

						int size = slash2 - slash;

						std::string valueF = values.substr(slash, size);

						slash = slash2 + 1;

						if (j == 0)
						{
							float a = std::stof(valueF);
							indexPositions = a;
							vertexIndex.push_back(indexPositions);
							std::cout << "position value: " << indexPositions << std::endl;
						}
						else if (j == 1)
						{
							float a = std::stof(valueF);
							indexUvs = a;
							uvIndex.push_back(indexUvs);
						}
						else if (j == 2)
						{
							float a = std::stof(valueF);
							indexNormals = a;
							normalIndex.push_back(indexNormals);
						}
					}
				}
			}
			else if (tipoValor == "vt")
			{
				int space = 2, space2;
				vector2 tempVector;

				for (int i = 0; i < 2; i++)
				{
					space2 = tempLine.find(" ", space + 1);

					int size = space2 - space;

					std::string values = tempLine.substr(space, size);

					space = space2;

					if (i == 0)
					{
						tempVector.x = std::stof(values);
					}
					if (i == 1)
					{
						tempVector.y = std::stof(values);
					}
				}

				tempUvs.push_back(tempVector);
			}
			else if (tipoValor == "vn")
			{
				int space = 2, space2;
				vector3 tempVec3;

				for (int i = 0; i < 3; i++)
				{

					space2 = tempLine.find((char)32, space + 1);

					int size = space2 - space;

					std::string val = tempLine.substr(space + 1, size);

					space = space2;

					if (i == 0)
					{
						tempVec3.x = std::stof(val);
					}
					else if (i == 1)
					{
						tempVec3.y = std::stof(val);
					}
					else if (i == 2)
					{
						tempVec3.z = std::stof(val);
					}
				}

				tempNormals.push_back(tempVec3);
			}
			else
			{
				continue;
			}
		}

		for (int i = 0; i < tempPositions.size(); i++)
		{
			Vertex tempVertex;

			tempVertex.positions = tempPositions[i];
			tempVertex.uvs = tempUvs[i];
			tempVertex.normals = tempNormals[i];

			vertexs.push_back(tempVertex);
		}
	}
}

Mesh::Mesh()
{
}


Mesh::~Mesh()
{
}
