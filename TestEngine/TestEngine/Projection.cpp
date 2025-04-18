#include "Projection.hpp"
#include <iostream>

int distanceToScreen(300); 

float projX(float x, float z)
{
	return (window.getSize().x / 2) + ((x / z) * distanceToScreen);
}

float projY(float y, float z)
{
	std::cout << window.getSize().y << std::endl;
	return (window.getSize().y / 2) - ((y / z) * distanceToScreen);
}