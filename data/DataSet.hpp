#pragma once

#include <string>

#include "Coordinates.hpp"
#include "Point.hpp"

namespace data
{
struct DataSet
{
    size_t index;
    std::string name;
    Coordinates position;
    double size;
    Point pivotPoint;
    double priority;
};
} //data