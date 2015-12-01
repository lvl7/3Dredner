#include <calculation/LineEdgeDetector.h>
#include <format/read.h>
#include <visualisation/Scene.h>
#include <vtkPoints.h>
#include <vtkSmartPointer.h>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {

	std::string filepath;
	double hoodDistance = 50;
	int numberOfPointsLine = 500;

	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " Filename[.xyz]" << std::endl;
		return 1;
	} else{
		filepath = argv[1];
//		hoodDistance = argv[2];
//		numberOfPointsLine = argv[3];
	}

	std::vector<unsigned int> line;

	vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
	read(filepath,points);

	LineEdgeDetector lineEdge(points,hoodDistance,numberOfPointsLine);
	line = lineEdge.getLineIndices();

	Scene scene;
	scene.show(points);

	std::cout << "main line size: " << line.size() << std::endl;
	if( scene.show(points, line) != 0 ){
		std::cerr << "show line error.\n";
	}

	return 0;
}
