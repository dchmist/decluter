#pragma once

#include "Point.hpp"

#include <string>

namespace data
{
struct Coordinates
{
    void fillFromString(const std::string& input);
    void shift(const Point& shift) noexcept;

    Point origin;
    double scale;
};
} //data