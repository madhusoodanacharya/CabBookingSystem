#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "cabBookingSystem.hpp"

// using namespace std;

int main(void)
{
    coordinates c(51.5007, 0.1246);
    coordinates o(40.6892, 74.0445);
    std::cout<<c.distance(o)<<"\n";

    return 0;
}
