#pragma once

#include <vector>

#include "data/DataSet.hpp"
#include "data/Point.hpp"

namespace transformation{
class Matrice
{
public:
    Matrice() = default;
    Matrice(const data::Point& shift, const double zoom, const double scale);
    void transform(std::vector<data::DataSet>& inputData) const noexcept;
private:
    const data::Point matriceShift{.x = 10, .y = 10};
    const double zoom{100};
    const double scale{1000};
};
} // transformation