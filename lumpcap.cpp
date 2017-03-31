#include <math.h>

const float PI = 3.1415926;

float sphere_surface_area(float radius){
	return 4.0f*PI*radius*radius;
}

float sphere_volumn(float radius){
	return 4.0f*PI*radius*radius*radius/3.0f;
}

float sphere_bi(float h, float k, float r){
	return h*r/(k*3.0f);
}

float sphere_lumped_cap_at_time(string mat, float radius, float time, float t_init, float t_inf, float pos){
	float density;
	float h;
	float c;
	float vol = sphere_volumn(radius);
	float surface_area = sphere_surface_area(radius);

	float theta = exp(-h*surface_area*time/(density*vol*c));
	return theta*(t_init-t_inf)+t_inf;
}