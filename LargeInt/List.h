#ifndef List_h
#define  List_h

template <class x>
struct node
{
    x data;
    node *next;
    node *back;
};

template <class x>
class List
{
protected:
    int length;
    node<x> *head;
    node<x> *last;
    // to help us ding the interface, it will point to the last node other wise to NULL
    node<x> *f;
    node<x> *l;

public:

    List();   // constructor
    List(const List<x>& other);                //copy constructor
    void copy(const List<x>& other);          // a function to copy to list
    void operator =(List<x> other);          //overloding = function
    void insertitem( x item);               // add item to the list in the front	 
    void insertback( x item);              // add item to the end of the list	   
    void deleteitem(x item);              // delete item in the list
    int lengthlist();                    // return the length of the list
    void makeempty();                   // delete the list
    void print();                      // print every thing on the list
    void begin();                     // set a pointer to the first node in the list 
    void walkbegin();                // set the a pointer to the next node
    void End();                     // set the pointer (l) to the last node
    void walkEnd();                // move the pointer to the second node from the end
    bool endNULL();               // return true if the end pointer is = NULL
    bool beginNULL();            // return true if the begain pointer = NULL
    x read();                   //get the data in the front node  (return a value)
    x readl();                 // get the data in the last node  (return a value)
    ~List();                  //destructor
};

#endif


