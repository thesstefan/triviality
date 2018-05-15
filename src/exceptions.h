#include <string>
#include <exception>

class Exception : public std::exception {
    protected:
        std::string message;

    public:
        Exception(const std::string& message);

        virtual const char *what() const noexcept = 0;
};

class OpenFail : public Exception {
    public:
        OpenFail(const std::string &message);

        const char *what() const noexcept;
};

class ReadFail : public Exception {
    public:
        ReadFail(const std::string &message);

        const char *what() const noexcept;
};

class EntryReadFail : public Exception {
    public:
        EntryReadFail(const std::string &message);

        const char *what() const noexcept;
};
