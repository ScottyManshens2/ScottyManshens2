#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SFML/Graphics.hpp>
#include "Projection.hpp"
#include "Vecteur.hpp"

class Point;

class Camera
{
public:
    Camera(float x, float y, float z, float playerAngleX, float playerAngleY);

    float getX() const;
    float getY() const;
    float getZ() const;
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    float getPlayerAngleX() const;
    float getPlayerAngleY() const;
    void setPlayerAngleX(float angle);
    void setPlayerAngleY(float angle);

    void updateMouvement(float elapsed);

private:
    float m_x;
    float m_y;
    float m_z;
    float m_playerAngleX;
    float m_playerAngleY;
};

#endif // CAMERA_HPP
