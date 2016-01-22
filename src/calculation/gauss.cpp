#include <calculation/gauss.h>
#include <math.h>
#include <iostream>

std::vector<double> gauss(std::vector<std::vector<double>> A)
{
    int noOfRows = A.size();
    std::vector<double> x(noOfRows, 0);
    
    for(int i = 0; i < noOfRows; i++)
    {
        int max = i;
        
        for(int j = i + 1; j < noOfRows; j++)
        {
            if(fabs(A[j][i]) > fabs(A[max][i]))
                max = j;
        }
        
        for(int k = i; k < noOfRows+1; k++)
        {
            double tmp = A[i][k];
            A[i][k] = A[max][k];
            A[max][k] = tmp;
        }
        
        if(A[i][i] == 0)
        {
            std::vector<double> empty;

            return empty;  // check if not empty
        }
        
        for(int j = i + 1; j < noOfRows; j++)
        {
            for(int k = noOfRows; k >= i; k--)
                A[j][k] = A[j][k] - A[i][k] * A[j][i] / A[i][i];
        }
        
        for(int j = noOfRows - 1; j >= 0; j--)
        {
            double tmp = 0;
            for(int k = j + 1; k <= noOfRows; k++)
                tmp = tmp + A[j][k] * x[k];
            x[j] = (A[j][noOfRows] - tmp) / A[j][j];
        }
    }
    return x;
}
