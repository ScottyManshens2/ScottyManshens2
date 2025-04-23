#ifndef PROJECTION_HPP
#define PROJECTION_HPP

#include <SFML/Graphics.hpp>
#include "Point.hpp"
#include "Vecteur.hpp"

class Camera;

//extern sf::RenderWindow window;

float projX(float x, float z);
float projY(float y, float z);

float getRelativeX(Point p, const Camera& c);
float getRelativeZ(Point p, const Camera& c);
float getRelativeY(Point p, const Camera& c);

#endif // PROJECTION_HPP
