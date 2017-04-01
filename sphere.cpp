#include "sphere.h"
#include "constant.h"

Sphere::Sphere(float radius){
		_radius = radius;
	}

Sphere::~Sphere(){}

float Sphere::getSurfaceArea(){
	return 4.0f*PI*_radius*_radius;
}

float Sphere::getVolumn(){
	return 4.0f*PI*_radius*_radius*_radius/3.0f;
}

float Sphere::getRadius(){
	return _radius;
}
