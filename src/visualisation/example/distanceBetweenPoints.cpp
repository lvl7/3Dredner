/*
 * DistanceBetweenPoints.cpp
 *
 *  Created on: 09-11-2015
 *      Author: lvl7
 */

#include <vtkMath.h>
#include <cmath>
#include <iostream>

#include <visualisation/example/distanceBetweenPoints.h>


void distanceBetweenPoints()
{
  // Create two points.
  double p0[3] = {0.0, 0.0, 0.0};
  double p1[3] = {1.0, 1.0, 1.0};

  // Find the squared distance between the points.
  double squaredDistance = vtkMath::Distance2BetweenPoints(p0, p1);

  // Take the square root to get the Euclidean distance between the points.
  double distance = sqrt(squaredDistance);

  // Output the results.
  std::cout << "SquaredDistance = " << squaredDistance << std::endl;
  std::cout << "Distance = " << distance << std::endl;

}


