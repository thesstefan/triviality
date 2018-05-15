#include "exceptions.h"

Exception::Exception(const std::string& message) : message(message) {}

OpenFail::OpenFail(const std::string& message) : Exception(message) {}

const char *OpenFail::what() const noexcept {
    return this->message.c_str();
}

ReadFail::ReadFail(const std::string& message) : Exception(message) {}

const char *ReadFail::what() const noexcept {
    return this->message.c_str();
}
