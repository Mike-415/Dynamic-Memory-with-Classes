//
// Created by Michael Gonzalez on 11/17/18.
//
#include "MyString.h"
#include <cstring>
#include <iostream>

namespace cs_mystring{
    MyString::MyString(){
        myString = new char[1];
        strcpy(myString, "");

    }

    MyString::MyString(const char *inMyString) {
        myString = new char[strlen(inMyString) + 1];
        strcpy(myString, inMyString);
    }

    MyString::~MyString() {
        delete [] myString;
    }

    int MyString::length(){
        return strlen(myString);
    }

    std::ostream& operator<<(std::ostream& leftOS, const MyString& rightOperand) {
        leftOS << rightOperand.myString;
        return leftOS;
    }

    MyString MyString::operator=(const MyString& right)
    {
        if (this != &right){
            delete [] myString;
            myString = new char[strlen(right.myString) + 1];
            strcpy(myString, right.myString);
        }
        return *this;
    }

    char MyString::operator[](int index) const
    {
        assert(index >= 0 && index < strlen(myString));
        return myString[index];
    }

    char& MyString::operator[](int index)
    {
        assert(index >= 0 && index < strlen(myString));
        return myString[index];
    }

    bool operator<(const MyString& leftOperand, const MyString& rightOperand){
        return  strcmp(leftOperand.myString, rightOperand.myString) < 0;
    }

    bool operator>(const MyString& leftOperand, const MyString& rightOperand){
        return strcmp(leftOperand.myString, rightOperand.myString) > 0;
    }

    bool operator<=(const MyString& leftOperand, const MyString& rightOperand){
        return strcmp(leftOperand.myString, rightOperand.myString) <= 0;
    }

    bool operator>=(const MyString& leftOperand, const MyString& rightOperand){
        return strcmp(leftOperand.myString, rightOperand.myString) >= 0;
    }

    bool operator!=(const MyString& leftOperand, const MyString& rightOperand){
        return strcmp(leftOperand.myString, rightOperand.myString) != 0;
    }

    bool operator==(const MyString& leftOperand, const MyString& rightOperand){
        return strcmp(leftOperand.myString, rightOperand.myString) == 0;

    }





}

