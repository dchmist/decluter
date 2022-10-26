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
        const auto splitterPosition = input.find(':');
        if (splitterPosition == std::string::npos)
        {
            helpers::ErrorHandler::handleError("Incorrect PointType");
        }
        
        x = std::stod(input.substr(0, splitterPosition));
        y = std::stod(input.substr(splitterPosition+1, input.size() - splitterPosition));
    }

    void shift(const Point& shift) noexcept
    {
        x += shift.x;
        y += shift.y;
    }
};
} //data