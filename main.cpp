#include "cabBookingSystem.hpp"

// using namespace std;

int main(void)
{
    coordinates myLocation(0,0,"something");
    myLocation.random_coordinates();
    myLocation.print_coordinates();

    coordinates cabs[COORDINATE_LIMIT];
    load_coordinates(cabs);

    std::vector<coordinates> distance = closest5Cabs(cabs, myLocation);
    for(auto i : distance){
        i.print_coordinates();
        std::cout<<myLocation.distance(i)<<std::endl;
    }

    return 0;
}
