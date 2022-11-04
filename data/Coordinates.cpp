#include "Coordinates.hpp"

#include "helpers/ErrorHandler.hpp"

namespace data
{
void Coordinates::fillFromString(const std::string& input)
{
    const auto firstSplitterPosition = input.find(':');
    const auto lastSplitterPosition = input.find_last_of(':');
    if ((firstSplitterPosition == std::string::npos) or (lastSplitterPosition == std::string::npos) or (firstSplitterPosition == lastSplitterPosition))
    {
        helpers::ErrorHandler::handleError("Incorrect coordinates : " + input);
    }
    
    origin.x = std::stod(input.substr(0, firstSplitterPosition));
    origin.y = std::stod(input.substr(firstSplitterPosition + 1, input.size() - (lastSplitterPosition - firstSplitterPosition)));
    scale = std::stod(input.substr(lastSplitterPosition + 1, input.size() - lastSplitterPosition));
}

void Coordinates::shift(const Point& shift) noexcept
{
    origin.x += shift.x;
    origin.y += shift.y;
}
} // data