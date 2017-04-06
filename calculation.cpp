#include <math.h>
#include "sphere.h"
#include "constant.h"

float biot(float h, float k, float x){
	return h*x/k;
}

float fourier(float alpha, float time, float x){
	return alpha*time/(x*x);
}

float calculate_alpha(float k, float density, float c){
    return k/(density*c);
}


//newton-raphson
float solve_for_zeta(float biot){
    return 1.142;
}


template <typename Geometry>
float lumped_cap_at_time(Geometry g, float density, float h, float c, float time, float t_init, float t_inf){
	float vol = g.getVolumn();
	float surface_area = g.getSurfaceArea();

	float theta = exp(-h*surface_area*time/(density*volumn*c));
	return theta*(t_init-t_inf)+t_inf;
}

float sphere_one_term_at_time_at_point(float fourier, float biot, float r, float r0, float t_init, float t_inf){
    float zeta = solve_for_zeta(biot); //can we solve this directly? (biot number)
    float c1 = 4.0f*(sin(zeta)-zeta*cos(zeta))/(2.0f*zeta-sin(2.0f*zeta));
    float temp = zeta*r/r0;
    float theta = c1*exp(-zeta*zeta*fourier)*(1/temp)*sin(temp);
    return theta*(t_init-t_inf)+t_inf;
}

void sphere_one_term_at_time(vector<float>* ret, float fourier, float biot, vector<float>& points, float r0, float t_init, float t_inf){
    float zeta; //can we solve this directly?
    float c1 = 4.0f*(sin(zeta)-zeta*cos(zeta))/(2.0f*zeta-sin(2.0f*zeta));
    float y = c1*exp(-zeta*zeta*fourier);
    float z = zeta/r0;
    float diff = t_init-t_inf;
    int i = 0;
    for(auto it = points.begin(); it != points.end(); ++it, ++i){
        float q = z*(*it);
        float theta = y*(1/q)*sin(q);
        (*ret)[i] = theta*diff+t_inf;
    }
}

float semi_infinite_at_time_at_point(float x, float alpha, float t, float h, float k, float t_init, float t_inf){
    float y = sqrt(alpha*time);
    float z = x/(2*y);
    float theta = erfc(z) - exp(h*x/k + h*h*alpha*time/(k*k))*erfc(z+h*y/k);
    return theta*(t_init-t_inf)+t_inf;
}

vector<float> semi_infinite_at_time(vector<float>* ret, vector<float>& points, float alpha, float t, float h, float k, float t_init, float t_inf){
    float y = sqrt(alpha*time);
    float z = h*h*alpha*time/(k*k);
    int i = 0;
    for(auto it = points.begin(); it != points.end(); ++it, ++i){
        float x = *it;
        float q = x/(2*y);
        float theta = erfc(q) - exp(h*x/k + z)*erfc(q+h*y/k);
        (*ret)[i] = theta*diff+t_inf;
    }
}

void temp_at_time(vector<float>* ret, Sphere s, string mat, string envmat, vector<float>& points, float time, float t_init, float t_inf){
    float r0 = s.getRadius();
    
    //heat transfer coefficient (units: W/m^2K)
    float h = get_h(envmat);
    //conduction coefficient (units: W/mK)
    float k = get_k(mat, t_init);
    float bi = biot(h, k, r0);
    //Lumped Capacitance. Use this when Bi < 0.1
    // saved data
    float density = get_density(mat);
    float c = get_c(mat, t_init);
    if(bi<0.1){
        float temp =  lumped_cap_at_time(s, density, h, c, time, t_init, t_inf);
        for(int i = 0; i < points.size(); i++){
            (*ret)[i] = temp;
        }
        return;
    }
    
    //thermal diffusivity (units: m^2/s)
    float alpha = calculate_alpha(k, density, c);
    float fo = fourier(alpha, time, r0);
    //One-Term Approximation. Use this when Fo > 0.2
    if(fo > 0.2){
        sphere_one_term_at_time(ret, fo, bi, points, r0, t_init, t_inf);
        return;
    }
    
    //Saved data.
    if(fo > 0.05){
        
    }
    
    //semi-infinite approximation
    semi_infinite_at_time(ret, points, alpha, time, h, k, t_init, t_inf);
    
}

float temp_at_time_at_point(Sphere s, string mat, string envmat, float r, float time, float t_init, float t_inf){
	float r0 = s.getRadius();

	//heat transfer coefficient (units: W/m^2K)
    float h = get_h(envmat);
    //conduction coefficient (units: W/mK)
    float k = get_k(mat, t_init);
    float bi = biot(h, k, r0);
	//Lumped Capacitance. Use this when Bi < 0.1
    float density = get_density(mat);
    float c = get_c(mat, t_init);
    if(bi<0.1){
		return lumped_cap_at_time(s, density, h, c, time, t_init, t_inf);
	}

	//thermal diffusivity (units: m^2/s)
	float alpha = calculate_alpha(k, density, c);
	float fo = fourier(alpha, time, r0);
	//One-Term Approximation. Use this when Fo > 0.2
	if(fo > 0.2){
        return sphere_one_term_at_time_at_point(fo, bi, r, r0, t_init, t_inf);
	}
    
    //Saved data.
    if(fo > 0.05){
        
    }
    
    //semi-infinite approximation
    
    return semi_infinite_at_time_at_point(r, alpha, time, h, k, t_init, t_inf);
}
