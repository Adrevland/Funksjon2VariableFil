#include "Vector3d.h"
#include <string>

Vector3d::Vector3d(const float x, const float y, const float z)
	:x(x),y(y),z(z)
{
}

Vector3d::~Vector3d()
{
}

Vector3d::Vector3d(const Vector3d& vec)
	:x(vec.x), y(vec.y), z(vec.z)
{
}

Vector3d Vector3d::operator+(const Vector3d& vec) const
{
	return Vector3d{ vec.x + x, vec.y + y, vec.z + z };
}

Vector3d& Vector3d::operator+=(const Vector3d& vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
	return *this;
}

Vector3d Vector3d::operator-(const Vector3d& vec) const
{
	return Vector3d{ x - vec.x, y - vec.y, z - vec.z };
}

Vector3d& Vector3d::operator-=(const Vector3d& vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	return *this;
}

Vector3d Vector3d::operator*(float value) const
{
	return Vector3d{ x * value, y * value, z * value };
}

Vector3d& Vector3d::operator*=(float value)
{
	x *= value;
	y *= value;
	z *= value;
	return *this;
}

Vector3d Vector3d::operator/(float value) const
{
	return Vector3d{ x / value, y / value, z / value };
}

Vector3d& Vector3d::operator/=(float value)
{
	x /= value;
	y /= value;
	z /= value;
	return *this;
}

Vector3d& Vector3d::operator=(const Vector3d& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
	return *this;
}

bool Vector3d::operator!=(const Vector3d& vec) const
{
	return x != vec.x && y != vec.y && z != vec.z;
}

bool Vector3d::operator==(const Vector3d& vec) const
{
	return x == vec.x && y == vec.y && z == vec.z;
}

float Vector3d::magnitude() const
{
	return sqrt(square());
}

float Vector3d::square() const
{
	return x * x + y * y + z * z;
}

Vector3d Vector3d::cross_product(const Vector3d& vec) const
{
	return Vector3d{ y * vec.z - z * vec.y,z * vec.x - x * vec.z,x * vec.y - y * vec.x };
}

float Vector3d::distance(const Vector3d& vec) const
{
	return (*this-vec).magnitude();
}

Vector3d& Vector3d::Normalize()
{
	*this /= magnitude();
	return *this;
}

float Vector3d::dot_product(const Vector3d& vec) const
{
	return x * vec.x + y * vec.y + z * vec.z;
}
