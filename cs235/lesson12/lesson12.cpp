/***********************************************************************
* Program:
*    Lesson 12, Graph
*    Brother Helfrich, CS 235
* Author:
*    Br. Helfrich
* Summary: 
*    This is a driver program to exercise the Graph class.  When you
*    submit your program, this should not be changed in any way.  That being
*    said, you may need to modify this once or twice to get it to work.
************************************************************************/

#include <iostream>      // for CIN and COUT
#include <fstream>       // for IFSTREAM
#include <string>        // for STRING
#include "graph.h"       // for Graph class which should be in graph.h
#include "vertex.h"      // for Vertex, LVertex, and CVertex
#include "maze.h"
using namespace std;

int Vertex::max = 10;

// prototypes for our four test functions
void testSimple();
void testAdd();
void testQuery();
void testFindAll();

// To get your program to compile, you might need to comment out a few
// of these. The idea is to help you avoid too many compile errors at once.
// I suggest first commenting out all of these tests, then try to use only
// TEST1.  Then, when TEST1 works, try TEST2 and so on.
#define TEST1   // for testSimple()
#define TEST2   // for testAdd()
#define TEST3   // for testQuery()
#define TEST4   // for testFindAll()

/**********************************************************************
 * MAIN
 * This is just a simple menu to launch a collection of tests
 ***********************************************************************/
int main()
{
   // menu
   cout << "Select the test you want to run:\n";
   cout << "\t1. Just create and destroy a graph\n";
   cout << "\t2. The above plus add a few entries\n";
   cout << "\t3. Determine if two verticies are connected\n";
   cout << "\t4. Find all the verticies connected to a given vertex\n";
   cout << "\ta. Maze\n";

   // select
   char choice;
   cout << "> ";
   cin  >> choice;
   switch (choice)
   {
      case 'a':
         solveMaze();
         break;
      case '1':
         testSimple();
         cout << "Test 1 complete\n";
         break;
      case '2':
         testAdd();
         cout << "Test 2 complete\n";
         break;
      case '3':
         testQuery();
         cout << "Test 3 complete\n";
         break;
      case '4':
         testFindAll();
         cout << "Test 4 complete\n";
         break;
      default:
         cout << "Unrecognized command, exiting...\n";
   }

   return 0;
}

/*******************************************
 * TEST SIMPLE
 * Very simple test for a Graph: create and destroy
 ******************************************/
void testSimple()
{
#ifdef TEST1
   // Test1: a graph on the stack
   cout << "Create a graph of 10 verticies\n";
   Graph g(10);
   
   // Test2: a graph in the heap
   cout << "Create a graph of 20 verticies\n";
   Graph * p = new Graph(20);
   delete p;
   
#endif //TEST1
}

/*******************************************
 * TEST ADD
 * Add a few elements to our Graph
 *****************************************/
void testAdd()
{
#ifdef TEST2
   // create a graph
   cout << "Create a graph of 5 verticies\n";
   Graph g(5);
   LVertex v1;
   LVertex v2;
   v1.setMax(5);

   // A --> B
   cout << "\tA --> B\n";
   v1.setText(string("A"));
   v2.setText(string("B"));
   g.add(v1, v2);

   // B --> C
   cout << "\tB --> C\n";
   v1.setText(string("B"));
   v2.setText(string("C"));
   g.add(v1, v2);

   // C --> A
   cout << "\tC --> A\n";
   v1.setText(string("C"));
   v2.setText(string("A"));
   g.add(v1, v2);

   

   //  D --> A
   //  D --> B
   //  D --> C
   //  D --> D
   cout << "\tD --> {A, B, C, D}\n";
   v1.setText(string("D"));
   Set <Vertex> s;
   v2.setText(string("A"));
   s.insert(v2);
   v2.setText(string("B"));
   s.insert(v2);
   v2.setText(string("C"));
   s.insert(v2);
   v2.setText(string("D"));
   s.insert(v2);
   g.add(v1, s);   

   //g.display();
   
#endif // TEST2   
}

int CVertex::maxCol = 0;

/*******************************************
 * TEST Query
 * Determine if two verticies are connected
 * in a given graph
 *******************************************/
void testQuery()
{
#ifdef TEST3
   // read the verticies from a file
   Graph g(readMaze("/home/cs235/lesson12/maze5x5.txt"));

   // need some variables
   CVertex vFrom;
   CVertex vTo;
   
   // allow the user to prompt for verticies  
   cout << "Determine if a given edge exists in the graph\n";
   cout << "> ";
   while (cin >> vFrom >> vTo)
      cout << '\t' << vFrom << " - " << vTo
           << " is " << (g.isEdge(vFrom, vTo) ? "" : "NOT ")
           << "an edge\n"
           << "> ";
#endif // TEST3
}


/*******************************************
 * TEST Find All
 * Create a Graph and find all the edges
 ******************************************/
void testFindAll()
{
#ifdef TEST4
   Graph g(28);
   CourseVertex vFrom;
   CourseVertex vTo;

   // read the class dependencies from a file
   // CS124 CS165 CIT225 ECEN160 |
   ifstream fin("/home/cs235/lesson12/cs.txt");
   assert(fin.good());
   while (fin >> vFrom)  // read the first vertex, the class
   {
      while (fin >> vTo) // keep reading until the "|" is encountered
         g.add(vFrom, vTo);
      fin.clear();       // clear the error state which came from the "|"
      fin.ignore();
   }
   fin.close();

   // prompt for the next class
   cout << "For the given class, the prerequisites will be listed:\n";
   cout << "> ";
   while (cin >> vFrom)
   {
      Set <Vertex> s = g.findEdges(vFrom);

      for (SetIterator <Vertex> it = s.begin(); it != s.end(); ++it)
         cout << '\t' << (vTo = *it) << endl;
      
      cout << "> ";
   }
   

#endif // TEST4
}

