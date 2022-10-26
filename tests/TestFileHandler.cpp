#include "gtest/gtest.h"

#include "helpers/FileHandler.hpp"

#include <string>

namespace tests
{
using namespace testing;
class TestFileHandler : public Test
{
protected:
    helpers::FileHandler sut{};
    const std::string pathFile{"/mnt/c/Workspace/C++17 Receptury/Declutter/data.txt"};
};

TEST_F(TestFileHandler, openFileSucceed)
{
    const auto data{sut.getDataFromFile(pathFile)};
    EXPECT_NE(data.size(), 0);
}

TEST_F(TestFileHandler, openFileFailed)
{
    EXPECT_THROW(sut.getDataFromFile(""), std::string);
}
} // tests