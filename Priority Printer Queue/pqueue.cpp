// CS311 Yoshii - HW5 Priority Queue Implementation File
// Complete all ** parts and give good comments
// ** Do not delete my comments.

// =================================================
// HW5 Priority Printer Queue 
// YOUR NAME: Tyler Cochran
// File Type: implementation pqueue.cpp
// =================================================

#include "pqueue.h"

// constructor
pqueue::pqueue()
{
  count = 0;  // no jobs yet
}

// destructor does nothing
pqueue::~pqueue() {}

// Purpose: to add a job to a right place in the Pqueue
// Argument: j is the job priority number
// Remember that the current last job is in slot count-1.
void pqueue::insertjob(int j)
{
  cout << "Adding: " << j << endl;

  // if possible else display error message. 
  if(count < MAX)
    {
      // add the job j at the rear (and update count)
      count++;
      Q[count - 1] = j;
    }
  else
    cout << "**ERROR** Number of elements exceeds MAX" << endl;
  
  trickleup(); // moves the job to the right place
}

// Purpose: to print a job and reheapify the Pqueue
void pqueue::printjob()
{
  cout << "Printing: " << Q[0] <<endl;
  reheapify(); 
}

// Purpose: to display all jobs
void pqueue::displayAll()
{ 
  cout << "Jobs: ";
  
  // loop to display jobs from slot 0 to slot count-1 horizontally. No need to show a tree format.
  for(int i = 0; i <= count - 1; i++)
    cout << Q[i] << " ";
  
  cout << endl; 
}


// Utility functions follow: ------------------

void pqueue::swap(int loc1, int loc2)
{
  // swap the values in these locations in Q
  int temp;
  
  temp = Q[loc1];
  Q[loc1] = Q[loc2];
  Q[loc2] = temp;
}

// Purpose: to make the very last job trickle up to the right location. Never do X--. 
void pqueue::trickleup()
{ 
  int x = count-1;  // the very last job's location
  int P;            // location of the parent
  P = getParent(x);
  
  while(x > 0)  // While x is > 0   
    {
      if(Q[x] < Q[P])        // compare Q[x] with the parent (*)
	{	             // and if the parent is bigger swap & update x 
	  swap(x, P);        // to be the parent . Otherwise stop the loop. 
	  x = P;             // (*) Call getParent to get the location of the parent
	  P = getParent(x);  //            based on the child's location.
	}
      else
	break;
    }  
}

// Purpose: find the location of the parent 
// The child location is given.  Need to call even.
int pqueue::getParent(int childloc)
{  
  // return the parent location based on the child loc
  if(even(childloc))
    return (childloc - 2) / 2;
  else
    return (childloc - 1) / 2;
}

// Purpose: is location i even? Important in finding its parent location
bool pqueue::even(int i)
{
  if ((i % 2) ==  0) return true; else return false;
}

// Purpose: to reheapify the Pqueue after printing
// This trickles down.  Never do X++.
void pqueue::reheapify()
{
  int X;   // the current location
  Q[0] = Q[count - 1];  // move the last job to the front
  count--;
  
  // Start X at 0 (the root)
  X = 0;
  int sChild;   // location of the smaller child
  
  // while X is within the array:
  while(X <= count - 1)
    {
      // Find the location of the smaller child    
      sChild = getSmallerchild(X);
      
      // (if the location of both children are off the tree, stop the loop).
      if(sChild > count - 1)
	break;
      else
	{
	  // If the smaller child is smaller than the parent,
	  if(Q[sChild] < Q[X])
	    {
	      // swap and X becomes the smaller child's location.
	      swap(sChild, X);
	      X = sChild;
	    }
	  else
	    break;  //  else no swaps so stop to loop
	}
    }
}

// Purpose: to find the location of the smaller child
// where children are at locations 2*i+1 and 2*i+2
int pqueue::getSmallerchild(int i)
{
  //    return the location of the smaller child 
  //    Be careful because one or both of them may be
  //    beyond count-1.  Check boundaries before you 
  //    compare Q contents!!!!
  
  if(2 * i + 1 >= count - 1)
    return 2 * i + 1;
  else
    {
      if(Q[2 * i + 1] <= Q[2 * i + 2])
	return 2 * i + 1;
      else
	return 2 * i + 2;
    }
}


