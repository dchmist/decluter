#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "data/DataConverter.hpp"
#include "data/DataSet.hpp"
#include "helpers/FileHandler.hpp"
#include "transformation/Matrice.hpp"


void print(const std::vector<data::DataSet>& data)
{
    for(const auto& dataSet : data)
    {
        std::cout << dataSet.index << ", "
            << dataSet.name << ", "
            << dataSet.pivotPoint.x << ":" << dataSet.pivotPoint.y  << ", "
            << dataSet.position.x << ":" << dataSet.position.y  << ", "
            << dataSet.priority << ", "
            << dataSet.size << std::endl;
    }
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cout << "Missing filepath\n";
        return -1;
    }
    const std::string filePath{*(argv+1)};
    const helpers::FileHandler fileHandler{};
    std::vector<std::string> rawData{};

    try
    {
        rawData = fileHandler.getDataFromFile(filePath);
    }
    catch(const std::string& e)
    {
        std::cerr << e << '\n';
    }    

    const data::DataConverter dataConverter{};
    auto convertedData{dataConverter.convertData(rawData)};

    //sort
    const auto comparePriorities = [](const data::DataSet& lhs, const data::DataSet& rhs)
    {
        return lhs.priority > rhs.priority;
    };
    std::sort(convertedData.begin(), convertedData.end(), comparePriorities);

    std::cout << "Sorted:\n";
    print(convertedData);

    transformation::Matrice matrice{};
    matrice.transform(convertedData);

    return 0;
}