/**
 * @file exceptions.h
 *
 * This module provides the inteface of the exceptions used in the program.
 */

#include <string>
#include <exception>

/**
 * @class Exception
 *
 * @brief This class stands as the inteface of the exceptions used across the program.
 *
 * @note It is derived from std::exception.
 */
class Exception : public std::exception {
    protected:
        /**
         * @brief The message of the Exception.
         */
        std::string message;

    public:
        /**
         * @brief Constructs the Exception, assigning it a message.
         *
         * @param message -> The message of the Exception.
         */
        Exception(const std::string& message);

        /**
         * @brief Returns the message of the Exception.
         */
        const char *what() const noexcept;
};

/**
 * @class OpenFail
 *
 * @brief Exception used to show that a file failed to open.
 */
class OpenFail : public Exception {
    public:
        /**
         * @brief Constructs OpenFail, assigning it a message.
         *
         * @param message -> The message of OpenFail.
         */
        OpenFail(const std::string &message);
};

/**
 * @class ReadFail
 * 
 * @brief Exception used to show that something failed to be read.
 */
class ReadFail : public Exception {
    public:
        /**
         * @brief Constructs the Exception, assigning it a message.
         *
         * @param message -> The message of the ReadFail.
         */
        ReadFail(const std::string &message);
};

/**
 * @class OutOfBounds
 *
 * @brief Exception used to show that something is out of bounds.
 */
class OutOfBounds : public Exception {
    public:
        /**
         * @brief Constructs the Exception, assigning it a message.
         *
         * @param message -> The message of OutOfBounds.
         */
        OutOfBounds(const std::string &message);
};
