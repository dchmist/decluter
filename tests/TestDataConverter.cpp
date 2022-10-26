#include "gtest/gtest.h"

#include "data/DataConverter.hpp"

#include <string>

namespace tests
{
using namespace testing;
class TestDataConverter : public Test
{
protected:
    data::DataConverter sut{};
};

TEST_F(TestDataConverter, convertNoData)
{
    EXPECT_THROW(sut.convertData({}), std::string);
}
} // tests