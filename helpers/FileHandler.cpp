#include "FileHandler.hpp"

#include "helpers/ErrorHandler.hpp"

#include <fstream>
#include <iostream>

namespace helpers
{
std::vector<std::string> FileHandler::getDataFromFile(const std::string& filePath) const
{
    std::fstream file{filePath};
    if(not(file.is_open()))
    {
        ErrorHandler::handleError("Cannot open file " + filePath);
    }
    std::vector<std::string> data{};
    std::string temp{};
    while(std::getline(file, temp))
    {
        temp.pop_back();
        data.push_back(temp);
    }
    return data;
}
} // helpers