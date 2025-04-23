#include "Camera.hpp"
#include "Point.hpp"
#include "Projection.hpp"
#include <iostream>
#include <numbers>

float playerSpeed(2.f);
float playerRotationSpeed(0.8f);

Camera::Camera(float x, float y, float z, float playerAngleX, float playerAngleY)
    : m_x(x), m_y(y), m_z(z), m_playerAngleX(playerAngleX), m_playerAngleY(playerAngleY)
{
    // Constructeur
}

float Camera::getX() const
{
    return m_x;
}

float Camera::getY() const
{
    return m_y;
}

float Camera::getZ() const
{
    return m_z;
}

void Camera::setX(float x)
{
    m_x = x;
}

void Camera::setY(float y)
{
    m_y = y;
}

void Camera::setZ(float z)
{
    m_z = z;
}

float Camera::getPlayerAngleX() const
{
    return m_playerAngleX;
}

float Camera::getPlayerAngleY() const
{
    return m_playerAngleY;
}

void Camera::setPlayerAngleX(float angle)
{
    m_playerAngleX = angle;
}

void Camera::setPlayerAngleY(float angle)
{
    m_playerAngleY = angle;
}

#include "Hitbox.hpp" // Il faut inclure Hitbox pour accéder à Hitboxes

void Camera::updateMouvement(float elapsed)
{
    // Sauvegarde la position avant mouvement
    float oldX = m_x;
    float oldY = m_y;
    float oldZ = m_z;

    const float cosA = cos(m_playerAngleX);
    const float sinA = sin(m_playerAngleX);

    // Mouvement vers l'avant et l'arrière (Z/QS)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        m_x += playerSpeed * sinA * elapsed;
        m_z += playerSpeed * cosA * elapsed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        m_x -= playerSpeed * sinA * elapsed;
        m_z -= playerSpeed * cosA * elapsed;
    }

    // Mouvement latéral (strafe gauche/droite) (Q/D)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        m_x -= playerSpeed * cosA * elapsed;
        m_z += playerSpeed * sinA * elapsed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_x += playerSpeed * cosA * elapsed;
        m_z -= playerSpeed * sinA * elapsed;
    }

    // Monter et descendre (espace/shift)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
    {
        m_y -= playerSpeed * elapsed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        m_y += playerSpeed * elapsed;
    }

    // Rotation (gauche/droite + haut/bas)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_playerAngleX -= playerRotationSpeed * elapsed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_playerAngleX += playerRotationSpeed * elapsed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (m_playerAngleY < 3.141592f / 2)
        {
            m_playerAngleY += playerRotationSpeed * elapsed;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (m_playerAngleY > -3.141592f / 2)
        {
            m_playerAngleY -= playerRotationSpeed * elapsed;
        }
    }

    for (auto& hitbox : Hitboxes)
    {
        if (hitbox.TouchHitBox(*this))
        {
            // Collision détectée : on annule le mouvement
            m_x = oldX;
            m_y = oldY;
            m_z = oldZ;
            break; // Pas besoin de continuer à tester
        }
    }
}
