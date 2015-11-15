#include <calculation/Points.h>
#include <fstream>
#include <sstream>

void Points::fill(std::string filename)
{
    std::ifstream fin(filename.c_str());

    if(!fin.is_open())
    {
        std::cerr << "Couldn't open file " << filename;
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

void Points::show()
{
    for(std::vector<Coordinates>::iterator it = points.begin(); it != points.end(); ++it) {
        std::cout << it->x << " " << it->y << " " << it->z << std::endl;
    }
}