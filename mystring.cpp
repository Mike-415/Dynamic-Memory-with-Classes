/*
 Name:       Michael Gonzalez
 Class:      cs110b
 Instructor: Dave Harden
 File:       mystring.cpp

 Class Invariant:

   The mystring class contains one data member: a char pointer named myString
   This data member stores c-strings and it's used
   in various operations such as relational operations.
 */

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






    int mystring::length() const {
        return strlen(myString);
    }






    std::ostream& operator<<(std::ostream& leftOS, const mystring& rightOperand) {
        leftOS << rightOperand.myString;
        return leftOS;
    }






    std::istream& operator>>(std::istream& leftIS, mystring& rightOperand) {
        char tempString[mystring::MAX_INPUT_SIZE + 1];
        leftIS >> tempString;
        delete [] rightOperand.myString;
        rightOperand.myString = new char[strlen(tempString) + 1];
        strcpy(rightOperand.myString, tempString);
        return  leftIS;
    }






    mystring mystring::operator=(const mystring& right) {
        if ( this != &right ) {
            delete [] myString;
            myString = new char[strlen(right.myString) + 1];
            strcpy(myString, right.myString);
        }
        return *this;
    }






    char mystring::operator[](int index) const {
        assert(index >= 0 && index < strlen(myString));
        return myString[index];
    }






    char& mystring::operator[](int index) {
        assert(index >= 0 && index < strlen(myString));
        return myString[index];
    }






    bool operator<(const mystring& leftOperand, const mystring& rightOperand) {
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

