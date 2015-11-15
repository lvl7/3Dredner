#pragma once

#include <calculation/Coordinates.h>
#include <vector>
#include <iostream>
#include <string>


class Points {
    std::vector<Coordinates> points;
    
public:
    void fill(std::string filename);
    void show();
    
};
