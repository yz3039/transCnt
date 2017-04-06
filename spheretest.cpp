#include <math.h>
#include "calculation.cpp"

int main(){
    float radius;
    string mat = "st";
    string envmat = "water";
    float r = 0.0125;
    float time = 30;
    float t_init = 500;
    float t_inf = 300;
    
    float result = 397.3;
    
    //(zeta = 1.142)
    
    Sphere s = new Sphere(0.025);
    float output = temp_at_time_at_point(s, mat, envmat, r, time, t_init, t_inf);
    
    assert( abs(output-result) < 0.01 );
}
