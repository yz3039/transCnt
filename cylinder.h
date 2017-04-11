#ifndef CYLINDER_H
#define CYLINDER_H

class Cylinder{
	float _radius;
	float _L;
public:
	Cylinder(float radius, float L);
	~Cylinder();
	float getRadius();
	float getL();
};

#endif