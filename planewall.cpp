#include "planewall.h"

PlaneWall::PlaneWall(float length){
	_length = length;
}

PlaneWall::~PlaneWall(){}

float PlaneWall::getLength(){
	return _length;
}