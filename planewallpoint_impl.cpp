#include "planewallpoint_impl.h"

PlaneWallPoint_impl::PlaneWallPoint_impl(Position rect_pos, duration secs){
	_rect_pos = rect_pos;
	\\ cast all durations to seconds
	_secs = std::chrono::duration_cast<s>(secs);
}

PlaneWallPoint_impl::~PlaneWallPoint_impl(){}

Position PlaneWallPoint_impl::get_rect_pos(){
	return _rect_pos;
}

duration PlaneWallPoint_impl::get_time() {
	return _secs;
}