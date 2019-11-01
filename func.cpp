#include <stdio.h>
#include "cabBookingSystem.hpp"
#include <cmath>

double coordinates::distance(coordinates other)
{
    //lat and longitude diff in radians
    double lat_diff = (other.latitude - latitude)*(M_PI/180.0);
    double lon_diff = (other.longitude - longitude)*(M_PI/180.0);

    //latitudes in radians
    double lat1 = latitude*(M_PI/180.0);
    double lat2 = other.latitude*(M_PI/180.0);

    double a = pow(sin(lat_diff / 2), 2) +  
                   pow(sin(lon_diff / 2), 2) *  
                   cos(lat1) * cos(lat2); 
    double earth_rad = 6371; 
    double c = 2 * asin(sqrt(a)); 
    return earth_rad * c; 
}
