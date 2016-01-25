#pragma once

#include <vtkPoints.h>
#include <vtkSmartPointer.h>
#include <vector>

/**
 *
 * domain, codomain axis =
 * 0 - x
 * 1 - y
 * 2 - z
 */
std::vector<double> interpolationPolynomial(int domain, int codomain,
		vtkSmartPointer<vtkPoints> line);

double lagrangeInterpolation(int domain, int codomain,
                                          vtkSmartPointer<vtkPoints> line, double atValue);

std::vector<double> approximation(int domain, int codomain,
		vtkSmartPointer<vtkPoints> linePoints, unsigned int degreeOfPolynomial);
