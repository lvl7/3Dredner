//#include <calculation/gauss.h>
//#include <calculation/LineEdgeDetector.h>

#include <calculation/LineEdgeDetector.h>
#include <calculation/numericalAnalysis.h>
#include <format/read.h>
#include <visualisation/fromTo.h>
#include <visualisation/Scene.h>
#include <vtkPoints.h>
#include <vtkSmartPointer.h>
#include <iostream>
#include <string>
#include <vector>

//#include <vector>

int main(int argc, char *argv[]) {

	std::string filepath;

	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " Filename[.xyz]" << std::endl;
		return 1;
	} else {
		filepath = argv[1];
	}



	std::vector<unsigned int> line;
	std::vector<unsigned int> line2;
	std::vector<unsigned int> line3;

	std::vector<unsigned int> edgePoints1;
	std::vector<unsigned int> edgePoints2;
	std::vector<unsigned int> edgePoints3;

	vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
	read(filepath, points);

	Scene scene;
	double color[3] = { .8, .8, .8 };
	scene.showPoints(points, 1.5, color);


	//TODO ----------
	vtkSmartPointer<vtkPoints> lineTemp = vtkSmartPointer<vtkPoints>::New();
	vtkSmartPointer<vtkPoints> lineTemp2 = vtkSmartPointer<vtkPoints>::New();
	std::vector<double> polynomial;

	// good for 1 const axis;
	//	lineTemp->InsertNextPoint(1, 2, 8);
	//	lineTemp->InsertNextPoint(5, 6, 7);
	//	lineTemp->InsertNextPoint(4, -1, 1);
	//	lineTemp->InsertNextPoint(7, 2, 3);


		lineTemp->InsertNextPoint(4, 4, 8);
		lineTemp->InsertNextPoint(6, 5, 7);
		lineTemp->InsertNextPoint(8, 3, 1);
		lineTemp->InsertNextPoint(13, 4, 3);
		lineTemp->InsertNextPoint(18, 4, 3);


	polynomial = interpolationPolynomial(2, 1, lineTemp);
	std::cout << "Polynomial(" << polynomial.size() << ")\n";
	for (unsigned int i = 0; i < polynomial.size(); ++i) {
		std::cout << polynomial.at(i) << " ";
	}

	lineTemp2 = polynomialVector2vtkPoints(0, -10, polynomial, 1, 3, 18, 0.5);

	color[0] = .7;
	color[1] = .7; // green
	color[2] = 0;
	scene.showLine(lineTemp2, color);

	//TODO ==========




	return 0;
}
