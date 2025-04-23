#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <SFML/Graphics.hpp>
#include "Projection.hpp"
#include "Point.hpp"
#include <vector>

// Déclaration anticipée (forward declaration)
class Point;
class Camera;
class Vecteur;

extern std::vector<Vecteur> vectors;

class Vecteur
{
private:
    Point m_point1;
    Point m_point2;

	sf::Color m_color;

public:

    Vecteur(const Point& p1, const Point& p2);
    Vecteur(const Point& p1, const Point& p2, sf::Color color);


    Point getP1() const;
    Point getP2()const;

    float getDepth(const Camera& cam) const;

    void drawVector(sf::RenderWindow& window, const Camera& cam) const;
};



#endif // VECTOR_HPP
