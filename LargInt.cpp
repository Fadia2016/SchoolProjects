 #include "LargInt.h"


LargInt::LargInt()
{



}


// function to recive the input from the user and inverse it. (the number will be from the right to the left)
//example:  123  will be   321
istream& operator >> (istream& in, LargInt &other)
{
     string numbers1;
    in >> numbers1;

    for (int i = 0; i != numbers1.length(); i++)
    {

    other.num.insertitem((numbers1[i] - 48)); // will comfert the string to numbers
    
    }

    return in;
}


// overloding << function to print the result
// it will give the result in different order
//example::  321  will be printed 123
ostream&  operator << (ostream& out, LargInt &other) 
{
   
    other.num.End();
    while (!other.num.endNULL())
    {
	   out << other.num.readl(); // get the number and asine it to out 
	   other.num.walkEnd(); // walk the pointer to the next node
    }

    return out; //return the result   
}

// overloding + function to add to integer nodes.
// it will add the number from the left side because of the >> overloding function.

LargInt LargInt :: operator + (LargInt other)
{

    LargInt result;                   // create an object to store the result of the addtion in it 
    num.begin();                      // pointing to the first node in the first list
    other.num.begin();               // pointing to the first node in the second list
    int big;
    int small;
    int number = 0;
    int carry = 0;
    if (other.num.lengthlist() >= num.lengthlist()) // to get the size of each list 
    {
	   big = other.num.lengthlist();  //assign the longer list to big
	   small = num.lengthlist();      // assign the smaller list to small
    }
    else
    {
	   big = num.lengthlist();
	   small = other.num.lengthlist();
    }

    for (int i = 0; i < small; i++)           //run a loop base on the shorter list
    {
	   number = other.num.read() + num.read() + carry;   // add the the DATA in each node + the carry.
		 
	   if (number > 9)                    // to take care of the the carry if there is one.
	   {
		  result.num.insertback(number - 10); 
		  carry = 1;
	   }
	   else                               // if there is no carry
	   {
		  result.num.insertback(number);
		  carry = 0;

	   }
		 
	   other.num.walkbegin();       // to move the pointer to the next node in the list.
	   num.walkbegin();             // to move the pointer to the next node in the other list. 
  
    }
    // it will run base on the different between the lists
    for (int i = 0; i < (big - small); i++)  // this loop if one of the numbers has more digit than the other one.
    {
	   if (!other.num.beginNULL()) // to handle the first possibility which is if (other) is longer. 
	   {
		  
		  number = other.num.read() + carry;   // copy the number in side the node + the carry.
		  if (number > 9)                      // chech the number >9 to handle the carry.
		  {
			 result.num.insertback(number - 10);
			 carry = 1;
		  }
		  else                 // if the is no carry
		  {
			 result.num.insertback(number);
			 carry = 0;
		  }
		   
		  other.num.walkbegin();     // move the pinter to the next node in this list

	   }
	   else                       // to handle the second possibility which is if the other list is longer than (other).
	   {
		  
		  number = num.read() + carry; // add the carry and the number in the node
		  if (number > 9)              // to handle the carry
		  {
			 result.num.insertback(number - 10); 
			 carry = 1;
		  }
		  else     // if there is no carry
		  {
			 result.num.insertback(number);
			 carry = 0;
		  }
		 
		  num.walkbegin();   // move the pinter to the next node in this list
		 
	   }
    }
	// to add an extra node in the end if there is only carry and the list is done
     // for example  99 + 1   it will add the 1 in the end to make it a 100
   if (carry == 1)   

   {
	  result.num.insertback(1);
   }

    return result; 
}


bool LargInt::operator==(LargInt other) // function to check if the two object are equal
{
    other.num.begin();
    num.begin();

    if (other.num.lengthlist() == num.lengthlist()) // check the length of the list
    {
	   for (int i = 0; i < num.lengthlist(); i++) // check each element in the list 
	   {
		 
		  if (other.num.read() != num.read()) //if the information in  the nodes are not equal return false 
			 return false;
		  else
		  {
			 other.num.walkbegin(); // else keep (walk) read the nodes in each list
			 num.walkbegin();
		  }
			 
	   }
	   return true;
    }
    else   // if the length not equal that mean the numbers are not equal base on the length of the list
	   return false;
}

LargInt LargInt :: operator= (LargInt other) // very important function to return the result of the + overloding
{
  
	   other.num.begin(); // to set the pointer to first which is the begin of the list. ()resived from the + overloding function

	   while (!other.num.beginNULL()) 
	   {
		  num.insertback(other.num.read());  // copy the element and inserted in the back of the new list 
		  other.num.walkbegin(); // move the to the next node
	   }
	   return *this; // to return the object in side the function 

}

LargInt::~LargInt()  // no need for it beacause there is no poiters (dynamic allocated memory) in this class
{
}