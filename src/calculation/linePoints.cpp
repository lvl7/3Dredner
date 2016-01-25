#include <calculation/linePoints.h>
#include <vtkMath.h>
#include <vtkPoints.h>
#include <vtkSmartPointer.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

vtkSmartPointer<vtkPoints> computeLine(vtkSmartPointer<vtkPoints> pointsCuboid,
		std::vector<std::vector<bool>> place, int minPoints, int maxPoints, double maxError) {


	if (place.size() != 2) {
		throw "Wrong number of vector. (getLine)\n";
	} else if (minPoints > maxPoints) {
		throw "MaxPoints must be greater than minPoints.\n";
	} else if (minPoints < 2) {
		throw "MinPoints must be greater than 2.\n";
	}

	for (unsigned int i = 0; i < place.size(); ++i) {
		if (place.at(i).size() != 3)
			throw "Wrong number of conditions. (getLine)\n";
	}

	vtkSmartPointer<vtkPoints> line = vtkSmartPointer<vtkPoints>::New();

	double from[3] = { pointsCuboid->GetPoint(0)[0], pointsCuboid->GetPoint(0)[1],
			pointsCuboid->GetPoint(0)[2] };
	double to[3] = { from[0], from[1], from[2] };

	for (int i = 0; i < pointsCuboid->GetNumberOfPoints(); ++i) {
		for (int c = 0; c < 3; ++c) { // x, y, z

			if (place.at(0).at(c)) { // find max form
				if (pointsCuboid->GetPoint(i)[c] > from[c])
					from[c] = pointsCuboid->GetPoint(i)[c];

			} else { // find min from
				if (pointsCuboid->GetPoint(i)[c] < from[c])
					from[c] = pointsCuboid->GetPoint(i)[c];
			}

			if (place.at(1).at(c)) { // find to
				if (pointsCuboid->GetPoint(i)[c] > to[c])
					to[c] = pointsCuboid->GetPoint(i)[c];

			} else { // find min to
				if (pointsCuboid->GetPoint(i)[c] < to[c])
					to[c] = pointsCuboid->GetPoint(i)[c];
			}
		}
	}

//	std::cout << "from: " << from[0] << " " << from[1] << " " << from[2] << std::endl;
//	std::cout << "to: " << to[0] << " " << to[1] << " " << to[2] << std::endl;

	int noPoints = rand()%(maxPoints - minPoints) + minPoints;

	// make line
	double partDistance;
	srand(time( NULL));
	for (int i = 0; i < noPoints; ++i) {
		partDistance = (rand() % 1000) / 1000.0;

		line->InsertNextPoint(
				from[0] + partDistance * (to[0] - from[0]) + ((rand()%1000/1000.0)*2-1) * maxError,
				from[1] + partDistance * (to[1] - from[1]) + ((rand()%1000/1000.0)*2-1) * maxError,
				from[2] + partDistance * (to[2] - from[2]) + ((rand()%1000/1000.0)*2-1) * maxError);

//		std::cout << partDistance << " " << line->GetPoint(i)[0] << " "
//				<< line->GetPoint(i)[1] << " " << line->GetPoint(i)[2]
//				<< std::endl;
	}

	return line;
}
