#include <iostream>

#include "Drawing.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

#include "ListLinked.h"
#include "ListArray.h"

#include "Shape.h"


Drawing::Drawing(){
	shapes = new ListArray<Shape*>;
}

Drawing::~Drawing(){
	delete shapes;
}

void Drawing::add_front(Shape* shape){
	shapes->append(shape);
}

void Drawing::add_back(Shape* shape){
	shapes->prepend(shape);
}

void Drawing::print_all(){
	std::cout << "Drawing contents:\n";
	for(int i = 0; i < shapes->size(); i++){
		shapes->get(i)->print();
		std::cout << std::endl;
	}
}

double Drawing::get_area_all_circles(){
	
	double sum = 0.0;
	for(int i = 0; i < shapes->size(); i++){
		Circle* circlePtr = dynamic_cast<Circle*>(shapes->get(i));
		if(circlePtr){
			sum += shapes->get(i)->area();
		}
	}
	return sum;
}

void Drawing::move_squares(double incX, double incY){
	for(int i = 0; i < shapes->size(); i++){
		Square* squarePtr = dynamic_cast<Square*>(shapes->get(i));
		if(squarePtr){
			shapes->get(i)->translate(incX, incY);
		}
	}
}
