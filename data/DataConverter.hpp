#pragma once

#include <array>
#include <vector>

#include "DataSet.hpp"

namespace data{
class DataConverter
{
public:
    std::vector<DataSet> convertData(const std::vector<std::string>& rawData) const noexcept;
private:
    DataSet convertDataSample(const std::string& sample) const;
    DataSet convertStringToDataSetFormat(std::array<std::string, 5>& stringDataSet) const;
    void verifyData(const std::string& sample) const;
    void assignAndInceaseIndex() const;

    const char splitter{';'};
};
} // data