
#include <visualisation/example/cube.h>
#include <visualisation/example/cylinder.h>
#include <visualisation/example/distanceBetweenPoints.h>
#include <iostream>
#include <calculation/Matrix.h>

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

    Matrix matrix;
    matrix.fill("../../../bridge2.xyz"); // TODO: change path
    matrix.show();
	return 0;
}
