#include "DataConverter.hpp"

#include "helpers/ErrorHandler.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>

namespace data
{
static size_t innerIndex{1};

std::vector<DataSet> DataConverter::convertData(const std::vector<std::string>& rawData) const noexcept
{
    std::vector<DataSet> output{};
    output.reserve(rawData.size());
    for(const auto& sample : rawData)
    {
        try
        {
            output.emplace_back(convertDataSample(sample));
        }
        catch(const std::string& exception)
        {
            std::cerr << exception << '\n';
        }
    }
    return output;
}

DataSet DataConverter::convertDataSample(const std::string& sample) const
{
    verifyData(sample);
    std::array<std::string, 5> stringDataSet{};
    auto arrayIt = stringDataSet.begin();
    std::string temp;
    std::stringstream sstream;
    sstream << sample;

    while (std::getline(sstream, temp, splitter))
    {
        *arrayIt = temp;
	    std::advance(arrayIt, 1);
	}

    return convertStringToDataSetFormat(stringDataSet);
}

void DataConverter::verifyData(const std::string& sample) const
{
    if(const auto amounfOfSplitter = std::count(sample.cbegin(), sample.cend(), splitter); amounfOfSplitter != 4)
    {
        helpers::ErrorHandler::handleError("Incorrect data format of : " + sample);
    }
    else if(sample.front() == ';' or sample.back() == ';' )
    {
        helpers::ErrorHandler::handleError("Empty first or last field of : " + sample);
    }

    for(size_t i = 0; i < sample.size()-1; i++)
    {
        if(sample.at(i) == ';' and sample.at(i+1) == ';')
        {
            helpers::ErrorHandler::handleError("Mising data in sample of : " + sample);
        }
    }
}

DataSet DataConverter::convertStringToDataSetFormat(std::array<std::string, 5>& stringDataSet) const
{
    DataSet output{};

    output.name = stringDataSet.at(0);
    try
    {
        output.position.fillFromString(stringDataSet.at(1));
        output.size = std::stod(stringDataSet.at(2));
        output.pivotPoint.fillFromString(stringDataSet.at(3));
        output.priority = std::stod(stringDataSet.at(4));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        helpers::ErrorHandler::handleError("Cannot convert data");
    }
    output.index = innerIndex;
    innerIndex++;
    return output;
}
} // data