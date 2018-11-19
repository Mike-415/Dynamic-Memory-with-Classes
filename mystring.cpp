//
// Created by Michael Gonzalez on 11/17/18.
//
#include "mystring.h"
#include <cstring>
#include <iostream>

namespace cs_mystring{
    mystring::mystring(){
        myString = new char[1];
        strcpy(myString, "");

    }

    mystring::mystring(const char *inMyString) {
        myString = new char[strlen(inMyString) + 1];
        strcpy(myString, inMyString);
    }

    mystring::mystring(const mystring& otherString) {
        myString = new char[strlen(otherString.myString) + 1];
        strcpy(myString, otherString.myString);
    }

    mystring::~mystring() {
        delete [] myString;
    }

    int mystring::length() const{
        return strlen(myString);
    }

    std::ostream& operator<<(std::ostream& leftOS, const mystring& rightOperand) {
        leftOS << rightOperand.myString;
        return leftOS;
    }

    mystring mystring::operator=(const mystring& right)
    {
        if (this != &right){
            delete [] myString;
            myString = new char[strlen(right.myString) + 1];
            strcpy(myString, right.myString);
        }
        return *this;
    }

    char mystring::operator[](int index) const
    {
        assert(index >= 0 && index < strlen(myString));
        return myString[index];
    }

    char& mystring::operator[](int index)
    {
        assert(index >= 0 && index < strlen(myString));
        return myString[index];
    }

    bool operator<(const mystring& leftOperand, const mystring& rightOperand){
        return  strcmp(leftOperand.myString, rightOperand.myString) < 0;
    }

    bool operator>(const mystring& leftOperand, const mystring& rightOperand){
        return strcmp(leftOperand.myString, rightOperand.myString) > 0;
    }

    bool operator<=(const mystring& leftOperand, const mystring& rightOperand){
        return strcmp(leftOperand.myString, rightOperand.myString) <= 0;
    }

    bool operator>=(const mystring& leftOperand, const mystring& rightOperand){
        return strcmp(leftOperand.myString, rightOperand.myString) >= 0;
    }

    bool operator!=(const mystring& leftOperand, const mystring& rightOperand){
        return strcmp(leftOperand.myString, rightOperand.myString) != 0;
    }

    bool operator==(const mystring& leftOperand, const mystring& rightOperand){
        return strcmp(leftOperand.myString, rightOperand.myString) == 0;

    }





}

