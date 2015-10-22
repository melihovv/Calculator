#include "error.h"

melihovv::calculator::Error::Error(const calculator::location& location,
    const std::string& message)
{
    this->location = location;
    this->message = message;
}

std::string melihovv::calculator::Error::error() const
{
    std::ostringstream stream;
    stream << location << ": " << message;
    return stream.str();
}
