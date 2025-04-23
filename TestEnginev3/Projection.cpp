#include "Projection.hpp"
#include <iostream>
#include <cmath>
#include "Camera.hpp"

int FOV(1000); // de 100 à 1000

float projX(float x, float z)
{
    const float nearClip = 1e-6; // Profondeur minimale pour éviter les divisions par zéro
    z = std::max(z, nearClip); // Appliquer une correction de profondeur si z est trop petit
    return (1920 / 2) + ((x / z) * FOV);
}

float projY(float y, float z)
{
    const float nearClip = 1e-6; // Profondeur minimale pour éviter les divisions par zéro
    z = std::max(z, nearClip); // Appliquer une correction de profondeur si z est trop petit
    return (1080 / 2) - ((y / z) * FOV);
}


float getRelativeX(Point p, const Camera& c)
{
	const float dx = p.getX() - c.getX();
	const float dz = p.getZ() - c.getZ();
	const float dy = p.getY() - c.getY();

	const float a = c.getPlayerAngleX();
	const float b = c.getPlayerAngleY();

	return dx*cos(a)-dz*sin(a);
}

float getRelativeZ(Point p, const Camera& c)
{
	const float dx = p.getX() - c.getX();
	const float dz = p.getZ() - c.getZ();
	const float dy = p.getY() - c.getY();
	const float a = c.getPlayerAngleX();
	const float b = c.getPlayerAngleY();
	return dx*sin(a)*cos(b)+dy*sin(b)+dz*cos(a)*cos(b);
}

float getRelativeY(Point p, const Camera& c)
{
	const float dx = p.getX() - c.getX();
	const float dz = p.getZ() - c.getZ();
	const float dy = p.getY() - c.getY();
	const float a = c.getPlayerAngleX();
	const float b = c.getPlayerAngleY();
	return -dx*sin(a)*sin(b) + dy*cos(b) - dz*cos(a)*sin(b);
}
