#include "cabBookingSystem.hpp"

// using namespace std;

int main(void)
{
    coordinates s(0,0,"something");
    s.random_coordinates();
    s.print_coordinates();

    coordinates cabs[COORDINATE_LIMIT];
    load_coordinates(cabs);
    double min = 100000000;
    std::string address;
    for(int i = 0; i<COORDINATE_LIMIT; i++){
        if(s.distance(cabs[i]) < min){
            min = s.distance(cabs[i]);
            address = cabs[i].get_address();
        }
    }
    std::cout<<min<<" "<<address<<std::endl;

    return 0;
}
