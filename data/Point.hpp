#pragma once

#include "helpers/ErrorHandler.hpp"

#include <string>

namespace data
{

struct Point
{
    double x;
    double y;

    void fillFromString(const std::string& input)
    {
        const auto firstSplitterPosition = input.find(':');
        if (firstSplitterPosition == std::string::npos)
        {
            helpers::ErrorHandler::handleError("Incorrect coordinates : " + input);
        }
        
        x = std::stod(input.substr(0, firstSplitterPosition));
        y = std::stod(input.substr(firstSplitterPosition + 1, input.size() - firstSplitterPosition));
    }
};
} // data