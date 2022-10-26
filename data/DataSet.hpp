#pragma once

#include <string>

#include "Point.hpp"

namespace data
{
struct DataSet
{
    size_t index;
    std::string name;
    Point position;
    double size;
    Point pivotPoint;
    double priority;
};
} //data