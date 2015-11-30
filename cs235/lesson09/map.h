/***********************************************************************
* Program:
*    Lesson 09, Map and balanced BSTs
*    Brother Helfrich, CS 235
* Author:
*    David Lambertson and Derek Calkins
* Summary: 
*    this is a Abstract Data Type : Map
*    It allows a user to create their own maps and use the square 
*    bracket operator to save new keys or access old keys
************************************************************************/
#ifndef MAP_H
#define MAP_H

#include "bst.h"
#include "pair.h"

template <class T, class U>
class MapIterator;

/******************************************
 * All the private and public member variables and
 * methods for which a Map needs to work how we desire.
 *****************************************/
template <class T, class U>
class Map
{
  public:
   //default constructor
  Map(): tree(), numItems(0) {}
   //copy constructor
  Map(Map<T, U> & rhs) : tree(), numItems() { this = rhs; }
   //destructor
   ~Map() { clear(); }

   //Our simple empty, size and clear functions.
   bool empty() {return (numItems == 0); }
   int size() { return numItems; }
   void clear()
   {
      tree.clear();
      numItems = 0;
   }

   /**********************************
    * assignment operator to copy a Map.
    ********************************/
   Map<T, U> & operator =(Map<T, U> & oldMap)
   {
      this->tree = oldMap.tree;
      this->numItems = oldMap.numItems;
      return *this;
   }

   //square bracket operator, see below.
   U & operator [](const T & key);

   //begin, end, rbegin, rend functions returning Iterators
   MapIterator<T, U> begin() { return MapIterator<T, U>(tree.begin());  }
   MapIterator<T, U> end()   { return MapIterator<T, U>(tree.end());    }
   MapIterator<T, U> rbegin(){ return MapIterator<T, U>(tree.rbegin()); }
   MapIterator<T, U> rend()  { return MapIterator<T, U>(tree.rend());   }

   //find function which calls our BST find function
   MapIterator<T, U> find(const T & value)
   {
      Pair<T , U> temp;
      temp.first = value;
      return MapIterator<T, U>(tree.find(temp));
   }

   //allows us to access which ever node we desire to find.
   BSTIterator<Pair<T, U> > getNode(T value)
   {
      Pair<T, U> temp;
      temp.first = value;
      return tree.find(temp);
   }
 
                    
  private:
   BST<Pair<T, U> > tree;
   int numItems;
};

/**********************************************
 * Square Bracket Operator
 * allows users to either save a new key within
 * the map or display our value for the key given to us.
 *********************************************/
template <class T, class U>
U & Map<T, U> :: operator [](const T & key)
{
   Pair<T, U> temp;
   temp.first = key;
   if (tree.find(temp) == NULL)
   {
      tree.insert(temp);
      numItems++;
   }
   BSTIterator<Pair<T ,U> > it = tree.find(temp);
   return (*it).second;
}



/************************************************
 * This is the class definition for the Binary
 * Search Tree Iterator.
 **********************************************/
template <class T, class U>
class MapIterator
{
  public:
   //default constructor
  MapIterator() : it(NULL) {}

   //non-default constructor
   MapIterator(BSTIterator<Pair<T, U> > p) { it = p; }

   //assignment operator
   MapIterator<T, U> operator =(const MapIterator<T, U> & rhs)
   {
      this->it = rhs.it;
      return *this;
   }

   //are they equal?
   bool operator ==(const MapIterator<T, U> & rhs)
   { return (this->it == rhs.it); }

   //are they not equal?
   bool operator !=(const MapIterator<T, U> & rhs)
   { return (this->it != rhs.it); }

   //dereference operator
   U & operator *() { return (*it).second; }

   //overloaded operators, ++ and --
   MapIterator<T, U> operator ++() { ++it; return *this; }
   MapIterator<T, U> operator --() { --it; return *this; }

  private:
   //so we have access to the BST
   BSTIterator<Pair<T, U> > it;

};

#endif // MAP_H
