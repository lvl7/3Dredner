#include <calculation/gauss.h>
#include <calculation/numericalAnalysis.h>
#include <vtkPoints.h>
#include <vtkSmartPointer.h>
#include <cmath>
#include <vector>
#include <iostream>

/**
 * ignored axis =
 * 0 - x
 * 1 - y
 * 2 - z
 */
std::vector<double> interpolationPolynomial(int domain, int codomain,
		vtkSmartPointer<vtkPoints> line) {

	// for interpolation
	std::vector<std::vector<double>> matrix(line->GetNumberOfPoints(),
			std::vector<double>(line->GetNumberOfPoints() + 1));
	std::vector<double> temp(line->GetNumberOfPoints() + 1);


	if(domain == codomain){
 		throw "Wrong axis ( interpolation ).\n";
	}

	for (int nop = 0; nop < line->GetNumberOfPoints(); ++nop) {
		for (int coor = 0; coor < line->GetNumberOfPoints(); ++coor) {
			matrix.at(nop).at(coor) = pow(line->GetPoint(nop)[domain], line->GetNumberOfPoints()-coor-1);

		}
		matrix.at(nop).at(line->GetNumberOfPoints()) =
				line->GetPoint(nop)[codomain];
	}

	return gauss(matrix);
}


double lagrangeInterpolation(int domain, int codomain,
                             vtkSmartPointer<vtkPoints> line, double atValue)
{
    if(domain == codomain)
    {
        std::cerr << "Wrong axis given to lagrange interpolation" << std::endl;
    }
    
    auto noOfPoints = line->GetNumberOfPoints();
    
    double lagrangeAtValue = 0;
    
    for (auto i = 0; i < noOfPoints; ++i)
    {
        double li = 1;
        
        for (auto j = 0; j < noOfPoints; ++j)
        {
            if (i == j)
            {
                continue;
            }
            
            li *= (atValue - line->GetPoint(j)[domain]) / (line->GetPoint(i)[domain] - line->GetPoint(j)[domain]);
            
        }
        
        lagrangeAtValue += line->GetPoint(i)[codomain] * li;
        
    }
    
    return lagrangeAtValue;
}