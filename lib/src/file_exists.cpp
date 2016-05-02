#include <fstream>
#include "file_exists.h"
bool file_exists(const std::string& fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}