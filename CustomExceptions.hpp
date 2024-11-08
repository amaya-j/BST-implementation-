//==============================================================
// Names: Aisha Barry, Omar Perez, Amaya Joshi
// Class: CS 271-01
// Date: 11/07/2024
// About: Declerations and definitions of the exception used
//==============================================================



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
