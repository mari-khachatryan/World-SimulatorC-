#include <iostream>


int getAir(bool light) {
    double oxygen{};
    std::cout << "the tree produs oxygen";
    while(oxygen < 50) {
       oxygen += 0.0001;
       std::cout << oxygen << std::endl;
    }
    return oxygen;
}