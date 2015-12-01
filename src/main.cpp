#include <calculation/angle.h>
#include <calculation/LineEdgeDetector.h>
#include <format/read.h>
//#include <visualisation/example/cube.h>
//#include <visualisation/example/cylinder.h>
//#include <visualisation/example/distanceBetweenPoints.h>
#include <visualisation/Scene.h>
#include <vtkPoints.h>
#include <vtkSmartPointer.h>
#include <iostream>
#include <string>
#include <vector>

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

	std::vector<unsigned int> line;
	std::vector<unsigned int> line2;
	std::vector<unsigned int> line3;

	vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
	read(filepath, points);

	LineEdgeDetector lineEdge(points, hoodDistance, numberOfPointsLine);
	line = lineEdge.getLineIndices();

	Scene scene;
	scene.show(points);

	std::cout << "main line size: " << line.size() << std::endl;
	double lineColor[3] = { 1, 0, 0 };
	if (scene.show(points, line, lineColor) != 0) {
		std::cerr << "show line error.\n";
	}

	LineEdgeDetector lineEdge2(points, hoodDistance, numberOfPointsLine);
	line2 = lineEdge2.getLineIndices();

	std::cout << "main line size: " << line.size() << std::endl;
	lineColor[0] = 0;
	lineColor[1] = 1; // green
	if (scene.show(points, line2, lineColor) != 0) {
		std::cerr << "show line error.\n";
	}

	LineEdgeDetector lineEdge3(points, hoodDistance, numberOfPointsLine);
	std::cout << "main line size: " << line.size() << std::endl;
	line3 = lineEdge3.getLineIndices();
	lineColor[1] = 0;
	lineColor[2] = 1; //blue

	if (scene.show(points, line3, lineColor) != 0) {
		std::cerr << "show line error.\n";
	}


	Coordinates A(3, 2, 1);
	Coordinates B(3, 8, 7);
	Coordinates C(3, 3, 9);

	getAngle(A, B, C);

	return 0;
}
