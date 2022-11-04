#include <iostream>
#include <string>
#include <vector>

#include "Declutter.hpp"
// #include "data/DataSet.hpp"
#include "data/DataConverter.hpp"
#include "helpers/FileHandler.hpp"



// void print(const std::vector<data::DataSet>& data)
// {
//     for(const auto& dataSet : data)
//     {
//         std::cout << dataSet.index << ", "
//             << dataSet.name << ", "
//             << dataSet.pivotPoint.x << ":" << dataSet.pivotPoint.y  << ", "
//             << dataSet.position.origin.x << ":" << dataSet.position.origin.y  << ':' << dataSet.position.scale << ", "
//             << dataSet.priority << ", "
//             << dataSet.size << std::endl;
//     }
// }

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
        return -1;
    }

    const data::DataConverter dataConverter{};
    auto dataSetStorage{dataConverter.convertData(rawData)};

    Declutter declutter{};
    declutter.printListOfIndexes(dataSetStorage);

    return 0;
}