#include <calculation/gauss.h>

#include <vtkPoints.h>
#include <vtkSmartPointer.h>
#include <vector>


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

vtkSmartPointer<vtkPoints> polynomialVector2vtkPoints(int wichAxisHeight,
		double axisHeight, std::vector<double> polynomial, int wichAxisDomain,
		double from, double to, double samplingDistance) {

	vtkSmartPointer<vtkPoints> line = vtkSmartPointer<vtkPoints>::New();
	void (*addPoint)(vtkSmartPointer<vtkPoints>, double, double, double);


	//TODO if else will better look?
	switch (wichAxisHeight) {
	case 0:

		switch (wichAxisDomain) {
		case 1:
			addPoint = addPointConstXDomainY;
			break;
		case 2:
			addPoint = addPointConstXDomainZ;
			break;
		default:
			throw "Wrong codomain axis.\n";
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
			throw "Wrong codomain axis.\n";
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
			throw "Wrong codomain axis.\n";
		}
		break;
	default:
		throw "Wrong domain axis.\n";
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


