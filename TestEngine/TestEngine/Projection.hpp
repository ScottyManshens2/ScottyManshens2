#ifndef PROJECTION_HPP
#define PROJECTION_HPP

#include <SFML/Graphics.hpp>
#include "Point.hpp"
#include "Vecteur.hpp"

extern sf::RenderWindow window;

float projX(float x, float z);
float projY(float y, float z);

#endif // PROJECTION_HPP
