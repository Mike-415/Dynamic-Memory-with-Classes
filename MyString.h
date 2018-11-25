/*
    Name:       Michael Gonzalez
    Class:      cs110b
    Instructor: Dave Harden
    File:       MyString.h

    The MyString class is used to make working with sequences of characters a little more
    convenient and less error-prone than handling raw c-strings.

    The following functions are available:

    MyString();
      post: Constructs a MyString object with an empty string for the myString data member.


    MyString(const char *inMyString);
      post: Constructs a MyString object with a c-string argument for the myString data member.

    MyString(const MyString& otherString);
      post: Constructs a hard copy of a MyString object with another MyString object
            that provides the myString data member

    MyString();
      post: deallocates any object within the stack, usually when
            execution reaches the end of the function body.

    int length() const;
      post: returns the number of characters contained within the myString data member.

    friend std::ostream& operator<<(std::ostream& leftOS, const MyString& rightOperand);
      post: returns an output stream that contains the myString data member.

    MyString operator=(const MyString& right);
      post: returns a hard copy of the right MyString object


    char operator[](int index) const;
      post: returns the character within the index of the myString char array.

    char& operator[](int index);
      post: returns a reference to the left-side operand in order to assign
            it a value.

    friend bool operator<(const MyString& leftOperand, const MyString& rightOperand);
      post: Returns true if the left operand is less than to the right operand.

    friend bool operator>(const MyString& leftOperand, const MyString& rightOperand);
      post: Returns true if the left operand is greater than to the right operand.

    friend bool operator<=(const MyString& leftOperand, const MyString& rightOperand);
      post: Returns true if the left operand is less than or equal to the right operand.

    friend bool operator>=(const MyString& leftOperand, const MyString& rightOperand);
      post: Returns true if the left operand is greater than or equal to the right operand.

    friend bool operator!=(const MyString& leftOperand, const MyString& rightOperand);
      post: Returns true if the left operand is not equal to the right operand.

    friend bool operator==(const MyString& leftOperand, const MyString& rightOperand);
      post: Returns true if the left operand is equal to the right operand.
*/
#include <iostream>
#include <fstream>
#ifndef MYSTRING_MYSTRING_H
#define MYSTRING_MYSTRING_H
namespace cs_mystring{
    class MyString {
    public:
        static const int MAX_INPUT_SIZE = 127;
        MyString();
        MyString(const char *inMyString);
        MyString(const MyString& otherString);
        ~MyString();
        int length() const;

        void read(std::ifstream& inStream, const char delimiter);

        MyString operator=(const MyString& right);
        char operator[](int index) const;
        char& operator[](int index);
        friend std::ostream& operator<<(std::ostream& leftOS, const MyString& rightOperand);

        friend std::istream& operator>>(std::istream& leftIS, MyString& rightOperand);

        friend bool operator<(const MyString& leftOperand, const MyString& rightOperand);
        friend bool operator>(const MyString& leftOperand, const MyString& rightOperand);
        friend bool operator<=(const MyString& leftOperand, const MyString& rightOperand);
        friend bool operator>=(const MyString& leftOperand, const MyString& rightOperand);
        friend bool operator!=(const MyString& leftOperand, const MyString& rightOperand);
        friend bool operator==(const MyString& leftOperand, const MyString& rightOperand);

        friend MyString operator+(const MyString& leftOperand, const MyString& rightOperand);
        MyString operator+=(const MyString& rightOperand);

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