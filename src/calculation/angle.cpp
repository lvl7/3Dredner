#include <calculation/angle.h>
#include <iostream>
#include <math.h>

double getAngle(Coordinates A, Coordinates B, Coordinates C)
{
    // returns an angle [rad] between vectors BA and BC
    Coordinates BA(A.x - B.x, A.y - B.y, A.z - B.z);
    Coordinates BC(C.x - B.x, C.y - B.y, C.z - B.z);
    std::cout << C.x << " " << B.x << " ";
    
    double BAMagnitude = sqrt(BA.x * BA.x + BA.y * BA.y + BA.z * BA.z);
    Coordinates BANorm(BA.x / BAMagnitude, BA.y / BAMagnitude, BA.z / BAMagnitude);
    
    double BCMagnitude = sqrt(BC.x * BC.x + BC.y * BC.y + BC.z * BC.z);
    Coordinates BCNorm(BC.x / BCMagnitude, BC.y / BCMagnitude, BC.z / BCMagnitude);
    
    double res = BANorm.x * BCNorm.x + BANorm.y * BCNorm.y + BANorm.z * BCNorm.z;
    
    
    double angle = acos(res);
    std::cout << "Angle: " << angle;
    
    return angle;
}
