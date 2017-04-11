#include <math.h>
#include <iostream>
#include "calculation.h"

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
    
    Sphere s = Sphere(0.025);
    float output = temp_at_time_at_point(s, mat, envmat, r, time, t_init, t_inf);
    
    cout << output << endl;
    //assert( abs(output-result) < 0.01 );


    PlaneWall pl = PlaneWall(0.001);
    output = temp_at_time_at_point(pl, mat, envmat, 0.0005, 10, t_init, t_inf);
    cout << output << endl;

    InfiniteCylinder ic = InfiniteCylinder(0.001);
    output = temp_at_time_at_point(ic, mat, envmat, 0.0005, 10, t_init, t_inf);
    cout << output << endl;

    Sphere s2 = Sphere(0.001);
    output = temp_at_time_at_point(s2, mat, envmat, 0.0005, 5, t_init, t_inf);
    cout << output << endl;
}
