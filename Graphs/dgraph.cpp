//======================================================
// HW#: HW6 dgraph
// Name: Tyler Cochran
// File Type: dgraph implementation file
//========================================================

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"

dgraph::dgraph() // initialize vertexName (blank) and visit numbers (0)    // initialize countUsed to be 0
{
  for(int i = 0; i < SIZE; i++)
    {
      Gtable[i].vertexName = ' ';
      Gtable[i].visit = 0;
    }
  countUsed = 0;
}

dgraph::~dgraph() // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{
}

void dgraph::fillTable() // be sure to read from a specified file
{
  string fname;
  cout << "Enter a file name: ";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in); // declare and open fname
  
  char x;    // variable to hold elements being read from file
  
  while(fin >> Gtable[countUsed].vertexName)
    {
      fin >> Gtable[countUsed].outDegree;
      
      for(int i = 0; i < Gtable[countUsed].outDegree; i++)
	{
	  fin >> x;
	  Gtable[countUsed].adjacentOnes.addRear(x);
	}
      countUsed++;
    }
  fin.close();
}

void dgraph::displayGraph() // be sure to display
{
  // in a really nice table format -- all columns but no unused rows 
  cout << "\n" << "  Out Visit Adj" << endl;
  cout << "-------------------" << endl;
  
  for(int i = 0; i < countUsed; i++)
    {
      cout << Gtable[i].vertexName << " ";
      cout << Gtable[i].outDegree << "     ";
      cout << Gtable[i].visit << "   ";
      Gtable[i].adjacentOnes.displayAll();    
    }
  cout << endl;
}

int dgraph::findOutDegree(char V) // throws exception
{
  // does not use a loop
  int slot;
  
  slot =(int)V - 65;
  
  if(Gtable[slot].vertexName == V)
    return Gtable[slot].outDegree;
  else
    throw BadVertex();
}

slist dgraph::findAdjacency(char V) // throws exception
{
  // does not use a loop
  int slot;
  
  slot = (int)V - 65;
  
  if(Gtable[slot].vertexName == V)
    return Gtable[slot].adjacentOnes;
  else
    throw BadVertex();
}
