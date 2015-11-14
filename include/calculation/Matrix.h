#pragma once

#include <vector>
#include <iostream>
#include <string>

struct Coordinates {
    double x, y, z;
    Coordinates(double x_param, double y_param, double z_param): x(x_param), y(y_param), z(z_param) {};

};

class Matrix {
    std::vector<Coordinates> points;
    
public:
    void fill(std::string filename);
    void show();
    
};
