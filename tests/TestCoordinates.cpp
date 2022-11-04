#include "gtest/gtest.h"

#include "data/Coordinates.hpp"

#include <string>

namespace tests
{
using namespace testing;
class TestCoordinates : public Test
{
protected:
    data::Coordinates sut{.origin = {10,10}, .scale = 3};
};

TEST_F(TestCoordinates, shift)
{
    const data::Point shiftPoint{15, 30};
    const double expectedX = shiftPoint.x + sut.origin.x;
    const double expectedY = shiftPoint.y + sut.origin.y;
    
    sut.shift(shiftPoint);
    EXPECT_EQ(sut.origin.x, expectedX);
    EXPECT_EQ(sut.origin.y, expectedY);
}

TEST_F(TestCoordinates, fillWithCorrectData)
{
    const double expectedX = 110;
    const double expectedY = 9000;
    const double expectedScale = 1000;
    std::string strCoords{"110:9000:1000"};

    sut.fillFromString(strCoords);
    EXPECT_EQ(sut.origin.x, expectedX);
    EXPECT_EQ(sut.origin.y, expectedY);
    EXPECT_EQ(sut.scale, expectedScale);
}

TEST_F(TestCoordinates, fillWithCorruptedData)
{
    std::string corruptedStr{"110:9000"};
    EXPECT_THROW(sut.fillFromString(corruptedStr), std::string);
}
} // tests