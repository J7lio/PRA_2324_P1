#include <iostream>

#include "Rectangle.h"

bool Rectangle::check(Point2D* vertices){
	double d1 = Point2D::distance(vertices[0], vertices[1]);
	double d2 = Point2D::distance(vertices[2], vertices[3]);
	double d3 = Point2D::distance(vertices[1], vertices[2]);
	double d4 = Point2D::distance(vertices[3], vertices[0]);

	return d1 == d2 && d3 == d4;
}

Rectangle::Rectangle(){
	vs = new Point2D[N_VERTICES]{
		Point2D(-1.0, 0.5),
		Point2D( 1.0, 0.5),
		Point2D( 1.0,-0.5),
		Point2D(-1.0,-0.5)
	};
}

Rectangle::Rectangle(std::string color, Point2D* vertices){
	if(!check(vertices)) throw std::invalid_argument("No forma un rectangulo");

	vs = new Point2D[N_VERTICES]{
		vertices[0],
		vertices[1],
		vertices[2],
		vertices[3]
	};
	set_color(color);
}

Rectangle::Rectangle(const Rectangle &r){
	vs = new Point2D[N_VERTICES]{
		r.vs[0],
		r.vs[1],
		r.vs[2],
		r.vs[3]
	};
	set_color(r.get_color());
}

Rectangle::~Rectangle(){
	delete[] vs;
}


Point2D Rectangle::get_vertex(int ind) const{

	if(ind < 0 || ind >= 4) throw std::out_of_range("Indice fuera de rango");
	return vs[ind];
}

Point2D Rectangle::operator[](int ind) const{
	return get_vertex(ind);
}

Rectangle& Rectangle::operator=(const Rectangle &r){
	Rectangle copia(r);

	*this = copia;

	return *this;
}

std::ostream& operator<<(std::ostream& out, const Rectangle &r){
	out << "[Rectangle: color = " << r.color << "; v0 = " << r[0] << "; v1 = " << r[1]
		<< "; v2 = " << r[2] << "; v3 = " << r[3];

	return out;
}

void Rectangle::set_vertices(Point2D* vertices){
	if(!check(vertices)) throw std::invalid_argument("Vertices no validos");

	for(int i = 0; i < N_VERTICES; i++){
		vs[i] = vertices[i];
	}
}

double Rectangle::area() const{
	double b = Point2D::distance(vs[0], vs[1]);
	double a = Point2D::distance(vs[1], vs[2]);

	return b*a;
}

double Rectangle::perimeter() const{
	double d1 = Point2D::distance(vs[0], vs[1]);
	double d2 = Point2D::distance(vs[2], vs[3]);
	double d3 = Point2D::distance(vs[1], vs[2]);
	double d4 = Point2D::distance(vs[3], vs[0]);

	return d1+d2+d3+d4;
}

void Rectangle::translate(double incX, double incY){
	for(int i = 0; i < N_VERTICES; i++){
		vs[i].x += incX;
		vs[i].y += incY;
	}
}

void Rectangle::print(){
	std::cout << *this;
}
