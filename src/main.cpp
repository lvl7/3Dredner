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
	double hoodDistance = 50;
	int numberOfPointsLine = 50;

	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " Filename[.xyz]" << std::endl;
		return 1;
	} else {
		filepath = argv[1];
//		hoodDistance = argv[2];
//		numberOfPointsLine = argv[3];
	}

//	//TODO -------
//	std::vector<std::vector<double>> vin(0, std::vector<double>(0));
//	std::vector<double> x;
//
//	std::vector<double> temp;
//	std::vector<double> temp2;
//	std::vector<double> temp3;
//	temp.push_back(2.3);
//	temp.push_back(3.25);
//	temp.push_back(52.1);
//	temp.push_back(57.455);
//	vin.push_back(temp);
//
//	temp.at(0) = 2.4;
//	temp.at(1) = 9.87;
//	temp.at(2) = 10.8;
//	temp.at(3) = 478;
//	vin.push_back(temp);
//
//	temp.at(0) = 5.4;
//	temp.at(1) = 11.87;
//	temp.at(2) = 16.8;
//	temp.at(3) = 154;
//	vin.push_back(temp);
//
//	std::cout << "vin\n";
//	for (unsigned int i = 0; i < vin.size(); ++i) {
//		std::cout << "row: " << i << std::endl;
//
//		for (unsigned int j = 0; j < vin.at(i).size(); ++j) {
//			std::cout << vin.at(i).at(j) << " ";
//		}
//		std::cout << std::endl;
//	}
//	std::cout << "=====" << endl;
//
//	//
////	for(unsigned int i = 0; i< vin.size(); ++i){
////
////		for(unsigned int j = 0; j< vin.at(i).size(); ++j){
////			vin.at(i).at(j) = i+j * (i+2)+1;
////		}
////	}
//	//	std::cout << "=====" << endl;
//	std::cout << "gauss:\n" << endl;
//
//	x = gauss(vin);
//	std::cout << "x:\n" << endl;
//
//	for (unsigned int i = 0; i < x.size(); ++i) {
//		std::cout << x.at(i) << " ";
//	}
//	std::cout << std::endl;
	//TODO =======











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
	scene.show(points, 1.5, color);

	// 2rad ~~ 120*
	LineEdgeDetector lineEdge(points, hoodDistance, numberOfPointsLine, 2);
	line = lineEdge.getLineIndices();
	color[0] = .7; // red
	color[1] = 0;
	color[2] = 0; // yellow
	scene.show(points, line, color);

	edgePoints1 = lineEdge.getEdgePoints();
	color[0] = 1;
	color[1] = 0;
	color[2] = 0;
	scene.showPoints(points, edgePoints1, 15, color);

//	LineEdgeDetector lineEdge2(points, hoodDistance, numberOfPointsLine, 2);
//	line2 = lineEdge2.getLineIndices();
//	color[0] = 0;
//	color[1] = .7; // green
//	color[3] = 0;
//	scene.show(points, line2, color);
//
//	edgePoints2 = lineEdge2.getEdgePoints();
//	color[0] = 0;
//	color[1] = 1;
//	color[2] = 0;
//	scene.showPoints(points, edgePoints2, 15, color);
//
//	LineEdgeDetector lineEdge3(points, hoodDistance, numberOfPointsLine, 2);
//	line3 = lineEdge3.getLineIndices();
//	color[0] = 0;
//	color[1] = 0;
//	color[2] = .7; //blue
//	scene.show(points, line3, color);
//
//	edgePoints3 = lineEdge3.getEdgePoints();
//	color[0] = 0;
//	color[1] = 0;
//	color[2] = 1;
//	scene.showPoints(points, edgePoints3, 15, color);


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


	polynomial = interpolationPolynomial(2, lineTemp);
	std::cout << "Polynomial(" << polynomial.size() << ")\n";
	for (unsigned int i = 0; i < polynomial.size(); ++i) {
		std::cout << polynomial.at(i) << " ";
	}

	lineTemp2 = polynomialVector2vtkPoints(0, -10, polynomial, 1, 3, 18, 0.5);

	color[0] = .7;
	color[1] = .7; // green
	color[3] = 0;
	scene.show(lineTemp2, 3, color );

	//TODO ==========




	return 0;
}
