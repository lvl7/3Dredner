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
std::vector<double> interpolationPolynomial(int axis,
		vtkSmartPointer<vtkPoints> line) {

//	std::vector<double> polynomial; // vector of coefficients
	std::vector<unsigned int> axes(2);
	// for interpolation
	std::vector<std::vector<double>> matrix(line->GetNumberOfPoints(),
			std::vector<double>(line->GetNumberOfPoints() + 1));
	std::vector<double> temp(line->GetNumberOfPoints() + 1);

	switch (axis) {
	case 0:
		axes.at(0) = 1;
		axes.at(1) = 2;
		break;
	case 1:
		axes.at(0) = 0;
		axes.at(1) = 2;
		break;
	case 2:
		axes.at(0) = 0;
		axes.at(1) = 1;
		break;
	default:
		throw "Wrong axis.\n";
	}

	for (int nop = 0; nop < line->GetNumberOfPoints(); ++nop) {
		for (int coor = 0; coor < line->GetNumberOfPoints(); ++coor) {
			matrix.at(nop).at(coor) = pow(line->GetPoint(nop)[axes.at(0)], line->GetNumberOfPoints()-coor-1);

		}
		matrix.at(nop).at(line->GetNumberOfPoints()) =
				line->GetPoint(nop)[axes.at(1)];
	}

	//TODO ---------
	std::cout << "vin\n";
	for (unsigned int i = 0; i < matrix.size(); ++i) {

		for (unsigned int j = 0; j < matrix.at(i).size(); ++j) {
			std::cout << matrix.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "=====" << endl;

	//TODO =========

	return gauss(matrix);
}
