#include <vector>
#include <string>

using namespace std;

class Sphere;
class PlaneWall;
class InfiniteCylinder;
class RectangularParallelepiped;
class Cylinder;
class InfiniteRectangularBar;
class SemiInfinitePlate;

extern const float PI;

/**
void temp_at_time(vector<float>* ret, Sphere s, string mat, string envmat, 
    vector<float>& points, float time, float t_init, float t_inf);
**/

float temp_at_time_at_point(Sphere s, string mat, string envmat, 
    float r, float time, float t_init, float t_inf);

float temp_at_time_at_point(PlaneWall w, string mat, string envmat, 
    float x, float time, float t_init, float t_inf);

float temp_at_time_at_point(InfiniteCylinder cylinder, string mat, string envmat, 
    float x, float time, float t_init, float t_inf);

float temp_at_time_at_point(RectangularParallelepiped rp, string mat, string envmat, 
    float x1, float x2, float x3, float time, float t_init, float t_inf);

float temp_at_time_at_point(Cylinder cylinder, string mat, string envmat, 
    float r, float x, float time, float t_init, float t_inf);

float temp_at_time_at_point(InfiniteRectangularBar irb, string mat, string envmat, 
    float x1, float x2, float time, float t_init, float t_inf);

float temp_at_time_at_point(SemiInfinitePlate sip, string mat, string envmat, 
    float x1, float x2, float time, float t_init, float t_inf);