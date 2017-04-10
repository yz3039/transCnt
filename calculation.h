#include <vector>
#include <string>
using namespace std;
class Sphere;
extern const float PI;

void temp_at_time(vector<float>* ret, Sphere s, string mat, string envmat, 
    vector<float>& points, float time, float t_init, float t_inf);

float temp_at_time_at_point(Sphere s, string mat, string envmat, 
    float r, float time, float t_init, float t_inf);

