#include <iostream>

#include "Square.h"

bool Square::check(Point2D* vertices){
	double d1 = Point2D::distance(vertices[0], vertices[1]);
	double d2 = Point2D::distance(vertices[2], vertices[3]);
	double d3 = Point2D::distance(vertices[1], vertices[2]);
	double d4 = Point2D::distance(vertices[3], vertices[0]);

	return d1 == d2 && d1 == d3 & d1 == d4;
}

Square::Square(){
	vs = new Point2D[N_VERTICES]{
		Point2D(-1, 1),
		Point2D( 1, 1),
		Point2D( 1,-1),
		Point2D(-1,-1)
	};
}

Square::Square(std::string color, Point2D* vertices){

	if(!check(vertices)) throw std::invalid_argument("Cuadrado no valido");

	vs = new Point2D[N_VERTICES]{
		vertices[0],
		vertices[1],
		vertices[2],
		vertices[3]
	};
	set_color(color);
}

void Square::set_vertices(Point2D* vertices){
	if(!check(vertices)) throw std::invalid_argument("Vertices no validos para un cuadrado.");

	for(int i = 0; i < N_VERTICES; i++){
		vs[i] = vertices[i];
	}
}

std::ostream& operator<<(std::ostream& out, const Square &r){
	out << "[Square: color = " << r.color << "; v0 = " << r[0] << "; v1 = " << r[1]
		<< "; v2 = " << r[2] << "; v3 = " << r[3];

	return out;
}

void Square::print(){
	std::cout << *this;
}

