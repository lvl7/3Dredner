#pragma once

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
	std::vector<unsigned int> edgePoints;

	double maxDistanceSquared;
	unsigned int numberOfPoints;

	double angleOfEdge;

	int findLine();
	/**
	 * <index of neighbour, distance>
	 */
	std::vector<std::pair<int, double>> findHood(
			unsigned int indexOfCenterPoint);

public:
	LineEdgeDetector(vtkPoints *points, double maxDistanceSquared,
			unsigned int numberOfPoints, double angleOfEdge) :
			maxDistanceSquared(maxDistanceSquared), numberOfPoints(
					numberOfPoints), angleOfEdge(angleOfEdge) {

		this->points = points;

		findLine();
	}

	std::vector<unsigned int> getLineIndices() {
		return this->lineIndices;
	}

	std::vector<unsigned int> getEdgePoints() {
		return this->edgePoints;
	}

};

