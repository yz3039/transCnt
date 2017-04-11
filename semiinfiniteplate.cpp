#include "semiinfiniteplate.h"

SemiInfinitePlate::SemiInfinitePlate(float L){
	_L = L;
}
SemiInfinitePlate::~SemiInfinitePlate(){}

float SemiInfinitePlate::getL(){
	return _L;
}