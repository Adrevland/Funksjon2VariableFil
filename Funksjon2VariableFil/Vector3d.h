#pragma once


class Vector3d
{
public:
    Vector3d(){};
	Vector3d(const float x,const float y,const float z);
	~Vector3d();


	float x{ 0 }, y{ 0 }, z{ 0 };

    Vector3d(const Vector3d& vec);    //copy constructor
    Vector3d operator+(const Vector3d& vec)const;    //addition
    Vector3d& operator+=(const Vector3d& vec);  ////assigning new result to the vector
    Vector3d operator-(const Vector3d& vec)const;    //substraction
    Vector3d& operator-=(const Vector3d& vec);  //assigning new result to the vector
    Vector3d operator*(float value)const;    //multiplication
    Vector3d& operator*=(float value);  //assigning new result to the vector.
    Vector3d operator/(float value)const;    //division
    Vector3d& operator/=(float value);  //assigning new result to the vector
    Vector3d& operator=(const Vector3d& vec);

    bool operator!=(const Vector3d&vec)const;
    bool operator==(const Vector3d& vec)const;

    float magnitude()const;
    float square()const;
    float distance(const Vector3d &vec) const;
    Vector3d& Normalize();
    float dot_product(const Vector3d& vec)const;
    Vector3d cross_product(const Vector3d& vec)const;

private:

};

