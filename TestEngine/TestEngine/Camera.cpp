#include "Camera.hpp"
#include "Point.hpp"
#include <iostream>

float playerSpeed(0.07f);

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

void Camera::updateMouvement()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        this->setZ(this->getZ() + playerSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->setZ(this->getZ() - playerSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->setX(this->getX() - playerSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->setX(this->getX() + playerSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
    {
        this->setY(this->getY() - playerSpeed); // Monter
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        this->setY(this->getY() + playerSpeed); // Descendre
    }
}
