#include "sphere.h"
#include <math.h>

float biot(float h, float k, float x){
	return h*x/k;
}

float fourier(float alpha, float time, float x){
	return alpha*time/(x*x);
}

template <typename Geometry>
float lumped_cap_at_time(Geometry g, float density, float h, float c, float time, float t_init, float t_inf){
	float vol = g.getVolumn();
	float surface_area = g.getSurfaceArea();

	float theta = exp(-h*surface_area*time/(density*volumn*c));
	return theta*(t_init-t_inf)+t_inf;
}

float temp_at_time(Sphere s, string mat, string envmat, float time, float t_init, float t_inf){
	float r = s.getRadius();

	//heat transfer coefficient (units: W/m^2K)
	float h;
	//conduction coefficient (units: W/mK)
	float k; 
	float bi = biot(h, k, r);
	//Lumped Capacitance. Use this when Bi < 0.1
	if(bi<0.1){
		// saved data
		float density;
		float c;
		
		return lumped_cap_at_time(s, density, h, c, time, t_init, t_inf);
	}

	//thermal diffusivity (units: m^2/s)
	float alpha;
	float fo = fourier(alpha, time, r);
	//One-Term Approximation. Use this when Fo > 0.2
	if(fo > 0.2){

	}
}