#include <calculation/Matrix.h>
#include <fstream>
#include <sstream>

void Matrix::fill(std::string filename)
{
    std::ifstream fin(filename.c_str());

    if(!fin.is_open())
    {
        std::cerr << "File " << filename << " couldn't be opened!";
    }
    
    std::string line;
    
    while (std::getline(fin, line)) {
        double x, y, z;
        std::stringstream linestream;
        linestream << line;
        linestream >> x >> y >> z;

        points.push_back(Coordinates(x, y, z));
    }
    
    fin.close();
}

void Matrix::show()
{
    for(std::vector<Coordinates>::iterator it = points.begin(); it != points.end(); ++it) {
        std::cout << it->x << " " << it->y << " " << it->z << std::endl;
    }
}