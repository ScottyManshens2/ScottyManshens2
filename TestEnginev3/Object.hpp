#pragma once
#include "Projection.hpp"
#include "Point.hpp"
#include "Hitbox.hpp"

class Point;
class Vecteur;
class Camera; // Attention ! "camera" ? "Camera" (majuscule en C++)

class Object
{
protected:
    Point m_p1;
    Point m_p2;
	sf::Color m_color; // Ajout d'une couleur pour l'objet

public:
    Object(const Point& p1, const Point& p2, sf::Color color);

    // Peut-�tre des m�thodes comme draw(), update(), etc.
};

class Cube : public Object
{
public:
    Cube(const Point& p1, const Point& p2, sf::Color color);

    // Tu n'as pas besoin de red�clarer m_p1 et m_p2 ici,
    // car tu h�rites d�j� de m_point1 et m_point2 dans Object !
};
