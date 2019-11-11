#include "cabBookingSystem.hpp"

double coordinates::distance(coordinates other) const
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
    const double my_latitudes[5] = {33.74854485, 32.3217, 40.479457, 28.65629508, 25.7886437};
    const double my_longitudes[5] = {-117.5419695, -110.819687, -74.26939, -81.24822669, -80.21450739};
    const std::string my_address[5] = {"Orange Unified School District, CA, USA",
                                        "Pima County, AZ, USA",
                                        "Keenan Way, South Amboy, NJ 08879, USA",
                                        "Needlewood Loop, FL 32765, USA",
                                        "1475 NW 12th Ave, Miami, FL 33136, USA"};
    srand(time(0));
    int random = rand()%5;
    latitude = my_latitudes[random];
    longitude = my_longitudes[random];
    address = my_address[random];
}

void coordinates::print_coordinates()
{
    std::cout<<latitude<<", "<<longitude<<" ("<<address<<")"<<"\n";
}

std::string coordinates::get_address()
{
    return address;
}

double coordinates::get_latitude()
{
    return latitude;
}

double coordinates::get_longitude()
{
    return longitude;
}

void load_coordinates(coordinates cabs[])
{
    std::ifstream f;
    f.open("coordinates.csv");
    std::string line;
    getline(f, line);
    for(int i = 0; i<COORDINATE_LIMIT; i++){
        getline(f, line);
        std::string temp, data[3];
        int count = 0;
        for(char c : line){
            if(c == ','){
                data[count] = temp;
                temp = "";
                count++;
            }
            else
                temp += c;
            if(count == 2){
                data[count] = temp;
            }
        }
        coordinates tempCoor(std::stod(data[0]), std::stod(data[1]), data[2]);
        cabs[i] = tempCoor;
    }
    f.close();

}

std::vector<coordinates> closest5Cabs(const coordinates cabs[],const coordinates myLocation)
{
    std::vector<coordinates> distance;
    double prev_min = 0;
    for(int i = 0; i<5; i++){
        double min = 1000000000;
        coordinates temp;
        for(int j = 0; j<COORDINATE_LIMIT; j++){
            if(myLocation.distance(cabs[j]) < min && myLocation.distance(cabs[j]) > prev_min){
                min = myLocation.distance(cabs[j]);
                temp = cabs[j];
            }
        }
        prev_min = min;
        distance.push_back(temp);
    }
    return distance;
}
