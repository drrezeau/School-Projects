/************************************************************
 * Component:
 *    Lesson 12, Graph.cpp
 *    Brother Helfrich, CS 235
 * Author:
 *    David Lambertson and Derek Calkins
 * Summary:
 *    These are the functions that are too long too be
 *    inline in our graph.h.
 ************************************************************/
#include "graph.h"

/***********************************************
 * IS EDGE
 * This function determines if two vertices are connected
 * or not.
 **********************************************/
bool Graph:: isEdge(const Vertex& one, const Vertex& two) const
{
   //loop through all of the vertices
   for (int i = 0; i < numItems; ++i)
   {
      //start look at vertex one connections
      if (*(array[i].front()) == one)
      {
         //loop through connections
         for (ListIterator<Vertex*> it = array[i].begin();
              it != array[i].end(); ++it)
         {
            //we find two, we are connected
            if (**it == two)
            {
               return true;
            }
         }
      }
   }
   //if there is no connection
   return false;
}

/***********************************************
 * FIND EDGES
 * This function finds all of the connections for a given
 * vertex and returns the set of vertices that are connected
 * to that vertex.
 **********************************************/
Set<Vertex> Graph:: findEdges(const Vertex & v)
{
   Set<Vertex> s;
   //finds the integer value of the vertex
   int spot = findSrc(v);
   //loop through all of the edges connected to vertex v
   for (ListIterator<Vertex*> it = array[spot].begin();
        it != array[spot].end(); ++it)
   {
      //if we are not ourself, insert into set
      if (!(**it == v))
         s.insert(**it);
   }
   return s;
}

/***********************************************
 * ADD - one Vertex Connection
 * This function takes two vertices and connects them
 * together.
 **********************************************/
void Graph:: add(const Vertex& one, const Vertex& two)
{
   //finds the integer value of the vertex one
   int spot = findSrc(one);

   //if we couldn't find the vertex already in the vector array
   //add a new item with a connection
   if (spot == numItems)
   {
      array[spot].push_back(new Vertex(one));
      numItems++;
   }

   //if we are found in the array, just add another node to the list of
   //connections
   array[spot].push_back(new Vertex(two));
}

/***********************************************
 * ADD - w/ a Set of Vertices
 * This function takes a vertex and a set of vertices
 * and connects all of them to the first vertex (v).
 **********************************************/
void Graph:: add(const Vertex& v, Set<Vertex> vertices)
{
   //adds a new vertex
   array[numItems].push_back(new Vertex(v));
   //adds all of the connected vertices to that new vertex
   for(SetIterator <Vertex> it = vertices.begin();
       it != vertices.end(); ++it)
   {
      array[numItems].push_back(new Vertex(*it));
   }
   //one more vertex added
   numItems++;
}

/***********************************************
 * FIND PATH
 * This function takes a start vertex and end vertex
 * and finds a viable path from start to end.
 **********************************************/
Vector<Vertex> Graph:: findPath(const Vertex& start, const Vertex& end)
{
   int depth[start.getMax()];     //holds the depth of a given vertex
   Vertex parent[start.getMax()]; //holds the parent of a given vertex
   bool visited[start.getMax()];  //if we have or have not been to vertex
      
   Vector<Vertex> path;                   //holds the path
   Queue<Vertex> breadth(start.getMax()); //holds the breadth of vertices
   Set<Vertex> connectedVertices;         //holds the set of connections
      
   //set all of the vertices to false because none have been visited
   for (int i = 0; i < start.getMax(); ++i)
      visited[i] = false;

   //push start vertex on queue
   breadth.push(start);

   //while we have reached the end of the maze
   while (!breadth.empty())
   {
      int index = breadth.front().index();

      //if we have already visited this vertex, skip
      if (visited[index] == true)
      {
         break;
      }

      //if we are the start vertex
      if(index == 0)
      {
         parent[index];
         depth[index] = 0;
      }

      //for every other vertex
      else
         depth[index] = depth[parent[index].index()] + 1;

      //now we have visited this vertex
      visited[index] = true;

      //if we have reached the end of the maze
      //we don't need to find children
      if (breadth.front() == end)
         break;
      
      //finds the children of a given vertex
      connectedVertices = findEdges(breadth.front());
      for (SetIterator<Vertex> it = connectedVertices.begin();
           it != connectedVertices.end(); ++it)
      {
         //pushes the children onto the queue
         breadth.push((*it));
         //sets their parent at the current vertex
         parent[(*it).index()] = breadth.front();
      }

      //pop off the vertex and continue
      breadth.pop();  
         
   }

   //push the end vertex onto the vector path
   path.push_back(end);
   //push every parent successively onto the vector path
   for (int i = end.index(); i > 0; i = parent[i].index())
      path.push_back(parent[i]);
      
   //return the path
   return path;
      
}
