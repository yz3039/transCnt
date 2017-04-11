#include "cylinder.h"

Cylinder::Cylinder(float radius, float L){
	_radius = radius;
	_L = L;
}

Cylinder::~Cylinder(){}

float Cylinder::getRadius(){
	return _radius;
}

float Cylinder::getL(){
	return _L;
}
