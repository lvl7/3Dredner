#include <calculation/gauss.h>
#include <calculation/numericalAnalysis.h>
#include <vtkPoints.h>
#include <vtkSmartPointer.h>
//#include <list>
#include <vector>

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
