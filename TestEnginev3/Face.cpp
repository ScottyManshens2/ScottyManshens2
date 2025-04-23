#include "Face.hpp"
#include "Vecteur.hpp"
#include <vector>
#include <iostream>


std::vector<Face> faces;

Face::Face(Vecteur& v1, Vecteur& v2, sf::Color color)
    : m_vector1(v1), m_vector2(v2), m_color(color)
{
    // Vérifier si une face avec les mêmes vecteurs existe déjà
    bool existeDeja = false;

    for (const Face& f : faces)
    {
        bool memeVecteurs =
            ((&f.m_vector1 == &v1 && &f.m_vector2 == &v2) ||
                (&f.m_vector1 == &v2 && &f.m_vector2 == &v1)); // peu importe l'ordre

        if (memeVecteurs)
        {
            existeDeja = true;
            break;
        }
    }

    if (!existeDeja)
    {
        faces.push_back(*this);
    }
}


sf::Color Face::getColor()
{
	return m_color;
}

float Face::getDepth(const Camera& cam) const
{
	return (getRelativeZ(m_vector1.getP1(), cam) + getRelativeZ(m_vector1.getP2(), cam) + getRelativeZ(m_vector2.getP1(), cam) + getRelativeZ(m_vector2.getP2(), cam)) / 4;
}

// Méthode pour dessiner la face
void Face::drawFace(sf::RenderWindow& window, const Camera& cam, sf::Color color) const
{
    const Point& p1 = m_vector1.getP1();
    const Point& p2 = m_vector1.getP2();
    const Point& p3 = m_vector2.getP2();
    const Point& p4 = m_vector2.getP1();

    float depth = (getRelativeZ(p1, cam) + getRelativeZ(p2, cam) + getRelativeZ(p3, cam) + getRelativeZ(p4, cam)) / 4;

    if (depth > 0) {
        float x1 = projX(getRelativeX(p1, cam), getRelativeZ(p1, cam));
        float y1 = projY(getRelativeY(p1, cam), getRelativeZ(p1, cam));

        float x2 = projX(getRelativeX(p2, cam), getRelativeZ(p2, cam));
        float y2 = projY(getRelativeY(p2, cam), getRelativeZ(p2, cam));

        float x3 = projX(getRelativeX(p3, cam), getRelativeZ(p3, cam));
        float y3 = projY(getRelativeY(p3, cam), getRelativeZ(p3, cam));

        float x4 = projX(getRelativeX(p4, cam), getRelativeZ(p4, cam));
        float y4 = projY(getRelativeY(p4, cam), getRelativeZ(p4, cam));

        // 1. Dessiner la face remplie (comme avant)
        sf::VertexArray quad(sf::TrianglesFan, 4);
        quad[0].position = sf::Vector2f(x1, y1);
        quad[1].position = sf::Vector2f(x2, y2);
        quad[2].position = sf::Vector2f(x3, y3);
        quad[3].position = sf::Vector2f(x4, y4);

        quad[0].color = color;
        quad[1].color = color;
        quad[2].color = color;
        quad[3].color = color;

        window.draw(quad);

        // 2. Dessiner les contours SEULEMENT si ce n'est pas du marron (139, 69, 19)
        if (!(color.r == 139 && color.g == 69 && color.b == 19)) {
            sf::VertexArray lines(sf::LineStrip, 5);  // 5 pour fermer le contour

            lines[0].position = sf::Vector2f(x1, y1);
            lines[1].position = sf::Vector2f(x2, y2);
            lines[2].position = sf::Vector2f(x3, y3);
            lines[3].position = sf::Vector2f(x4, y4);
            lines[4].position = sf::Vector2f(x1, y1); // fermer la boucle

            for (int i = 0; i < 5; ++i) {
                lines[i].color = sf::Color::Black;
            }

            window.draw(lines);
        }
    }
}
