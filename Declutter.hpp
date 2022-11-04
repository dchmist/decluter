#pragma once

#include <vector>

#include "data/DataSet.hpp"
#include "data/Point.hpp"
#include "transformation/Matrice.hpp"

class Declutter
{
public:
    void printListOfIndexes(std::vector<data::DataSet>& dataSetStorage);

private:
    void sort(std::vector<data::DataSet>& dataSetStorage);
    std::vector<size_t> createListOfIndexes(std::vector<data::DataSet>& dataSetStorage);
    void printIndexes(const std::vector<size_t>& sortedDataSetStorage);

    const double screenScale = 1000;
    const double zoom = 110;
    const data::Point shift{.x = 10, .y = 10};
    transformation::Matrice matrice{shift, zoom, screenScale};
};