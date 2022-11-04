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

TEST_F(TestDataConverter, convertValidData)
{
}

TEST_F(TestDataConverter, throwMisingDataInSample)
{
    // EXPECT_THROW(sut.convertData({}), std::string);
}

TEST_F(TestDataConverter, throwIncorrectDataFormat)
{
    // EXPECT_THROW(sut.convertData({}), std::string);
}

TEST_F(TestDataConverter, throwEmptyDirstOrLastField)
{
    // EXPECT_THROW(sut.convertData({}), std::string);
}

TEST_F(TestDataConverter, throwCannotConvertData)
{
    // EXPECT_THROW(sut.convertData({}), std::string);
}
} // tests