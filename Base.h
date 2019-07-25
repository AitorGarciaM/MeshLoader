#pragma once
#include<fstream>	
#include<iostream>
#include<vector>
#include<string>

struct vector3
{
	float x, y, z;

	vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}
};

struct vector2
{
	float x, y;

	vector2()
	{
		x = 0;
		y = 0;
	}
};

struct Vertex
{
	vector3 positions, normals;
	vector2 uvs;
};
