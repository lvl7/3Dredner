
#include <visualisation/example/cube.h>
#include <visualisation/example/cylinder.h>
#include <visualisation/example/distanceBetweenPoints.h>
#include <iostream>
#include <calculation/Points.h>

int main()
{
//	showCylinder();
//	std::cout << "byl pierwszy." << std::endl;
//	distanceBetweenPoints();
//	std::cout << "a teraz drugi." << std::endl;
//
//	showCube();
//
//	std::cout << "i trzeci." << std::endl;

    Points points;
    points.fill("../../../bridge2.xyz"); // TODO: change path
    points.show();
	return 0;
}
