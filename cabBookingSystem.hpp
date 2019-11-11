#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <random>
#include <time.h>
#include <fstream>
#define COORDINATE_LIMIT 6443

class coordinates{
    double latitude;
    double longitude;
    std::string address;
    public:
        coordinates(double lat = 0, double lon = 0, std::string add = ""){
            latitude = lat;
            longitude = lon;
            address = add;
        }
        double distance(coordinates other);
        void random_coordinates();
        void print_coordinates();
        std::string get_address();
        double get_latitude();
        double get_longitude();
        void put_latitude(double);
        void put_longitude(double);
        void put_address(std::string);
};

void load_coordinates(coordinates []);