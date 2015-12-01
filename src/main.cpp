
#include <visualisation/example/cube.h>
#include <visualisation/example/cylinder.h>
#include <visualisation/example/distanceBetweenPoints.h>

#include <calculation/angle.h>
#include <iostream>

int main()
{

    Coordinates A(3, 2, 1);
    Coordinates B(3, 8, 7);
    Coordinates C(3, 3, 9);
    
    getAngle(A, B, C);
    
    return 0;
}
