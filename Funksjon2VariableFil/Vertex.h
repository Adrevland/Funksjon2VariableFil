#ifndef VERTEX_H
#define VERTEX_H
#pragma once

#include "Vector3d.h"

class Vertex
{
public:
	Vertex();
	Vertex(float x, float y, float z);
	Vertex(float x, float y, float z, float t1, float t2);
	Vertex(float x, float y, float z, float r, float g, float b);
	Vertex(float x, float y, float z, float r, float g, float b, float t1, float t2);
	~Vertex();

	//latskap gidd ikke lag getters og setters
	float x{0.f}, y{ 0.f }, z{ 0.f };
	float r{ 0.f }, g{ 0.f }, b{ 0.f };
	float t1{ 0.f }, t2{ 0.f };
private:

	//Vector3d mXYZ;
	//Vector3d mNormal;
	
};

#endif
