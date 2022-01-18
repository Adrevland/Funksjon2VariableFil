

#include <iostream>
#include <fstream>
#include <ostream>
#include <cmath>
#include "Vertex.h"

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062


class funk2variable
{
public:
	funk2variable();
    ~funk2variable();

    void Write(float func(float x, float y));

    friend std::ostream& operator<< (std::ostream& os, const Vertex& v);

    //! Overloaded ostream operator which reads all vertex data from an open textfile stream
    friend std::istream& operator>> (std::istream& is, Vertex&);

private:
    int mLinjer{ 0 };

};

std::ostream& operator<<(std::ostream& os, const Vertex& v)
{
    os << std::fixed;
    os << "(" << v.x << ", " << v.y << ", " << v.z << ") ";
    os << "(" << v.r << ", " << v.g << ", " << v.b << ") ";
    os << "(" << v.t1 << ", " << v.t2 << ") \n";
    return os;
}

std::istream& operator>>(std::istream& is, Vertex& v)
{
    char dum, dum2, dum3, dum4;
    is >> dum >> v.x >> dum2 >> v.y >> dum3 >> v.z >> dum4;
    is >> dum >> v.r >> dum2 >> v.g >> dum3 >> v.b >> dum4;
    is >> dum >> v.t1 >> dum2 >> v.t2 >> dum3;
    return is;
}


funk2variable::funk2variable()
{
}

funk2variable::~funk2variable()
{
}

void funk2variable::Write(float func(float x, float y))
{

	std::ofstream MyFile("Graph3d.txt");

    float size{ 20 };
    float h{1.0f};

    MyFile << size * size * 6 << "\n"; // line count

	for (float ix = -(size/2); ix < (size/2) ; ix += h)
	{
        for (float iy = -(size / 2); iy < (size/2); iy += h)
        {
            float z = func(ix,iy);
            MyFile << (Vertex{ ix,iy,z,ix,iy,z });
        	z = func(ix+h, iy);
            MyFile << (Vertex{ ix + h,iy,z,ix,iy,z });
        	z = func(ix, iy+h);
            MyFile << (Vertex{ ix,iy + h,z,ix,iy,z });

            MyFile << (Vertex{ ix,iy + h,z,ix,iy,z });
            z = func(ix+h, iy);
            MyFile << (Vertex{ ix + h,iy,z,ix,iy,z });
            z = func(ix + h, iy + h);
            MyFile << (Vertex{ ix + h,iy + h,z,ix,iy,z });
        }
	}

    MyFile.close();
}

float basicfunc(float x, float y)
{
    return sin(x+PI)*sin(y+PI);
}

int main()
{
    funk2variable ftest;


    ftest.Write(basicfunc);

	std::cout << "Hello World!\n";
}


