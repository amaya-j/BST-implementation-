#ifndef CUSTOMEXCEPTIONS_HPP
#define CUSTOMEXCEPTIONS_HPP
using namespace std;
#include <exception>
#include <string>

class ValueNotInTreeException : public exception {
    public:
        virtual const char* what() const throw() {
            return "Value not in tree exception";
        }
};

class EmptyTreeException : public exception {
    public:
        virtual const char* what() const throw() {
            return "Empty tree exception";
        }
};

#endif // CUSTOMEXCEPTIONS_HPP
