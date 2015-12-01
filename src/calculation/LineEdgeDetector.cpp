#include <calculation/LineEdgeDetector.h>
#include <vtkMath.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>

/**
 * return:
 * 	2 - end of line before reach numberOfPoint
 */
int LineEdgeDetector::findLine() {
	srand(time(NULL));

	unsigned int centerHoodIndex = random() % this->points->GetNumberOfPoints();
	unsigned int centerHoodPreviousIndex;
	unsigned int centerHoodNextIndex;

	double tempPoint1[3];
	double tempPoint2[3];

	double tempDistance;

//	std::vector<std::pair<int, double>> hoodPrevious;
	std::vector<std::pair<int, double>> hood;

	hood = findHood(centerHoodIndex);
	lineIndices.push_back(centerHoodIndex);

	if (hood.size() < 1) {
		return EXIT_FAILURE;
	}

//	hoodPrevious = hood;
	centerHoodPreviousIndex = centerHoodIndex;

	centerHoodIndex = hood.at(0).first;
	double lastDistance = hood.at(0).second;

	// first line
	for (unsigned int i = 0; i < hood.size(); ++i) {
		if (hood.at(i).second > lastDistance) {
			lastDistance = hood.at(i).second;
			centerHoodIndex = hood.at(i).first;
		}
	}

	hood = findHood(centerHoodIndex);
	lineIndices.push_back(centerHoodIndex);

	// < 2 avoid come back to previous hood
	if (hood.size() < 2) {
		return 2;
	}

	for (unsigned int i = 0; i < this->numberOfPoints; ++i) {

		//find the farest point from hood to previous center point.
		this->points->GetPoint(centerHoodIndex, tempPoint1);
		this->points->GetPoint(centerHoodPreviousIndex, tempPoint2);

		lastDistance = vtkMath::Distance2BetweenPoints(tempPoint1, tempPoint2);

		for (unsigned int i = 0; i < hood.size(); ++i) {
			this->points->GetPoint(hood.at(i).first, tempPoint1);
			this->points->GetPoint(centerHoodPreviousIndex, tempPoint2);

			// if squared distance between center of previous hood and member of hood > lastDistance
			if ((tempDistance = vtkMath::Distance2BetweenPoints(tempPoint1,
					tempPoint2)) > lastDistance) {

				lastDistance = tempDistance;
				centerHoodNextIndex = hood.at(i).first;
			}
		}

		centerHoodPreviousIndex = centerHoodIndex;
		centerHoodIndex = centerHoodNextIndex;
		hood = findHood(centerHoodIndex);
		lineIndices.push_back(centerHoodIndex);
	}

//	for (unsigned int i = 0; i < hood.size(); ++i) {
//		lineIndices.push_back(hood.at(i).first);
//	}

	return EXIT_SUCCESS;
}

//TODO it chose centerPoint like neighbour of centerPoint/
std::vector<std::pair<int, double>> LineEdgeDetector::findHood(
		unsigned int indexOfCenterPoint) {

	bool check;
	std::vector<std::pair<int, double>> hood;
	double distanceSquared;

	// x y z
	double point[3];
	this->points->GetPoint(indexOfCenterPoint, point);

	//TODO chagne to for each
	for (unsigned int i = 0; i < this->points->GetNumberOfPoints(); ++i) {

		double temp[3];
		this->points->GetPoint(i, temp);

		// fiter only
		check = true;
		for (int j = 0; j < 3; ++j) {
			// filter points
			if (point[j] + this->maxDistanceSquared < temp[j]
					|| point[j] - this->maxDistanceSquared > point[j]) {

				check = false;
				break;
			}
		}
		if (check) {
			//Distance2BetweenPoints() return squared distance
			if ((distanceSquared = vtkMath::Distance2BetweenPoints(temp, point))
					< this->maxDistanceSquared) {

				std::pair<int, double> temp;
				temp.first = i;
				temp.second = distanceSquared;

				hood.push_back(temp);
			}
		}
	}
	return hood;
}
