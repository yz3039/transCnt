#include <map>
#include <vector>
using namespace std;

map<string, vector<pair<float,float> > > mat_to_k {
    {"al", { {100, 302}, {200, 237}, {300, 237}, {400, 240}, {600, 231}, {800, 218} } },
    {"st", { {300, 60.5}, {400, 56.7}, {600, 48}, {800, 39.2}, {1000, 30} } } };


map<string, vector<pair<float,float> > > mat_to_c {
    {"al", { {100, 482}, {200, 798}, {300, 903}, {400, 949}, {600, 1033}, {800, 1146} } },
    {"st", { {300, 434}, {400, 487}, {600, 559}, {800, 685}, {1000, 1169} } } };

map<string, float> mat_to_h {
    {"air", 100},
    {"water", 1000} };

map<string, float> mat_to_density {
    {"al", 2702},
    {"st", 7854} };


// left to do: check if the requested temp is in range
float get_k(string mat, float temp){
    vector<pair<float,float> > pairs = mat_to_k[mat];
    
    pair<float,float> prev;
    for(auto it = pairs.begin(); it != pairs.end(); ++it){
        if( it->first < temp ){
            prev = *it;
        }else{
            return prev.second+(it->second - prev.second) * (temp-prev.first)/(it->first-prev.first);
        }
    }
    
    return -1;
}

float get_c(string mat, float temp){
    vector<pair<float,float>> pairs = mat_to_c[mat];
    
    pair<float,float> prev;
    for(auto it = pairs.begin(); it != pairs.end(); ++it){
        if( it->first < temp ){
            prev = *it;
        }else{
            return prev.second+(it->second - prev.second) * (temp-prev.first)/(it->first-prev.first);
        }
    }
    
    return -1;
}

float get_h(string envmat){
    return mat_to_h[envmat];
}

float get_density(string mat){
    return mat_to_density[mat];
}
