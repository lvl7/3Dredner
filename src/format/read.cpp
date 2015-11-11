/*
 * read.cpp
 *
 *  Created on: 10-11-2015
 *      Author: lvl7
 */

#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int read(string filename, vtkSmartPointer<vtkPoints> &points) {

	// Get all data from the file
	ifstream fin(filename.c_str());

	string line;

	while (std::getline(fin, line)) {
		double x, y, z;
		std::stringstream linestream;
		linestream << line;
		linestream >> x >> y >> z;

		points->InsertNextPoint(x, y, z);
	}

	fin.close();


	return 0;
}


