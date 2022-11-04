#include "Matrice.hpp"

#include <algorithm>

namespace transformation
{
Matrice::Matrice(const data::Point& shift, const double zoom, const double scale)
    : matriceShift(shift)
    , zoom(zoom)
    , scale(scale)
{

}
void Matrice::transform(std::vector<data::DataSet>& inputData) const noexcept
{

    auto matriceTransfrom = [&](data::DataSet& data)
    {
        const auto multiplier = data.position.scale / scale;
        data.position.origin.x *= multiplier;
        data.position.origin.y *= multiplier;

        data.position.origin.x *= zoom/100;
        data.position.origin.y *= zoom/100;

        data.position.shift(matriceShift);
    };
    std::for_each(inputData.begin(), inputData.end(), matriceTransfrom);
}
} // transformation