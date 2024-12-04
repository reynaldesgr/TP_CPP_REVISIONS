#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP


#include <stdexcept>

class ExceptionChaine : public std::exception {
    std::string message;

    public: 
        explicit ExceptionChaine(std::string msg): message(msg){}

        const char * what() const noexcept override {
            return message.c_str();
        }
};
#endif //EXCEPTION_HPP