#include "Face.hpp"
#include "Camera.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Projection.hpp"
#include "Point.hpp"
#include "Vecteur.hpp"

#include <iostream>



void draw(sf::RenderWindow& window, const Camera& cam)
{
    // Trier les vecteurs par profondeur (les plus éloignés en premier)
    std::sort(vectors.begin(), vectors.end(), [&cam](const Vecteur& v1, const Vecteur& v2) {
        return v1.getDepth(cam) > v2.getDepth(cam);  // Inverser l'ordre pour les vecteurs
        });

    // Dessiner chaque vecteur après le tri
    for (const Vecteur& v : vectors)
    {
        v.drawVector(window, cam); // Dessiner chaque vecteur
    }

    // Trier les faces par profondeur (les plus éloignées en premier)
    std::sort(faces.begin(), faces.end(), [&cam](const Face& f1, const Face& f2) {
        return f1.getDepth(cam) > f2.getDepth(cam);  // Inverser l'ordre pour les faces
        });

    // Dessiner chaque face après le tri
    for (Face& f : faces)
    {
        f.drawFace(window, cam, f.getColor()); // Dessiner chaque face

    }

}
