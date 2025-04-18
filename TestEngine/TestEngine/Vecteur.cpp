#include "Vecteur.hpp"
#include "Point.hpp"
#include <iostream>

// La vraie définition ici
std::vector<Vecteur> vectors;


Vecteur::Vecteur(const Point& p1, const Point& p2)
    : m_point1(p1), m_point2(p2) {
    vectors.push_back(*this);
}

Point Vecteur::getP1() const {
    return m_point1;
}

Point Vecteur::getP2() const {
    return m_point2;
}

void Vecteur::drawVector(sf::RenderWindow& window, const Camera& cam) const {
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(projX(m_point1.getDx(cam), m_point1.getDz(cam)), projY(m_point1.getDy(cam), m_point1.getDz(cam))), sf::Color::Red),
        sf::Vertex(sf::Vector2f(projX(m_point2.getDx(cam), m_point2.getDz(cam)), projY(m_point2.getDy(cam), m_point2.getDz(cam))), sf::Color::Red)
    };

    window.draw(line, 2, sf::Lines); // Correction aussi ici : il faut 2 points pas 10
}
