#include <iostream>
#include <string>
#include "prototypes.h"

void frogLife(double air) {

    std::string right{};
    std::string left{};
    do{
        air -= 0.01;
        eatGrass(air);
        std::string frog = "^(*)^";
        std::cout << "frog run left and right and eating";
        if(air < 25) {
            frog = "^(*)^";
            right += " ";
            std::cout << right << frog << std::endl;
        } else {
            frog = "^(*)^";
            left += " ";
            std::cout << left << frog << std::endl;
        }
    } while (air > 0);
    std::cout << "Frog is sleaping\n";
}