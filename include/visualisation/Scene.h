#pragma once

#include <vtkPoints.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vector>

class Scene {
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
	//Create a renderer, render window, and interactor
	vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<
			vtkRenderWindow>::New();
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
			vtkSmartPointer<vtkRenderWindowInteractor>::New();

public:
	Scene(){
		renderWindow->AddRenderer(renderer);
		renderWindow->SetSize(500,500);
		renderWindowInteractor->SetRenderWindow(renderWindow);
		renderer->SetBackground(.05, .15, .05); // Background color green
	}

	int show(vtkSmartPointer<vtkPoints> points);
	int show(vtkSmartPointer<vtkPoints> points, std::vector<unsigned int> linePointsIndices);
};
