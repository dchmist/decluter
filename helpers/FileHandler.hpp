#pragma once

#include <string>
#include <vector>

namespace helpers
{
class FileHandler
{
public:
    std::vector<std::string> getDataFromFile(const std::string& filePath) const;
};
} // helpers