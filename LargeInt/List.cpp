#include "List.h"

#include <iostream>

using namespace std;

template <class x>
List<x>::List()
{
    head = NULL;
    last = NULL;
    f = NULL;
    l = NULL;
    length = 0;
}


template <class x>
List<x>::List(const List<x>& other)
{
    copy(other);

}

template <class x>
void List<x>::copy(const List<x> & other) // copy constructor
{
    length = other.length;

    if (length == 0)
    {
	   head = NULL;
	   last = NULL;
    }
    else
    {
	   head = new node<x>;
	   head->data = other.head->data;
	   node<x> *p = other.head->next;
	   node<x> *s = head;

	   while (p != NULL)
	   {
		  s->next = new node<x>;
		  s->next->back = s;
		  s = s->next;
		  s->data = p->data;
		  last = s;
		  p = p->next;

	   }
	   s->next = NULL;


    }

}


template <class x>
void List<x>:: operator= (List<x> other)
{
    if (this != &other)  // to check if it is the same list, if not go in side the if statment.
    {
	   makeempty();    //  we delete every thing in this list
	   copy(other);    // we copy every thing to this List using the copy function
    }

}

template <class x>
void List<x>::insertitem( x item)
{
    node<x> *n;
    n = new node<x>;
    n->data = item;
    n->back = NULL;
    n->next = head;
    if (head != NULL)
    {
	   head->back = n;
	   head = n;
    }
    else
    {
	   last = n;
	   head = n;
    }
    length++;

}

template <class x>
void List<x>::insertback( x  item) // to insert and add a node (item ) to the end of the list
{
    node<x> *n;
    n = new node<x>;
    n->data = item;
    n->next = NULL;
    n->back = last;
    if (last != NULL)
    {
	   last->next = n;
	   last = n;
    }
    else
    {
	   last = n;
	   head = n;
    }
    length++;

}

template <class x>
void List<x>::deleteitem(x item)   // delete item in the list
{
    node<x> * n;    // this pointer will delete the item if it is in the list
    n = head;
    if (head != NULL)   // if there is an item will go inside the if statment
    { 
	   if (head->data == item)   // if the item is in the first node
	   {
		  head = head->next;
		  if (head != NULL)     // if there is more than one node and the item is in the first node
			 head->back = NULL;
		  else
			 last = NULL;     // if the item in the first and its the only node in the list
		  delete n;
		  length--;
	   }
	   else
	   {
		  while (n != NULL && n->data != item)  //search for the item from the beigan to the end. 
		  {
			 n = n->next;
		  }
		  if (n != NULL)            // if we find the item
		  {
			 n->back->next = n->next;
			 if (n == last)            // if the item is in the end of the list
				last = last->back;
			 else                     
				n->next->back = n->back;
			 delete n;
			 length--;
		  }
		  else // if the item is not in the list
			 cout << " the item is not in the list" << endl;
	   }
	 
    }
    else  // if there is no nodes in the list (list is empty)
	   cout << "there is no list at all" << endl;

}

template <class x>
int List<x>::lengthlist() //  return the length of the list
{
    return length;
}

template<class x>
void List<x>::print()    // print the data in side each node in the list 
{
    node<x> *n = head;   // this pinter will go over the nodes to get the data
    if (head != NULL)
    {

	   while (n != NULL)
	   {
		  cout << n->data << endl;
		  n = n->next;
	   }
    }
    else                // if there is node list 
	   cout << " List is empty" << endl;
}

template <class x>
void List<x> ::makeempty() // delete the list
{
    node<x> *s;
    while (head != NULL) // going over each node and delete it
    {
	   s = head;
	   head = head->next;
	   delete s;

    }
    length = 0;
}

template <class x>
void List<x>::begin()  // to set the pinter to the first node in the list
{
    f = head;

}

template <class x>
void List<x>::walkbegin() // to make the pointer f walks one node away each call
{
    f = f->next;
}

template <class x>
x List<x>::read()        // get the value in side the node using f
{
    return (f->data);
}

template <class x>
x List<x>::readl()        // get the value in side the node using f
{
    
    return (l->data);
  
}



template <class x>
void List<x>::walkEnd()   // to make the pointer l walks one node away each call
{
    l = l->back;
}

template <class x>
bool List<x>::endNULL()   // to make the pointer f = NULL
{
return (l == NULL);
}

template <class x>
bool List<x>::beginNULL() // function to check if we get the end of the list. it will be used in the LargInt class
{
    return (f == NULL);
}

template <class x>
void List<x>::End()    // to set the pinter to the last node in the list
{

    l = last;

}


template <class x>
List<x>::~List()
{
    makeempty();
}

