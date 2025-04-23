#include "Hitbox.hpp"

std::vector<Hitbox> Hitboxes;

Hitbox::Hitbox(const Point&  p1, const Point&  p2)
	: m_p1(p1), m_p2(p2)
{
	Hitboxes.push_back(*this);
}


bool Hitbox::TouchHitBox(const Camera& cam) const
{
    float camX = cam.getX();
    float camY = cam.getY();
    float camZ = cam.getZ();

    // Dimensions du joueur
    float halfWidth = 0.5f;
    float halfDepth = 0.5f;
    float halfHeight = 1.0f;

    float playerMinX = camX - halfWidth;
    float playerMaxX = camX + halfWidth;
    float playerMinY = camY-halfHeight;
    float playerMaxY = camY + halfHeight;
    float playerMinZ = camZ - halfDepth;
    float playerMaxZ = camZ + halfDepth;

    float minX = std::min(m_p1.getX(), m_p2.getX());
    float maxX = std::max(m_p1.getX(), m_p2.getX());
    float minY = std::min(m_p1.getY(), m_p2.getY());
    float maxY = std::max(m_p1.getY(), m_p2.getY());
    float minZ = std::min(m_p1.getZ(), m_p2.getZ());
    float maxZ = std::max(m_p1.getZ(), m_p2.getZ());

    // TEST DE COLLISION AABB (Axis Aligned Bounding Box)
    return (playerMaxX >= minX && playerMinX <= maxX &&
        playerMaxY >= minY && playerMinY <= maxY &&
        playerMaxZ >= minZ && playerMinZ <= maxZ);
}


