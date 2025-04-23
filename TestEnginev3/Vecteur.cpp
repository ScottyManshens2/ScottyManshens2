#include "Vecteur.hpp"
#include <iostream>

// La vraie définition ici
std::vector<Vecteur> vectors;


Vecteur::Vecteur(const Point& p1, const Point& p2)
    : m_point1(p1), m_point2(p2), m_color(sf::Color::Black) {
    vectors.push_back(*this);
}

Vecteur::Vecteur(const Point& p1, const Point& p2, sf::Color color)
	: m_point1(p1), m_point2(p2), m_color(color) {
	vectors.push_back(*this);
}

Point Vecteur::getP1() const {
    return m_point1;
}

Point Vecteur::getP2() const {
    return m_point2;
}

float Vecteur::getDepth(const Camera& cam) const {
	return (getRelativeZ(m_point1, cam) + getRelativeZ(m_point2, cam)) / 1;
}
void Vecteur::drawVector(sf::RenderWindow& window, const Camera& cam) const {
    float depth = (getRelativeZ(m_point1, cam) + getRelativeZ(m_point2, cam)) / 2;

    // Vérifie si la ligne est devant la caméra
    if (depth > 0) {
        // Calculer les coordonnées des deux points
        float x1 = projX(getRelativeX(m_point1, cam), getRelativeZ(m_point1, cam));
        float y1 = projY(getRelativeY(m_point1, cam), getRelativeZ(m_point1, cam));

        float x2 = projX(getRelativeX(m_point2, cam), getRelativeZ(m_point2, cam));
        float y2 = projY(getRelativeY(m_point2, cam), getRelativeZ(m_point2, cam));

        // Calculer la direction du vecteur
        float dx = x2 - x1;
        float dy = y2 - y1;
        float length = std::sqrt(dx * dx + dy * dy);

        // Créer un rectangle pour dessiner la ligne avec une épaisseur personnalisée
        sf::RectangleShape line(sf::Vector2f(length, 1));  // 5 est l'épaisseur de la ligne

        // Calculer l'angle de la ligne
        float angle = std::atan2(dy, dx);
        line.setRotation(angle * 180 / 3.14159265359f);  // Convertir l'angle en degrés

        // Positionner le rectangle à la bonne position
        line.setPosition(x1, y1);
        line.setFillColor(m_color);

        // Dessiner la ligne
        window.draw(line);
    }
}

