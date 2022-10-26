#include "Matrice.hpp"

#include <algorithm>

namespace transformation
{
Matrice::Matrice(const data::Point& shift, const double zoom)
    : shift(shift)
    , zoom(zoom)
{

}
void Matrice::transform(std::vector<data::DataSet>& inputData) const noexcept
{
    /*
    const auto matriceTransfrom = [](data::DataSet& data)
    {
        data.position.shift(shift);
        // what can I do with zoom
    }
    std::transform(inputData.begin(), inputData.end(), matriceTransfrom);
    */
}
} // transformation