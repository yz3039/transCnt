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
     
    float output;
    //(zeta = 1.142)
    
    // Sphere s = Sphere(0.025);
    // output = temp_at_time_at_point(s, mat, envmat, r, time, t_init, t_inf);
    
    // cout << output << endl;
    // //assert( abs(output-result) < 0.01 );

    // Sphere s2 = Sphere(0.001);
    // output = temp_at_time_at_point(s2, mat, envmat, 0.0005, 5, t_init, t_inf);
    // cout << output << endl;

    // Sphere s3 = Sphere(0.01);
    // output = temp_at_time_at_point(s3, mat, envmat, 0.005, 10, t_init, t_inf);
    // cout << output << endl;

    // Sphere s4 = Sphere(0.1);
    // output = temp_at_time_at_point(s4, mat, envmat, 0.05, 100, t_init, t_inf);
    // cout << output << endl;


    // PlaneWall pl = PlaneWall(0.001);
    // output = temp_at_time_at_point(pl, mat, envmat, 0.0005, 10, t_init, t_inf);
    // cout << output << endl;

    PlaneWall pl2 = PlaneWall(0.01);
    output = temp_at_time_at_point(pl2, mat, envmat, 0.005, 10, t_init, t_inf);
    cout << output << endl;

    PlaneWall pl3 = PlaneWall(0.1);
    output = temp_at_time_at_point(pl3, mat, envmat, 0.05, 100, t_init, t_inf);
    cout << output << endl;

    // InfiniteCylinder ic = InfiniteCylinder(0.001);
    // output = temp_at_time_at_point(ic, mat, envmat, 0.0005, 10, t_init, t_inf);
    // cout << output << endl;


}
