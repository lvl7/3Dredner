#include <format/read.h>
#include <visualisation/show.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <iostream>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " Filename(.xyz)" << std::endl;
		return 1;
	}


	vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
	read(argv[1],points);

	show(points);

	return 0;
}
