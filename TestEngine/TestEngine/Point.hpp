#pragma once 
#include <SFML/Graphics.hpp>

class Camera;

class Point
{
public:
    Point(float x, float y, float z);
    float getX() const;
    float getY() const;
    float getZ() const;

    float getDx(const Camera& cam) const;
    float getDy(const Camera& cam) const;
    float getDz(const Camera& cam) const;

private:
    float m_x, m_y, m_z;
};

