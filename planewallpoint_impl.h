#ifndef PLANEWALLPOINT_IMPL_H
#define PLANEWALLPOINT_IMPL_H

class PlaneWallPoint_impl{
	Position _rect_pos;
	duration _secs;
public:
	PlaneWallPoint_impl(Position rect_pos, duration secs);
	~PlaneWallPoint();
	Position get_rect_pos();
	duration get_time();
};

#endif