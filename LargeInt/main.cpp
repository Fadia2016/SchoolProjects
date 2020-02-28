/*
Name: Fadi Ahmed
Class: CSC331
Project # 1
*/



#include "LargInt.h"
#include <iostream>
#include <string>
#include <stdio.h>


using namespace std;

int main()
{

    cout << "hello" << endl;

    List<int> l;
    l.insertback(1);
    l.insertback(2);
    l.insertback(3);
    l.insertback(4);
    l.insertback(5);
    l.insertback(6);
   
    l.print();
    cout << l.lengthlist() << "   the length" << endl;
    l.deleteitem(1);
    l.deleteitem(6);
    l.deleteitem(3);
    
    cout << "---------------------" << endl;
    
    l.print();
    cout << l.lengthlist()<< "    the length" << endl;

    LargInt p, o, d;
    cout << "enter the first number:  " << endl;
    cin >> o;
    cout << " enter the second number: " << endl;
    cin >> p;
    d = p + o;

    cout << endl;
    cout << o << " + " << p << endl;

    cout << d << endl;


    if (p == o)
	   cout << "equal" << endl;
    else
	   cout << " they are not equal" << endl;

    
	   
   
    system("pause");

    return 0;
}
