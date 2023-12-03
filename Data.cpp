#include "Data.h"
namespace Towerdefense
{
    void Data::writeToFile(const std::string& filename, const std::vector<std::string>& data) {
        std::ofstream outputFile(filename);

        if (outputFile.is_open()) {
            for (const auto& line : data) {
                outputFile << line << '\n';
            }
            //std::cout << "Data has been written to " << filename << std::endl;
        }
        else {
            std::cerr << "Unable to open the file: " << filename << std::endl;
        }
    }

    std::vector<std::string> Data::readFromFile(const std::string& filename) {
        std::vector<std::string> data;
        std::ifstream inputFile(filename);

        if (inputFile.is_open()) {
            std::string line;
            while (std::getline(inputFile, line)) {
                data.push_back(line);
            }
            //std::cout << "Data has been read from " << filename << std::endl;
        }
        else {
            std::cerr << "Unable to open the file: " << filename << std::endl;
        }

        return data;
    }
}