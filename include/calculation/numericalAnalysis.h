#pragma once

#include <vtkPoints.h>
#include <vtkSmartPointer.h>
#include <vector>

/**
 * ignored axis =
 * 0 - x
 * 1 - y
 * 2 - z
 */
std::vector<double> interpolationPolynomial(int axis,
		vtkSmartPointer<vtkPoints> line);
