#pragma once

#include <vtkInteractorStyleTrackballCamera.h>
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

	vtkSmartPointer<vtkInteractorStyleTrackballCamera> style = vtkSmartPointer<
			vtkInteractorStyleTrackballCamera>::New();

public:
	Scene() {
		renderWindow->AddRenderer(renderer);
		renderWindow->SetSize(500, 500);
		renderWindowInteractor->SetRenderWindow(renderWindow);
		renderer->SetBackground(0, 0, 0); // Background color
		renderWindowInteractor->SetInteractorStyle(style);

	}
	/*
	 * color[3] = r, g, b.  1 = max, 0 = min
	 */
	int showPoints(vtkSmartPointer<vtkPoints> points, double pointsSize,
			double * color);
	/*
	 * color[3] = r, g, b.  1 = max, 0 = min
	 */
	int showLine(vtkSmartPointer<vtkPoints> linePoints, double * color);

	/*
	 * color[3] = r, g, b.  1 = max, 0 = min
	 */
	int showLineFromPoinst(vtkSmartPointer<vtkPoints> points,
			std::vector<unsigned int> linePointsIndices, double * color);
	/*
	 * color[3] = r, g, b.  1 = max, 0 = min
	 */
	int showPointsFromPoints(vtkSmartPointer<vtkPoints> points,
			std::vector<unsigned int> pointsIndices, double pointsSize,
			double *color);
};
