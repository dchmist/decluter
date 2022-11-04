#include "gtest/gtest.h"

#include "transformation/Matrice.hpp"

#include <string>

bool operator==(const data::Coordinates& lhs, const data::Coordinates& rhs)
{
    return lhs.x == rhs.x and lhs.y == rhs.y;
}

bool operator==(const data::DataSet& lhs, const data::DataSet& rhs)
{
    return lhs.index == rhs.index and
        lhs.name == rhs.name and
        lhs.pivotPoint == rhs.pivotPoint and
        lhs.position == rhs.position and
        lhs.priority == rhs.priority and
        lhs.size == rhs.size;
}

namespace tests
{

using namespace testing;
class TestMatrice : public Test
{
protected:
    transformation::Matrice sut{};
};

TEST_F(TestMatrice, transform)
{
    std::vector<data::DataSet> toBeTranformed{};
    const std::vector<data::DataSet> expected{};
    sut.transform(toBeTranformed);
    EXPECT_EQ(toBeTranformed, expected);
}
} // tests