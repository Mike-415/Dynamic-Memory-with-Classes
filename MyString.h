//
// Created by Michael Gonzalez on 11/17/18.
//
#include <iostream>

#ifndef MYSTRING_MYSTRING_H
#define MYSTRING_MYSTRING_H
namespace cs_mystring{
    class MyString {
    public:
        //TODO: Compare this with the example in the lesson
        MyString();
        MyString(const char *inMyString);
        ~MyString();
        int length();
        friend std::ostream& operator<<(std::ostream& leftOS, const MyString& rightOperand);
        MyString operator=(const MyString& right);
        char operator[](int index) const;
        char& operator[](int index);
        friend bool operator<(const MyString& leftOperand, const MyString& rightOperand);
        friend bool operator>(const MyString& leftOperand, const MyString& rightOperand);
        friend bool operator<=(const MyString& leftOperand, const MyString& rightOperand);
        friend bool operator>=(const MyString& leftOperand, const MyString& rightOperand);
        friend bool operator!=(const MyString& leftOperand, const MyString& rightOperand);
        friend bool operator==(const MyString& leftOperand, const MyString& rightOperand);

    private:
        char *myString;
    };
}
#endif //MYSTRING_MYSTRING_H
