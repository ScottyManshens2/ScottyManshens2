#pragma once
#include "Point.hpp"
#include <SFML/Graphics.hpp>
#include "Camera.hpp"
#include "Vecteur.hpp"
#include "Face.hpp"
#include <vector>

class Hitbox;

extern std::vector<Hitbox> Hitboxes;

class Hitbox
{
public : 
	Hitbox(const Point& p1, const Point&  p2);

	bool TouchHitBox(const Camera& cam) const;


private:
	Point m_p1;
	Point m_p2;
};

