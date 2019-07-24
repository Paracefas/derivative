#include <iostream>
#include "../differential.h"


int main(int argc, char const** argv) {
    auto f = [](double x, double y, double z) {
        return 2*pow(x,2) + y*x + pow(y,3)*z;
    };
    auto fx = paracefas::derivative(f, 0);
    auto fy = paracefas::derivative(f, 1);
    auto fz = paracefas::derivative(f, 2);

    std::cout << "\t\t\t|fx\t\t|fy\t\t|fz\n";
    for(double x = 0.0, y = 1.0, z = 2.0; x < 10.0 && y < 11.0 && z < 12.0; x+= 0.5, y+= 0.5, z+=0.5) {
        std::cout << "[ " << x << ", " << y << ", " << z << " ]:\t" << fx(x,y,z) << "\t" << fy(x,y,z) << "\t" << fz(x,y,z) << "\n";
    }
}