#include "Declutter.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>

void Declutter::printListOfIndexes(std::vector<data::DataSet>& dataSetStorage)
{
    matrice.transform(dataSetStorage);
    sort(dataSetStorage);
    const auto listOfIndexes{createListOfIndexes(dataSetStorage)};
    printIndexes(listOfIndexes);
}

void Declutter::sort(std::vector<data::DataSet>& dataSetStorage)
{
    const auto comparePriorities = [](const data::DataSet& lhs, const data::DataSet& rhs)
    {
        return lhs.priority > rhs.priority;
    };
    std::sort(dataSetStorage.begin(), dataSetStorage.end(), comparePriorities);
}

std::vector<size_t> Declutter::createListOfIndexes(std::vector<data::DataSet>& sortedDataSetStorage)
{
    double occupiedScreenSpace = 0;
    std::vector<size_t> listOfIndexes{};

    for(const auto& dataSet : sortedDataSetStorage)
    {
        if(occupiedScreenSpace >= screenScale)
        {
            break;
        }
        occupiedScreenSpace += dataSet.size;
        listOfIndexes.push_back(dataSet.index);
    }
    return listOfIndexes;
}

void Declutter::printIndexes(const std::vector<size_t>& listOfIndexes)
{
    std::cout << "List of indexes: ";
    std::copy(listOfIndexes.cbegin(), listOfIndexes.cend(), std::ostream_iterator<size_t>(std::cout, " "));
    std::cout << '\n';
}