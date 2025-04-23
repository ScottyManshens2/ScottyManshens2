#include "Object.hpp"
#include "Point.hpp"
#include "Camera.hpp"
#include "Vecteur.hpp"
#include "Face.hpp"

Object::Object(const Point& p1, const Point& p2, sf::Color color) 
	: m_p1(p1), m_p2(p2), m_color(color){
}

Cube::Cube(const Point& point1, const Point& point2, sf::Color color)
	: Object(point1, point2, m_color) {

	Point p1(point1.getX(), point1.getY(), point1.getZ());
	Point p2(point2.getX(), point1.getY(), point1.getZ());
	Point p3(point1.getX(), point2.getY(), point1.getZ());
	Point p4(point2.getX(), point2.getY(), point1.getZ());
	Point p5(point1.getX(), point1.getY(), point2.getZ());
	Point p6(point2.getX(), point1.getY(), point2.getZ());
	Point p7(point1.getX(), point2.getY(), point2.getZ());
	Point p8(point2.getX(), point2.getY(), point2.getZ());

	Vecteur v1(p1, p2);
	Vecteur v2(p1, p3);
	Vecteur v3(p1, p5);
	Vecteur v4(p2, p4);
	Vecteur v5(p2, p6);
	Vecteur v6(p3, p4);
	Vecteur v7(p3, p7);
	Vecteur v8(p4, p8);
	Vecteur v9(p5, p6);
	Vecteur v10(p5, p7);
	Vecteur v11(p6, p8);
	Vecteur v12(p7, p8);

	Face f1(v1, v9, color);
	Face f2(v6, v12, color);
	Face f3(v1, v6, color);
	Face f4(v9, v12, color);
	Face f5(v3, v7, color);
	Face f6(v5, v8, color);

	Hitbox(point1, point2);
}