#pragma once

#include <string>

namespace helpers
{
class ErrorHandler
{
public:
    static void handleError(const std::string& msg);
} ;
} // helpers