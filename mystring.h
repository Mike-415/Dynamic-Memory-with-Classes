//
// Created by Michael Gonzalez on 11/17/18.
//
#include <iostream>

#ifndef MYSTRING_MYSTRING_H
#define MYSTRING_MYSTRING_H
namespace cs_mystring{
    class mystring {
    public:
        mystring();
        mystring(const char *inMyString);
        mystring(const mystring& otherString);
        ~mystring();
        int length() const;
        friend std::ostream& operator<<(std::ostream& leftOS, const mystring& rightOperand);
        mystring operator=(const mystring& right);
        char operator[](int index) const;
        char& operator[](int index);
        friend bool operator<(const mystring& leftOperand, const mystring& rightOperand);
        friend bool operator>(const mystring& leftOperand, const mystring& rightOperand);
        friend bool operator<=(const mystring& leftOperand, const mystring& rightOperand);
        friend bool operator>=(const mystring& leftOperand, const mystring& rightOperand);
        friend bool operator!=(const mystring& leftOperand, const mystring& rightOperand);
        friend bool operator==(const mystring& leftOperand, const mystring& rightOperand);

    private:
        char *myString;
    };
}
#endif //MYSTRING_MYSTRING_H

/*
OUTPUT:
----- Testing basic String creation & printing
string [0] = Wow
string [1] = C++ is neat!
string [2] =
string [3] = a-z

----- Testing access to characters (using const)
Whole string is abcdefghijklmnopqsrtuvwxyz
now char by char: abcdefghijklmnopqsrtuvwxyz
----- Testing access to characters (using non-const)
Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

----- Testing relational operators between MyStrings
Comparing app to apple
    Is left < right? true
    Is left <= right? true
    Is left > right? false
    Is left >= right? false
    Does left == right? false
    Does left != right ? true
Comparing apple to
    Is left < right? false
    Is left <= right? false
    Is left > right? true
    Is left >= right? true
    Does left == right? false
    Does left != right ? true
Comparing  to Banana
    Is left < right? true
    Is left <= right? true
    Is left > right? false
    Is left >= right? false
    Does left == right? false
    Does left != right ? true
Comparing Banana to Banana
    Is left < right? false
    Is left <= right? true
    Is left > right? false
    Is left >= right? true
    Does left == right? true
    Does left != right ? false

----- Testing relations between MyStrings and char *
Comparing he to hello
    Is left < right? true
    Is left <= right? true
    Is left > right? false
    Is left >= right? false
    Does left == right? false
    Does left != right ? true
Comparing why to wackity
    Is left < right? false
    Is left <= right? false
    Is left > right? true
    Is left >= right? true
    Does left == right? false
    Does left != right ? true

----- Testing copy constructor and operator= on MyStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return MyStrings by value and ref
after calling Append, sum is Binky
val is winky
after assign,  val is Binky

 */