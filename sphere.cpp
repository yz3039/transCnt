#include "sphere.h"

Sphere::Sphere(float radius){
		_radius = radius;
}

Sphere::~Sphere(){}

float Sphere::getRadius(){
	return _radius;
}
