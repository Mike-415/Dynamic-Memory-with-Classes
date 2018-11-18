#include <iostream>
#include <cstring>
#include "MyString.h"
using namespace cs_mystring;
using namespace std;
int main() {

}
/*

 List of operations the MyString class must support:

[X`] A length member function that returns the number of characters in the string.
    Use strlen().

[X] Construction of a MyString from a const c-string.
     You should copy the string data, not just store a pointer to an argument passed to the constructor.
     Constructing a MyString with no arguments creates an empty MyString object (i.e. "").
     A MyString object should be implemented efficiently (space-wise) which is to say
     you should not have a fixed-size buffer of chars, but instead allocate space for chars
     on an as-needed basis. Use strcpy().

[X] Printing a MyString to a stream using an overloaded << (insertion) operator,
     which should simply print out its characters. Use <<.

[X] Your MyString object should overload the square brackets [ ] operator
     to allow direct access to the individual characters of the string.
     This operation should range-check and assert if the index is out of bounds.
     You will write two versions of the [ ] operator, a const version that allows
     read access to the chars, and a non-const version that returns the client a reference
     to the char so they can change the value.

[X] All six of the relational operators (<, <=, >, >=, ==, !=) should be supported.
    They should be able to compare MyString objects to other MyStrings as well as MyStrings to c-strings.
    The ordering will be based on ASCII values. You can think of this as essentially alphabetical order;
    however, because of the way that ASCII values are defined, uppercase letters will always
    come before lowercase letters, and punctuation will make things even more complicated.
    Confused? You don't need to worry about any of this: just use the results of calling the strcmp() function.
    MyStrings or c-strings should be able to appear on either side of the comparison operator.

[X] Don't forget to include the big-3.
    [X] Assignment operator
    [X] Copy constructor
    [X] Destructor


 */