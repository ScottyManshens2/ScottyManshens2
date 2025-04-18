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
    for (const Vecteur& v : vectors)
    {
        v.drawVector(window, cam); // Dessiner chaque vecteur
    }

    for (Face& f : faces)
    {

        f.drawFace(window, cam, f.getColor()); // Dessiner chaque vecteur
    }


}