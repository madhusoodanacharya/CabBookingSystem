#include "cabBookingSystem.hpp"

double coordinates::distance(coordinates other)
{
    //lat and longitude diff in radians
    double lat_diff = (other.latitude - latitude)*(M_PI/180.0);
    double lon_diff = (other.longitude - longitude)*(M_PI/180.0);

    //latitudes in radians
    double lat1 = latitude*(M_PI/180.0);
    double lat2 = other.latitude*(M_PI/180.0);
    
    //using haversine formula
    double a = pow(sin(lat_diff / 2), 2) +  
                   pow(sin(lon_diff / 2), 2) *  
                   cos(lat1) * cos(lat2); 
    double earth_rad = 6371; 
    double c = 2 * asin(sqrt(a)); 
    return earth_rad * c; 
}

void coordinates::random_coordinates()
{
    //latitude and longitude ranges to be in America
    const double lat_max = 19.6512;
    const double lat_min = 64.8522227;
    const double lon_max = -68.74260283;
    const double lon_min = -159.396274;

    //creating random double values for latitude using STL C++
    std::uniform_real_distribution<double> unif(lat_min, lat_max);
    std::default_random_engine ran_lat;
    double random_latitude = unif(ran_lat);
    //assigning random value to object value
    latitude = random_latitude;
    //creating random double values for longitude using STL C++
    std::uniform_real_distribution<double> unif1(lon_min, lon_max);
    std::default_random_engine ran_lon;
    double random_longitude = unif1(ran_lon);
    //assigning random value to object value
    longitude = random_longitude;
}

void coordinates::print_coordinates()
{
    std::cout<<latitude<<", "<<longitude<<"\n";
}