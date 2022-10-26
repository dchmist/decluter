#include "ErrorHandler.hpp"

namespace helpers
{
void ErrorHandler::handleError(const std::string& msg)
{
    throw(msg);
}
} // helpers