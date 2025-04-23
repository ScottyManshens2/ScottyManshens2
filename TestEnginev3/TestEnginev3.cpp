#include <SFML/Graphics.hpp>
#include "Point.hpp"
#include "Projection.hpp"
#include "Vecteur.hpp"
#include "Camera.hpp"
#include "Face.hpp"
#include "Draw.hpp"
#include "Object.hpp"
#include "Hitbox.hpp"
#include <iostream>
#include <cmath>

int main()
{
    // Créer une fenêtre en plein écran avec la résolution actuelle du bureau
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktop, "TestEnginev3"/*, sf::Style::Fullscreen */);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Erreur : Impossible de charger la police 'arial.ttf' !" << std::endl;
        return -1; // quitte le programme
    }


    sf::Text fpsText;
    fpsText.setFont(font);
    fpsText.setCharacterSize(60);  // <<< Plus gros !
    fpsText.setFillColor(sf::Color::White);  // <<< Plus visible
    fpsText.setPosition(20, 20);  // <<< Bien placé
    sf::Clock clock; // Déclaré en dehors de la boucle principale
    float fps = 0.f;

    Camera cam(0.f,22.f, 0.f, 0.f, 0.f);

    for (int i = -5; i < 5; ++i)
    {
        for (int j = -5; j < 5; ++j)
        {
            Cube cube(Point(-70.f * i, 17.f, -70.f * j), Point(-70.f * (i + 1), 20.f, -70.f * (j + 1)), sf::Color(139, 69, 19));
        }
    }

	Cube wall(Point(-1.f, 20.f, 10.f), Point(1.f, 21.f, 12.f), sf::Color::Red);
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

        // update caméra et dessin
        draw(window, cam);

        // update fps
        float elapsed = clock.restart().asSeconds();
        fps = 1.f / elapsed;
        fpsText.setString("FPS: " + std::to_string(static_cast<int>(fps)));

        cam.updateMouvement(elapsed);  // <<< ici


        // DESSINER le texte fps après tout
        window.draw(fpsText);

        window.display();

    }

    return 0;
}
