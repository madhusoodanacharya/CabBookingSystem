#include "cabBookingSystem.hpp"

// using namespace std;

int main(void)
{
    coordinates c(25.8886, -80.1145);
    coordinates o(25.7886, -80.2145);
    std::cout<<c.distance(o)<<"\n";
    coordinates s;
    s.random_coordinates();
    s.print_coordinates();

    return 0;
}
