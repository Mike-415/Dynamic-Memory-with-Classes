/*
 * These functions are designed to help you test your mystring objects,
 * as well as show the client usage of the class.
 *
 * The BasicTest function builds an array of strings using various
 * constructor options and prints them out.  It also uses the String
 * stream operations to read some strings from a data file.
 *
 * The RelationTest function checks out the basic relational operations
 * (==, !=, <, etc) on Strings and char *s.
 *
 *
 * The CopyTest tries out the copy constructor and assignment operators
 * to make sure they do a true deep copy.
 *
 * Although not exhaustive, these tests will help you to exercise the basic
 * functionality of the class and show you how a client might use it.
 *
 * While you are developing your mystring class, you might find it
 * easier to comment out functions you are ready for, so that you don't
 * get lots of compile/link complaints.
*/

#include "mystring.h"
#include <cctype>      // for toupper()
#include <iostream>
#include <string>
using namespace std;
using namespace cs_mystring;

void BasicTest();
void RelationTest();
void CopyTest();
mystring AppendTest(const mystring& ref, mystring val);
string boolString(bool convertMe);

int main()
{
    BasicTest();
    RelationTest();
    CopyTest();
}





void BasicTest()
{
    mystring s;
    cout << "----- Testing basic String creation & printing" << endl;

    const mystring strs[] =
            {mystring("Wow"), mystring("C++ is neat!"),
             mystring(""), mystring("a-z")};

    for (int i = 0; i < 4; i++){
        cout << "string [" << i <<"] = " << strs[i] << endl;
    }

    cout << endl << "----- Testing access to characters (using const)" << endl;
    const mystring s1("abcdefghijklmnopqsrtuvwxyz");
    cout <<  "Whole string is " << s1 << endl;
    cout << "now char by char: ";
    for (int i = 0; i < s1.length(); i++){
        cout << s1[i];
    }

    cout << endl << "----- Testing access to characters (using non-const)" << endl;
    mystring s2("abcdefghijklmnopqsrtuvwxyz");
    cout <<  "Start with " << s2;
    for (int i = 0; i < s2.length(); i++){
        s2[i] = toupper(s2[i]);
    }
    cout << " and convert to " << s2 << endl;
}





string boolString(bool convertMe) {
    if (convertMe) {
        return "true";
    } else {
        return "false";
    }
}





void RelationTest()
{
    cout << "\n----- Testing relational operators between MyStrings\n";

    const mystring strs[] =
            {mystring("app"), mystring("apple"), mystring(""),
             mystring("Banana"), mystring("Banana")};

    for (int i = 0; i < 4; i++) {
        cout << "Comparing " << strs[i] << " to " << strs[i+1] << endl;
        cout << "    Is left < right? " << boolString(strs[i] < strs[i+1]) << endl;
        cout << "    Is left <= right? " << boolString(strs[i] <= strs[i+1]) << endl;
        cout << "    Is left > right? " << boolString(strs[i] > strs[i+1]) << endl;
        cout << "    Is left >= right? " << boolString(strs[i] >= strs[i+1]) << endl;
        cout << "    Does left == right? " << boolString(strs[i] == strs[i+1]) << endl;
        cout << "    Does left != right ? " << boolString(strs[i] != strs[i+1]) << endl;
    }

    cout << "\n----- Testing relations between MyStrings and char *\n";
    mystring s("he");
    const char *t = "hello";
    cout << "Comparing " << s << " to " << t << endl;
    cout << "    Is left < right? " << boolString(s < t) << endl;
    cout << "    Is left <= right? " << boolString(s <= t) << endl;
    cout << "    Is left > right? " << boolString(s > t) << endl;
    cout << "    Is left >= right? " << boolString(s >= t) << endl;
    cout << "    Does left == right? " << boolString(s == t) << endl;
    cout << "    Does left != right ? " << boolString(s != t) << endl;

    mystring u("wackity");
    const char *v = "why";
    cout << "Comparing " << v << " to " << u << endl;
    cout << "    Is left < right? " << boolString(v < u) << endl;
    cout << "    Is left <= right? " << boolString(v <= u) << endl;
    cout << "    Is left > right? " << boolString(v > u) << endl;
    cout << "    Is left >= right? " << boolString(v >= u) << endl;
    cout << "    Does left == right? " << boolString(v == u) << endl;
    cout << "    Does left != right ? " << boolString(v != u) << endl;
}





mystring AppendTest(const mystring& ref, mystring val)
{
    val[0] = 'B';
    return val;
}





void CopyTest()
{
    cout << "\n----- Testing copy constructor and operator= on MyStrings\n";

    mystring orig("cake");

    mystring copy(orig);    // invoke copy constructor

    copy[0] = 'f';  // change first letter of the *copy*
    cout << "original is " << orig << ", copy is " << copy << endl;

    mystring copy2;      // makes an empty string

    copy2 = orig;        // invoke operator=
    copy2[0] = 'f';      // change first letter of the *copy*
    cout << "original is " << orig << ", copy is " << copy2 << endl;

    copy2 = "Copy Cat";
    copy2 = copy2;        // copy onto self and see what happens
    cout << "after self assignment, copy is " << copy2 << endl;

    cout << "Testing pass & return MyStrings by value and ref" << endl;
    mystring val = "winky";
    mystring sum = AppendTest("Boo", val);
    cout << "after calling Append, sum is " << sum << endl;
    cout << "val is " << val << endl;
    val = sum;
    cout << "after assign,  val is " << val << endl;
}
/*

 List of operations the mystring class must support:

[X`] A length member function that returns the number of characters in the string.
    Use strlen().

[X] Construction of a mystring from a const c-string.
     You should copy the string data, not just store a pointer to an argument passed to the constructor.
     Constructing a mystring with no arguments creates an empty mystring object (i.e. "").
     A mystring object should be implemented efficiently (space-wise) which is to say
     you should not have a fixed-size buffer of chars, but instead allocate space for chars
     on an as-needed basis. Use strcpy().

[X] Printing a mystring to a stream using an overloaded << (insertion) operator,
     which should simply print out its characters. Use <<.

[X] Your mystring object should overload the square brackets [ ] operator
     to allow direct access to the individual characters of the string.
     This operation should range-check and assert if the index is out of bounds.
     You will write two versions of the [ ] operator, a const version that allows
     read access to the chars, and a non-const version that returns the client a reference
     to the char so they can change the value.

[X] All six of the relational operators (<, <=, >, >=, ==, !=) should be supported.
    They should be able to compare mystring objects to other MyStrings as well as MyStrings to c-strings.
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