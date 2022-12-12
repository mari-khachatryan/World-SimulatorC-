#include <iostream>
#include <string>

void eatGrass(double air) {
    int weight{1};
    int size = 15;
    char grass[size] = "||||||||||||||||";
    std::cout << grass << std::endl;
    while(weight < 20) {
        char newGrass[size] = "";
        size--;
        for(int i = 0; i < size; ++i) {
            newGrass[i] = grass[i];
            newGrass[size] = '\0';
            std::cout << newGrass <<std::endl;
        }
        weight++;
    }
}