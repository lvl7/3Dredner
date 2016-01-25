//#include <calculation/gauss.h>
//#include <calculation/LineEdgeDetector.h>

#include <calculation/linePoints.h>
#include <calculation/numericalAnalysis.h>
#include <format/read.h>
#include <visualisation/fromTo.h>
#include <visualisation/Scene.h>
#include <vtkPoints.h>
#include <vtkSmartPointer.h>
#include <exception>
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
	double colorPoints[3] = { .7, .7, 0 };
	double colorLine[3] = { 0 , .7, .7 };
    double colorApproximatedLine[3] = {.2 , 5, .7};
	vtkSmartPointer<vtkPoints> lineInterpolation;
	vtkSmartPointer<vtkPoints> lineLineFromTo;
    vtkSmartPointer<vtkPoints> lineApproximated = vtkSmartPointer<vtkPoints>::New();

	int axisDomain;
	int axisCodomain;
	int axisConst;
	double height;
	double from;
	double to;
	double maxError = 0.3;
	double degreeOfApproximatedPolinomial = 1;

	std::vector<double> polynomial;
	std::vector<double> polynomialApproximated;
	std::vector<std::vector<bool>> positionFromTo(2, std::vector<bool>(3));

	axisDomain = 0;
	axisCodomain = 1;
	axisConst = 2;
	positionFromTo.at(0).at(0) = false;
	positionFromTo.at(0).at(1) = false;
	positionFromTo.at(0).at(2) = false;
	positionFromTo.at(1).at(0) = true;
	positionFromTo.at(1).at(1) = false;
	positionFromTo.at(1).at(2) = false;

	height = 10;
	from = -15;
	to = 15;

	lineLineFromTo = computeLine(points, positionFromTo, 2, 6, maxError);
	scene.showPoints(lineLineFromTo, 10, colorPoints);

	polynomial = interpolationPolynomial(axisDomain, axisCodomain, lineLineFromTo);
	try {
		lineInterpolation = polynomialVector2vtkPoints(axisConst, height, polynomial, axisDomain, from, to,
				0.5);
	} catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}

	scene.showLine(lineInterpolation, colorLine);
    
    vtkSmartPointer<vtkPoints> lineLagrangeInterpolation = vtkSmartPointer<vtkPoints>::New();
    
    for (double i = from; i <= to; i += 0.5)
    {
        lineLagrangeInterpolation->InsertNextPoint(i, lagrangeInterpolation(axisDomain, axisCodomain, lineLineFromTo, i), height);
    }

    double lagrangeInterpolationLineColor[3] = {.7 , 0, .7};

    scene.showLine(lineLagrangeInterpolation, lagrangeInterpolationLineColor);


    polynomialApproximated = approximation(axisDomain, axisCodomain, lineLineFromTo, degreeOfApproximatedPolinomial);
    lineApproximated = polynomialVector2vtkPoints(axisConst, height, polynomialApproximated, axisDomain, from, to,
			0.5);
    scene.showLine(lineApproximated, colorApproximatedLine);











//----from (-10,10,10)
	axisDomain = 1;
	axisCodomain = 0;
	axisConst = 2;
	positionFromTo.at(0).at(0) = false;
	positionFromTo.at(0).at(1) = false;
	positionFromTo.at(0).at(2) = false;
	positionFromTo.at(1).at(0) = false;
	positionFromTo.at(1).at(1) = true;
	positionFromTo.at(1).at(2) = false;

	height = 10;
	from = 5;
	to = 25;

	lineLineFromTo = computeLine(points, positionFromTo, 2, 6, maxError);
	scene.showPoints(lineLineFromTo, 10, colorPoints);

	polynomial = interpolationPolynomial(axisDomain, axisCodomain, lineLineFromTo);
	try {
		lineInterpolation = polynomialVector2vtkPoints(axisConst, height, polynomial, axisDomain, from, to,
				0.5);
	} catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}

	scene.showLine(lineInterpolation, colorLine);
    
    lineLagrangeInterpolation->Delete();
    
    lineLagrangeInterpolation = vtkSmartPointer<vtkPoints>::New();
    
    for (double i = from; i <= to; i += 0.5)
    {
        lineLagrangeInterpolation->InsertNextPoint(lagrangeInterpolation(axisDomain, axisCodomain, lineLineFromTo, i), i, height);
    }
    
    scene.showLine(lineLagrangeInterpolation, lagrangeInterpolationLineColor);


    polynomialApproximated = approximation(axisDomain, axisCodomain, lineLineFromTo, degreeOfApproximatedPolinomial);
    lineApproximated = polynomialVector2vtkPoints(axisConst, height, polynomialApproximated, axisDomain, from, to,
			0.5);
    scene.showLine(lineApproximated, colorApproximatedLine);




	axisDomain = 2;
	axisCodomain = 1;
	axisConst = 0;
	positionFromTo.at(0).at(0) = false;
	positionFromTo.at(0).at(1) = false;
	positionFromTo.at(0).at(2) = false;
	positionFromTo.at(1).at(0) = false;
	positionFromTo.at(1).at(1) = false;
	positionFromTo.at(1).at(2) = true;

	height = -10;
	from = 5;
	to = 45;

	lineLineFromTo = computeLine(points, positionFromTo, 2, 6, maxError);
	scene.showPoints(lineLineFromTo, 10, colorPoints);

	polynomial = interpolationPolynomial(axisDomain, axisCodomain, lineLineFromTo);
	try {
		lineInterpolation = polynomialVector2vtkPoints(axisConst, height, polynomial, axisDomain, from, to,
				0.5);
	} catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}

	scene.showLine(lineInterpolation, colorLine);
    
    lineLagrangeInterpolation->Delete();
    
    lineLagrangeInterpolation = vtkSmartPointer<vtkPoints>::New();
    
    for (double i = from; i <= to; i += 0.5)
    {
        lineLagrangeInterpolation->InsertNextPoint(height, lagrangeInterpolation(axisDomain, axisCodomain, lineLineFromTo, i), i);
    }
    
    scene.showLine(lineLagrangeInterpolation, lagrangeInterpolationLineColor);
    

    polynomialApproximated = approximation(axisDomain, axisCodomain, lineLineFromTo, degreeOfApproximatedPolinomial);
    lineApproximated = polynomialVector2vtkPoints(axisConst, height, polynomialApproximated, axisDomain, from, to,
			0.5);
    scene.showLine(lineApproximated, colorApproximatedLine);
//=====from (-10,10,10)


//----from (10,20,40)
	axisDomain = 2;
	axisCodomain = 1;
	axisConst = 0;
	positionFromTo.at(0).at(0) = true;
	positionFromTo.at(0).at(1) = true;
	positionFromTo.at(0).at(2) = true;
	positionFromTo.at(1).at(0) = true;
	positionFromTo.at(1).at(1) = true;
	positionFromTo.at(1).at(2) = false;

	height = 10;
	from = 5;
	to = 45;

	lineLineFromTo = computeLine(points, positionFromTo, 2, 6, maxError);
	scene.showPoints(lineLineFromTo, 10, colorPoints);

	polynomial = interpolationPolynomial(axisDomain, axisCodomain, lineLineFromTo);
	try {
		lineInterpolation = polynomialVector2vtkPoints(axisConst, height, polynomial, axisDomain, from, to,
				0.5);
	} catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}

	scene.showLine(lineInterpolation, colorLine);

    lineLagrangeInterpolation->Delete();
    
    lineLagrangeInterpolation = vtkSmartPointer<vtkPoints>::New();
    
    for (double i = from; i <= to; i += 0.5)
    {
        lineLagrangeInterpolation->InsertNextPoint(height, lagrangeInterpolation(axisDomain, axisCodomain, lineLineFromTo, i), i);
    }
    
    scene.showLine(lineLagrangeInterpolation, lagrangeInterpolationLineColor);

    polynomialApproximated = approximation(axisDomain, axisCodomain, lineLineFromTo, degreeOfApproximatedPolinomial);
    lineApproximated = polynomialVector2vtkPoints(axisConst, height, polynomialApproximated, axisDomain, from, to,
			0.5);
    scene.showLine(lineApproximated, colorApproximatedLine);



	axisDomain = 0;
	axisCodomain = 1;
	axisConst = 2;
	positionFromTo.at(0).at(0) = true;
	positionFromTo.at(0).at(1) = true;
	positionFromTo.at(0).at(2) = true;
	positionFromTo.at(1).at(0) = false;
	positionFromTo.at(1).at(1) = true;
	positionFromTo.at(1).at(2) = true;

	height = 40;
	from = -15;
	to = 15;

	lineLineFromTo = computeLine(points, positionFromTo, 2, 6, maxError);
	scene.showPoints(lineLineFromTo, 10, colorPoints);

	polynomial = interpolationPolynomial(axisDomain, axisCodomain,
			lineLineFromTo);
	try {
		lineInterpolation = polynomialVector2vtkPoints(axisConst, height,
				polynomial, axisDomain, from, to, 0.5);
	} catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}

	scene.showLine(lineInterpolation, colorLine);

    lineLagrangeInterpolation->Delete();
    
    lineLagrangeInterpolation = vtkSmartPointer<vtkPoints>::New();
    
    for (double i = from; i <= to; i += 0.5)
    {
        lineLagrangeInterpolation->InsertNextPoint(i, lagrangeInterpolation(axisDomain, axisCodomain, lineLineFromTo, i), height);
    }
    
    scene.showLine(lineLagrangeInterpolation, lagrangeInterpolationLineColor);
    

    polynomialApproximated = approximation(axisDomain, axisCodomain, lineLineFromTo, degreeOfApproximatedPolinomial);
    lineApproximated = polynomialVector2vtkPoints(axisConst, height, polynomialApproximated, axisDomain, from, to,
			0.5);
    scene.showLine(lineApproximated, colorApproximatedLine);




	axisDomain = 1;
	axisCodomain = 0;
	axisConst = 2;
	positionFromTo.at(0).at(0) = true;
	positionFromTo.at(0).at(1) = true;
	positionFromTo.at(0).at(2) = true;
	positionFromTo.at(1).at(0) = true;
	positionFromTo.at(1).at(1) = false;
	positionFromTo.at(1).at(2) = true;

	height = 40;
	from = 5;
	to = 25;

	lineLineFromTo = computeLine(points, positionFromTo, 2, 6, maxError);
	scene.showPoints(lineLineFromTo, 10, colorPoints);

	polynomial = interpolationPolynomial(axisDomain, axisCodomain,
			lineLineFromTo);
	try {
		lineInterpolation = polynomialVector2vtkPoints(axisConst, height,
				polynomial, axisDomain, from, to, 0.5);
	} catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}

	scene.showLine(lineInterpolation, colorLine);
    
    lineLagrangeInterpolation->Delete();
    
    lineLagrangeInterpolation = vtkSmartPointer<vtkPoints>::New();
    
    for (double i = from; i <= to; i += 0.5)
    {
        lineLagrangeInterpolation->InsertNextPoint(lagrangeInterpolation(axisDomain, axisCodomain, lineLineFromTo, i), i, height);
    }
    
    scene.showLine(lineLagrangeInterpolation, lagrangeInterpolationLineColor);



    polynomialApproximated = approximation(axisDomain, axisCodomain, lineLineFromTo, degreeOfApproximatedPolinomial);
    lineApproximated = polynomialVector2vtkPoints(axisConst, height, polynomialApproximated, axisDomain, from, to,
			0.5);
    scene.showLine(lineApproximated, colorApproximatedLine);

	//====from (10,20,40)

//TODO ==========

	return 0;
}
