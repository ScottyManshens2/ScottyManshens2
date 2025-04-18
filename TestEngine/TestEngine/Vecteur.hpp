#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <SFML/Graphics.hpp>
#include "Projection.hpp"
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

public:

    Vecteur(const Point& p1, const Point& p2);

    Point getP1() const;
    Point getP2()const;

    void drawVector(sf::RenderWindow& window, const Camera& cam) const;
};



#endif // VECTOR_HPP
