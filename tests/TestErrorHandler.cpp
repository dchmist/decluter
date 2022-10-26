#include "gtest/gtest.h"

#include "helpers/ErrorHandler.hpp"

#include <string>

namespace tests
{
using namespace testing;
class TestErrorHandler : public Test
{
protected:
    helpers::ErrorHandler sut{};
};

TEST_F(TestErrorHandler, throwString)
{
    EXPECT_THROW(sut.handleError(""), std::string);
}
} // tests