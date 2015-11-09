
#include <visualisation/example/cube.h>
#include <visualisation/example/cylinder.h>
#include <visualisation/example/distanceBetweenPoints.h>
#include <iostream>

int main()
{
	showCylinder();
	std::cout << "byl pierwszy." << std::endl;
	distanceBetweenPoints();
	std::cout << "a teraz drugi." << std::endl;

	showCube();

	std::cout << "i trzeci." << std::endl;

	return 0;
}
