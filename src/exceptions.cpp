#include "exceptions.h"

Exception::Exception(const std::string& message) : message(message) {}

const char *Exception::what() const noexcept {
    return this->message.c_str();
}

OpenFail::OpenFail(const std::string& message) : Exception(message) {}

ReadFail::ReadFail(const std::string& message) : Exception(message) {}

OutOfBounds::OutOfBounds(const std::string& message) : Exception(message) {}

WidgetMismatch::WidgetMismatch(const std::string& message) : Exception(message) {}

ConnectionError::ConnectionError(const std::string& message) : Exception(message) {}
