// ================================================
// HW#: HW6 dgraph client 
// Name: Tyler Cochran
// File type: HW6 client file (tester)
// ================================================

#include "dgraph.h"

int main()
{ 
  dgraph myTable;  // declare table object
  string choice;   // choice for whether the user wants to enter vertex
  char vertex;     // variable to hold vertex name inputed by user
  int outDeg;      // holds the out degree of a vertex
  slist L1;        // holds the adjacent vertices for a vertex
  
  myTable.fillTable();
  myTable.displayGraph();
  
  cout << "Would you like to enter a vertex name? 'No' to exit: ";
  cin >> choice;
  
  while(choice != "No")
    {
      try
	{
	  cout << "Enter Vertex Name: ";
	  cin >> vertex;
	  
	  outDeg = myTable.findOutDegree(vertex);
	  cout << "Vertex Out Degree: " << outDeg << endl; 
	  
	  L1 = myTable.findAdjacency(vertex);
	  L1.displayAll();
	  cout << endl;
	}
      
      catch(dgraph::BadVertex)
	{
	  cerr << "Invalid Vertex" << endl << endl;
	}
      
      cout << "Would you like to enter another vertex name? 'No' to exit: ";
      cin >> choice;
    }
}

/*
Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.

*/
