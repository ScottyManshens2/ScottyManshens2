#include "Face.hpp"
#include <vector>
#include <iostream>


std::vector<Face> faces;

// Constructeur de la classe Face
Face::Face(Vecteur& v1, Vecteur& v2, sf::Color color)
	: m_vector1(v1), m_vector2(v2), m_color(color)
{
    faces.push_back(*this);
}

sf::Color Face::getColor()
{
	return m_color;
}

// Méthode pour dessiner la face
void Face::drawFace(sf::RenderWindow& window, const Camera& cam, sf::Color color) const
{
    // Récupérer les points des deux vecteurs
    const Point& p1 = m_vector1.getP1();
    const Point& p2 = m_vector1.getP2();
    const Point& p3 = m_vector2.getP2();
    const Point& p4 = m_vector2.getP1();

    float depth = (p1.getDz(cam) + p2.getDz(cam) + p3.getDz(cam) + p4.getDz(cam)) / 4;

    std::cout << depth << std::endl;
    // Vérifie si la face est devant la caméra (si Z est positif)
    if (depth > 0) {

        // Calculer les coordonnées X et Y de chaque point à projeter sur l'écran
        float x1 = projX(p1.getDx(cam), p1.getDz(cam));
        float y1 = projY(p1.getDy(cam), p1.getDz(cam));

        float x2 = projX(p2.getDx(cam), p2.getDz(cam));
        float y2 = projY(p2.getDy(cam), p2.getDz(cam));

        float x3 = projX(p3.getDx(cam), p3.getDz(cam));
        float y3 = projY(p3.getDy(cam), p3.getDz(cam));

        float x4 = projX(p4.getDx(cam), p4.getDz(cam));
        float y4 = projY(p4.getDy(cam), p4.getDz(cam));

        // Dessiner la face
        sf::VertexArray quad(sf::TrianglesFan, 4);  // Utilisation de sf::TrianglesFan pour dessiner une face

        quad[0].position = sf::Vector2f(x1, y1);
        quad[1].position = sf::Vector2f(x2, y2);
        quad[2].position = sf::Vector2f(x3, y3);
        quad[3].position = sf::Vector2f(x4, y4);

        quad[0].color = color;  // Appliquer une couleur (ici, rouge)
        quad[1].color = color;
        quad[2].color = color;
        quad[3].color = color;


        window.draw(quad);  // Dessiner la face sur la fenêtre
    }
}
