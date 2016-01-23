#include <calculation/gauss.h>
#include <visualisation/fromTo.h>
#include <vtkPoints.h>
#include <vtkSmartPointer.h>
#include <vector>
#include <stdexcept>

void addPointConstXDomainY(vtkSmartPointer<vtkPoints> line, double height,
		double domainValue, double codomainValue) {
	line->InsertNextPoint(height, domainValue, codomainValue);
}
void addPointConstXDomainZ(vtkSmartPointer<vtkPoints> line, double height,
		double domainValue, double codomainValue) {
	line->InsertNextPoint(height, codomainValue, domainValue);
}
void addPointConstYDomainX(vtkSmartPointer<vtkPoints> line, double height,
		double domainValue, double codomainValue) {
	line->InsertNextPoint(domainValue, height, codomainValue);
}
void addPointConstYDomainZ(vtkSmartPointer<vtkPoints> line, double height,
		double domainValue, double codomainValue) {
	line->InsertNextPoint(codomainValue, height, domainValue);
}
void addPointConstZDomainX(vtkSmartPointer<vtkPoints> line, double height,
		double domainValue, double codomainValue) {
	line->InsertNextPoint(domainValue, codomainValue, height);
}
void addPointConstZDomainY(vtkSmartPointer<vtkPoints> line, double height,
		double domainValue, double codomainValue) {
	line->InsertNextPoint(codomainValue, domainValue, height);
}

vtkSmartPointer<vtkPoints> polynomialVector2vtkPoints(int wichAxisConst,
		double axisHeight, std::vector<double> polynomial, int wichAxisDomain,
		double from, double to, double samplingDistance) {

	vtkSmartPointer<vtkPoints> line = vtkSmartPointer<vtkPoints>::New();
	void (*addPoint)(vtkSmartPointer<vtkPoints>, double, double, double);


	//TODO if else will better look?
	switch (wichAxisConst) {
	case 0:

		switch (wichAxisDomain) {
		case 1:
			addPoint = addPointConstXDomainY;
			break;
		case 2:
			addPoint = addPointConstXDomainZ;
			break;
		default:
			throw std::runtime_error("Wrong codomain axis.");
		}
		break;

	case 1:
		switch (wichAxisDomain) {
		case 0:
			addPoint = addPointConstYDomainX;
			break;
		case 2:
			addPoint = addPointConstYDomainZ;
			break;
		default:
			throw std::runtime_error("Wrong codomain axis.");
		}
		break;

	case 2:
		switch (wichAxisDomain) {
		case 0:
			addPoint = addPointConstZDomainX;
			break;
		case 1:
			addPoint = addPointConstZDomainY;
			break;
		default:
			throw std::runtime_error("Wrong codomain axis.");
		}
		break;
	default:
		throw std::runtime_error("Wrong domain axis.");
	}

	// compute codomain
	double codomain;
	int dofp = polynomial.size(); // degree of polynomial
	for( double dom = from; dom < to; dom += samplingDistance){

		codomain = 0;
		for(int coeff = 0; coeff < dofp; ++coeff){
			codomain += polynomial.at(dofp-coeff-1) * pow(dom, coeff);
		}

		(*addPoint)(line, axisHeight, dom, codomain);
	}


	return line;
}


