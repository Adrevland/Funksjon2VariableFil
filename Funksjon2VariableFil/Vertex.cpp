#include "Vertex.h"

Vertex::Vertex()
{
}

Vertex::Vertex(float x, float y, float z)
	:x(x), y(y), z(z)
{

}

Vertex::Vertex(float x, float y, float z, float t1, float t2)
	: x(x), y(y), z(z), t1(t1), t2(t2)
{
}

Vertex::Vertex(float x, float y, float z, float r, float g, float b)
	:x(x),y(y),z(z),r(r),g(g),b(b)
{
}

Vertex::Vertex(float x, float y, float z, float r, float g, float b, float t1, float t2)
	: x(x), y(y), z(z), r(r), g(g), b(b), t1(t1), t2(t2)
{
}

Vertex::~Vertex()
{

}
