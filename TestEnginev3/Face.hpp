#pragma once
#include <SFML/Graphics.hpp>
#include "Projection.hpp"
#include "Camera.hpp"
#include "Vecteur.hpp"
#include <vector>

class Vecteur;
class Face;

extern std::vector<Face> faces;

class Face

{
public:
    Face(Vecteur& v1, Vecteur& v2, sf::Color color);  // Constructeur avec les vecteurs

    sf::Color getColor();

    void drawFace(sf::RenderWindow& window, const Camera& cam, sf::Color color) const;  // Méthode pour dessiner la face

    float getDepth(const Camera& cam) const;

private:
    Vecteur m_vector1;  // Référence au premier vecteur
    Vecteur m_vector2;
    sf::Color m_color;// Référence au deuxième vecteur
};
