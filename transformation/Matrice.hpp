#pragma once

#include <vector>

#include "data/DataSet.hpp"
#include "data/Point.hpp"

namespace transformation{
class Matrice
{
public:
    Matrice() = default;
    Matrice(const data::Point& shift, const double zoom);
    void transform(std::vector<data::DataSet>& inputData) const noexcept;
private:
    const data::Point shift{.x = 10, .y = 10};
    const double zoom{100};
};
} // transformation