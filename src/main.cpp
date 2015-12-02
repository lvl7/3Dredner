//#include <calculation/angle.h>
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



	LineEdgeDetector lineEdge2(points, hoodDistance, numberOfPointsLine, 2);
	line2 = lineEdge2.getLineIndices();
	color[0] = 0;
	color[1] = .7; // green
	color[3] = 0;
	scene.show(points, line2, color);

	edgePoints2 = lineEdge2.getEdgePoints();
	color[0] = 0;
	color[1] = 1;
	color[2] = 0;
	scene.showPoints(points, edgePoints2, 15, color);


	LineEdgeDetector lineEdge3(points, hoodDistance, numberOfPointsLine, 2);
	line3 = lineEdge3.getLineIndices();
	color[0] = 0;
	color[1] = 0;
	color[2] = .7; //blue
	scene.show(points, line3, color);

	edgePoints3 = lineEdge3.getEdgePoints();
	color[0] = 0;
	color[1] = 0;
	color[2] = 1;
	scene.showPoints(points, edgePoints3, 15, color);


	return 0;
}
