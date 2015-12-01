#include <vtkPoints.h>
#include <vtkSmartPointer.h>
#include <iostream>
//#include <map>
#include <utility>
#include <vector>

class LineEdgeDetector {
	/**
	 * all object points
	 */
	vtkSmartPointer<vtkPoints> points;
	/**
	 * chosen index of points making line
	 */
	std::vector<unsigned int> lineIndices;

	double maxDistanceSquared;
	unsigned int numberOfPoints;

	int findLine();
	/**
	 * <index of neighbour, distance>
	 */
	std::vector<std::pair<int, double>> findHood(
			unsigned int indexOfCenterPoint);

public:
	LineEdgeDetector(vtkPoints *points, double maxDistanceSquared,
			unsigned int numberOfPoints) :
				maxDistanceSquared(maxDistanceSquared), numberOfPoints(numberOfPoints) {

		this->points = points;

		findLine();
	}

	std::vector<unsigned int> getLineIndices() {
		return lineIndices;
	}

};

