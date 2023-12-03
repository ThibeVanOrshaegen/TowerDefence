#ifndef DATA
#define DATA

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
namespace Towerdefense
{
    class Data {
    public:
        static void writeToFile(const std::string& filename, const std::vector<std::string>& data);
        static std::vector<std::string> readFromFile(const std::string& filename);
    };

#endif 
}