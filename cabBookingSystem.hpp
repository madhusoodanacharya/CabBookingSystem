#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <random>
#include <time.h>

class coordinates{
    double latitude;
    double longitude;
    public:
        coordinates(double lat = 0, double lon = 0){
            latitude = lat;
            longitude = lon;
        }
        double distance(coordinates other);
        void random_coordinates();
        void print_coordinates();
};
