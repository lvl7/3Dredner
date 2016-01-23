#pragma once

#include <vtkPoints.h>
#include <vtkSmartPointer.h>
#include <vector>

/**
 * polynomial2vtkPoints show polynomial parallel to \arg\ wichAxisHeight \arg\ on axis height.
 *
 * wichAxisHeight:
 * 0 - x
 * 1 - y
 * 2 - z
 *
 * axis - wichAxis value ( height of line )
 *
 * polynomial - coefficients of polynomial. From highest to lowest power.
 *
 * wichAxisDomain:
 * 0 - x
 * 1 - y
 * 2 - z
 *
 */
vtkSmartPointer<vtkPoints> polynomialVector2vtkPoints(int wichAxisHeight,
		double axisHeight, std::vector<double> polynomial, int wichAxisDomain,
		double from, double to, double samplingDistance);
