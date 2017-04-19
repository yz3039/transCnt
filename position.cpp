#include "position.h"

Position::Position(float pos) {
	_pos= pos;
}

Position::~Position(){}

float Position::getPos(){
	return _pos;
}