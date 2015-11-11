/*
 * read.h
 *
 *  Created on: 10-11-2015
 *      Author: lvl7
 */

#ifndef READ_H_
#define READ_H_

#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>

int read(std::string filename, vtkSmartPointer<vtkPoints> &points);

#endif /* READ_H_ */
