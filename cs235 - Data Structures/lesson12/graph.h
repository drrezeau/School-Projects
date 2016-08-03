/***********************************************************************
 * Component:
 *    Lesson 12, Graph.h
 *    Brother Helfrich, CS 235
 * Author:
 *    David Lambertson and Derek Calkins
 * Summary:
 *    Definition of our Graph class with its member variables and methods.
 ************************************************************************/
#ifndef GRAPH_H
#define GRAPH_H

#include "vector.h"
#include "vertex.h"
#include "set.h"
#include "list.h"
#include "queue.h"

/********************************************************
 * the class definition for the Graph used to solve mazes.
 * It is a directed graph that is created.
 ********************************************************/
class Graph
{
  public:
  Graph(int numV) : numVertices(numV), numItems(0)
   { array = new List<Vertex*>[numV]; }
      
   //The overloaded equals operator
   Graph operator =(const Graph & rhs)
   {
      for (int i = 0; i < rhs.size(); ++i)
      {
         this->array[i] = rhs.array[i];
      }
      this->numVertices = rhs.numVertices;
      this->numItems = rhs.numItems;
      return *this;
   }

   //Returns the size and the actual number of items within the array.
   int size() const { return numVertices; }

   //checks to see if there is an edge
   bool isEdge(const Vertex& one, const Vertex& two) const;

   //returns a set that contains all the edges from given vertex
   Set<Vertex> findEdges(const Vertex & v);

   //prototype for our findPath function returns a Vector of Vertices
   Vector<Vertex> findPath(const Vertex& start, const Vertex& end);

   //two different ways to add to the Graph, either just two vertices,
   //Or add a vertex with edges to a set of Vertices
   void add(const Vertex& one, const Vertex& two);
   void add(const Vertex& v, Set<Vertex> vertices);
  
   
  private:
   int numVertices;
   int numItems;
   List<Vertex*> *array;

   /************************************************
    * loops through the array of lists, looking at
    * just the first item and sees if there is already
    * a vertex with that value and returns the spot
    * at which it was found
    ***********************************************/
   int findSrc(const Vertex& value)
   {
      int src;
      for ( src = 0; src < numItems; src++)
      {
         if (*(array[src].front()) == value)
            return src;
      }
      return src;
   }
};

#endif // GRAPH_H
