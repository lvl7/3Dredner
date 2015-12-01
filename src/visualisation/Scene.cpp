#include <visualisation/Scene.h>
#include <vtkActor.h>
#include <vtkCellArray.h>
#include <vtkIdList.h>
#include <vtkLine.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkVertexGlyphFilter.h>
#include <cstdlib>

int Scene::show(vtkSmartPointer<vtkPoints> points) {

	vtkSmartPointer<vtkPolyData> polydata = vtkSmartPointer<vtkPolyData>::New();

	polydata->SetPoints(points);

	vtkSmartPointer<vtkVertexGlyphFilter> glyphFilter = vtkSmartPointer<
			vtkVertexGlyphFilter>::New();

	glyphFilter->SetInputData(polydata);

	glyphFilter->Update();

	// Visualize
	// Create a mapper and actor
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<
			vtkPolyDataMapper>::New();
	mapper->SetInputConnection(glyphFilter->GetOutputPort());

	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);
	actor->GetProperty()->SetPointSize(2); // size of points

	//Add the actor to the scene
	renderer->AddActor(actor);

	//Render and interact
	renderWindow->Render();
	renderWindowInteractor->Start();

	return EXIT_SUCCESS;

}

int Scene::show(vtkSmartPointer<vtkPoints> points,
		std::vector<unsigned int> linePointsIndices) {

	// Create a cell array to store the lines in and add the lines to it
	vtkSmartPointer<vtkCellArray> lines = vtkSmartPointer<vtkCellArray>::New();


	if(linePointsIndices.size() == 0){
		return EXIT_FAILURE;
	}

	for (unsigned int i = 0; i < linePointsIndices.size() - 1; i++) {

		vtkSmartPointer<vtkLine> line = vtkSmartPointer<vtkLine>::New();
		line->GetPointIds()->SetId(0, linePointsIndices.at(i));
		line->GetPointIds()->SetId(1, linePointsIndices.at(i + 1));
		lines->InsertNextCell(line);
	}

	// Create a polydata to store everything in
	vtkSmartPointer<vtkPolyData> linesPolyData =
			vtkSmartPointer<vtkPolyData>::New();

	// Add the points to the dataset
	linesPolyData->SetPoints(points);

	// Add the lines to the dataset
	linesPolyData->SetLines(lines);

	// Setup actor and mapper
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<
			vtkPolyDataMapper>::New();
	mapper->SetInputData(linesPolyData);

	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);
	actor->GetProperty()->SetColor(1,0,0);
	actor->GetProperty()->SetLineWidth(2);

	this->renderer->AddActor(actor);
	renderWindow->Render();
	renderWindowInteractor->Start();

	return EXIT_SUCCESS;
}

