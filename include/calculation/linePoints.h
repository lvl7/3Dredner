#pragma once

#include <vtkPoints.h>
#include <vtkSmartPointer.h>
#include <vector>

/**
 * place - vector of 2 vector:
 * 0 vector - from
 * 1 vector - to
 *
 * from/to - vector of 3 elements:
 * 0 - x
 * 1 - y
 * 2 - z
 *
 * false - find min value
 * true - find max value
 *
 * minPoints - minimal number of points of line
 * maxPoints - maximal number of points of line
 *
 */
vtkSmartPointer<vtkPoints> computeLine(vtkSmartPointer<vtkPoints> pointsCuboid,
		std::vector<std::vector<bool>> place, int minPoints, int maxPoints, double maxError);

