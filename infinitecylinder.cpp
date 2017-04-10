#include "infinitecylinder.h"

InfiniteCylinder::InfiniteCylinder(float radius){
	_radius = radius;
}

InfiniteCylinder::~InfiniteCylinder(){}

float InfiniteCylinder::getRadius(){
	return _radius;
}