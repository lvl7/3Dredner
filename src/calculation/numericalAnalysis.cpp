#include <calculation/gauss.h>
#include <calculation/numericalAnalysis.h>
#include <vtkPoints.h>
#include <vtkSmartPointer.h>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

/**
 * ignored axis =
 * 0 - x
 * 1 - y
 * 2 - z
 */
std::vector<double> interpolationPolynomial(int domain, int codomain,
		vtkSmartPointer<vtkPoints> line) {

	// for interpolation
	std::vector<std::vector<double>> matrix(line->GetNumberOfPoints(),
			std::vector<double>(line->GetNumberOfPoints() + 1));
	std::vector<double> temp(line->GetNumberOfPoints() + 1);


	if(domain == codomain){
 		throw "Wrong axis ( interpolation ).\n";
	}

	for (int nop = 0; nop < line->GetNumberOfPoints(); ++nop) {
		for (int coor = 0; coor < line->GetNumberOfPoints(); ++coor) {
			matrix.at(nop).at(coor) = pow(line->GetPoint(nop)[domain], line->GetNumberOfPoints()-coor-1);

		}
		matrix.at(nop).at(line->GetNumberOfPoints()) =
				line->GetPoint(nop)[codomain];
	}

	return gauss(matrix);
}


double lagrangeInterpolation(int domain, int codomain,
                             vtkSmartPointer<vtkPoints> line, double atValue)
{
    if(domain == codomain)
    {
        std::cerr << "Wrong axis given to lagrange interpolation" << std::endl;
    }
    
    auto noOfPoints = line->GetNumberOfPoints();
    
    double lagrangeAtValue = 0;
    
    for (auto i = 0; i < noOfPoints; ++i)
    {
        double li = 1;
        
        for (auto j = 0; j < noOfPoints; ++j)
        {
            if (i == j)
            {
                continue;
            }
            
            li *= (atValue - line->GetPoint(j)[domain]) / (line->GetPoint(i)[domain] - line->GetPoint(j)[domain]);
            
        }
        
        lagrangeAtValue += line->GetPoint(i)[codomain] * li;
        
    }
    
    return lagrangeAtValue;
}


std::vector<double> approximation(int domain, int codomain,
		vtkSmartPointer<vtkPoints> linePoints, unsigned int degreeOfPolynomial){


	if( domain < 0 || domain > 2){
		throw std::runtime_error("Wrong domain axis.");
	} else 	if( codomain < 0 || codomain > 2){
		throw std::runtime_error("Wrong codomain axis.");
	}

	if(degreeOfPolynomial > linePoints->GetNumberOfPoints()){
		degreeOfPolynomial = linePoints->GetNumberOfPoints();
	}

	// degreeOfPolynomial rows for degreeOfPolynomial+1 elements
	std::vector<std::vector<double>> matrix(degreeOfPolynomial+1,
			std::vector<double>(degreeOfPolynomial + 2, 0));

	std::vector<double> mValues(2*degreeOfPolynomial+1);

	for(unsigned int coef = 0; coef <= 2*degreeOfPolynomial; ++coef){
		for(unsigned int p =0; p < linePoints->GetNumberOfPoints(); ++p ){
			mValues.at(coef) += pow( linePoints->GetPoint(p)[domain], coef);
		}
	}

	// make matrix
	for(unsigned int r = 0; r <= degreeOfPolynomial; ++r){
		for(unsigned int c = 0; c <= degreeOfPolynomial; ++c){
			matrix.at(r).at(c) = mValues.at(r+c);

		}

		// last column
		for(unsigned int p =0; p < linePoints->GetNumberOfPoints(); ++p ){
			matrix.at(r).at(degreeOfPolynomial+1) += linePoints->GetPoint(p)[codomain] * pow( linePoints->GetPoint(p)[domain], r);
		}

	}

	std::vector<double> polynomial = gauss(matrix);
	// in this method we get coefficient from last to first.

	double temp = 0;
	double polSize = polynomial.size();
	for(unsigned int c = 0; c < polSize/2; ++c){
		temp = polynomial.at(c);
		polynomial.at(c) = polynomial.at(polSize-1-c);
		polynomial.at(polSize-1-c) = temp;

	}

	return polynomial;
}



