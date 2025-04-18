#include <SFML/Graphics.hpp>
#include "Point.hpp"
#include "Projection.hpp"
#include "Vecteur.hpp"
#include "Camera.hpp"
#include "Face.hpp"
#include "Draw.hpp"
#include <iostream>


sf::RenderWindow window(sf::VideoMode(800, 600), "Vector Draw");

int main()
{
    Camera cam(0.f, 0.f, 0.f, 0.f, 0.f);

    Vecteur v1(Point(10.f, 10.f, 50.f), Point(10.f, 20.f, 50.f));
	Vecteur v2(Point(-20.f, 10.f, 50.f), Point(-20.f, 40.f, 50.f));

	Face f1(v1, v2, sf::Color::Red);

    // Boucle principale SFML
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(135, 206, 235));

        draw(window , cam);
		cam.updateMouvement();

        window.display();
    }

    return 0;
}
