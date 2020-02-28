#ifndef LargInt_h
#define LargInt_h

#include "List.cpp"
#include <iostream>
#include <string>

using namespace std;


class LargInt
{
private:
    List<int> num;           // object in the List class 
public:
  
    LargInt();                                                      // defult constructor
    LargInt operator= (LargInt other);                             // overloading = function
    friend ostream&  operator << (ostream& out, LargInt &other);  // overloading << function
    friend istream& operator >> (istream& in, LargInt &other);   // oberloading >> function
    LargInt operator+(LargInt other);                           // overloading + function
    bool operator==(LargInt other);                            // overloading = function
    

    ~LargInt();
};

#endif

