#include "Point.hpp"
#include "Camera.hpp"

Point::Point(float x, float y, float z)
	: m_x(x), m_y(y), m_z(z)
{
	// Constructeur
}

float Point::getX() const
{
	return m_x;
}

float Point::getY() const
{
	return m_y;
}

float Point::getZ() const
{
	return m_z;
}

float Point::getDx(const Camera& cam) const
{
	return m_x - cam.getX();
}

float Point::getDy(const Camera& cam) const
{
	return m_y - cam.getY();
}

float Point::getDz(const Camera& cam) const
{
	return m_z - cam.getZ();
}
