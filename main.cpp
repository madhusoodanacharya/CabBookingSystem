#include "HeadBackend.hpp"
#include "HeadFrontend.hpp"

int main(void)
{
    system("clear");
    coordinates myLocation;
    myLocation.random_coordinates();
    
    coordinates cabs[COORDINATE_LIMIT];
    load_coordinates(cabs);

    std::vector<coordinates> distance = closest5Cabs(cabs, myLocation);
    start(distance, myLocation);

    return 0;
}
