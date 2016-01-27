/***********************************************************************
 * Program:
 *    Exploration 4, Ripeness
 *    Brother Neff, CS238
 *
 * Author:
 *    Your Name Here
 *
 * Summary:
 *    Tree Structure time-for-space traversal tradeoff and
 *    Tournament Sort
 *
 * Note:
 *    This code is mostly uncommented --- this is deliberate.
 *
 ***********************************************************************/

#include <cmath>
#include <climits> // for INT_MIN
#include <iostream>
using namespace std;

/******************************************************
 *The class that we use to create each node
 ***************************************************/
class Node
{
private:
   int mValue;
   Node* mLeft;
   Node* mRight;
public:
   Node(int inValue) { mValue = inValue; mLeft = NULL; mRight = NULL; }
   int getValue() { return mValue; }
   Node* getLeft() { return mLeft; }
   void setLeft(Node* inLeft) { mLeft = inLeft; }
   Node* getRight() { return mRight; }
   void setRight(Node* inRight) { mRight = inRight; }
   void setValue(int inValue) { mValue = inValue; }
};

//Overloaded extraction operator for nodes.
ostream& operator<<(ostream& os, Node* node)
{
   if (node != NULL)
   {
      os << node->getValue() << " ";
      os << node->getLeft();
      os << node->getRight();
   }
   return os;
}

/************************************
 * The class for our Tree
 *************************************/
class Tree
{
private:
   static int cNextNodeNumber;
   int mHeight;
   Node* mRoot;
   //builds the tree when called according to the height given
   Node* buildTree(int height)
   {
      Node* root = new Node(cNextNodeNumber++);
      if (height > 0)
      {
         root->setLeft(buildTree(height - 1));
         root->setRight(buildTree(height - 1));
      }
      return root;
   }

public:
   Tree(int height)
   {
      mHeight = height;
      mRoot = buildTree(height);
   }

   Node* getRoot() { return mRoot; }

   //the different kinds of traversals
   void traversePreorder()
   {
      traverse(mRoot, -1);
   }
   void traverseInorder()
   {
      traverse(mRoot, 0);
   }
   void traversePostorder()
   {
      traverse(mRoot, 1);
   }

   void traverse(Node* node, int tType)
   {
      if (node == NULL) return;
      if (tType == -1)
      {
         visit(node);
      }
      traverse(node->getLeft(), tType);
      if (tType == 0)
      {
         visit(node);
      }
      traverse(node->getRight(), tType);
      if (tType == 1)
      {
         visit(node);
      }
   }

   void visit(Node* node)
   {
      cout << node->getValue() << " ";
   }

   //one kind of level traversing
   void traverseLevel1()
   {
      const int MAX = 128;
      Node* queue[MAX];
      Node* temp;
      int front = 0;
      int back = 0;

      queue[back++] = mRoot;

      while (front != back)
      {
         temp = queue[front];
         front = (front + 1) % MAX;
         if (temp != NULL)
         {
            cout << temp->getValue() << " ";
            queue[back] = temp->getLeft();
            back = (back + 1) % MAX;
            queue[back] = temp->getRight();
            back = (back + 1) % MAX;
         }
      }
   }

   //a second kind of level traversing
   void traverseLevel2()
   {
      for (int level = 0; level <= mHeight; level++)
      {
         int maxWhich = (int) pow((double) 2, (double) level);
         for (int which = 1; which <= maxWhich; which++)
         {
            visit(findNode(mRoot, level, which));
         }
      }
   }

   //finds the node declared by level and which
   Node* findNode(Node* start, int level, int which)
   {
      int maxWhich = (int) pow((double) 2, (double) level);
      int halfway = maxWhich / 2;

      if (level == 0)
         return start;
      if (which > halfway)
         findNode(start->getRight(), level-1, which - halfway);
      else if (which < halfway + 1)
         findNode(start->getLeft(), level-1, which);
   }

};

//determines which child node is greater than
void isLarger(Node* groot)
{  
   if (groot->getLeft()->getValue() > groot->getRight()->getValue())
      groot->setValue(groot->getLeft()->getValue());
   else
      groot->setValue(groot->getRight()->getValue());
}

//overloaded extraction operator for the tree
ostream& operator<<(ostream& os, Tree& tree)
{
   os << tree.getRoot();
   return os;
}

int Tree::cNextNodeNumber = 0;

/*************************************************************************
 * treeTraversal
 *
 * Makes a tree of specified height, then outputs a printed representation
 * of the tree followed by output from calling the traversal functions:
 * PRE-order, IN-order, POST-order, LEVEL-order and (versions 1 and 2).
 *************************************************************************/
void treeTraversal(int height)
{
   Tree tree(height);
   cout << tree << endl;
   tree.traversePreorder();
   cout << endl;
   tree.traverseInorder();
   cout << endl;
   tree.traversePostorder();
   cout << endl;
   tree.traverseLevel1();
   cout << endl;
   tree.traverseLevel2();
   cout << endl;
}

/*************************************************************************
 * Tournament Sort implemented here.
 *
 * TODO: if you think it will help, add to (but don't subtract from) the
 * above-defined classes, and/or make other helper functions.
 *
 * Takes the array and inserts into a tree at the leaf nodes. It then perculates
 * up to find the greatest number. Inserts it into a new array and then rense
 * and repeat.
 *************************************************************************/
void tournamentSort(int array[], int size)
{
   int height = log2(size);
   Tree tourney(height);
   int newArray[size];

    //this populates the tree's leaves with the values in the array.
   for (int i = 1; i < size + 1; i++)
   {
      tourney.findNode(tourney.getRoot(), height, i)->setValue(array[i - 1]);
   }

   //Rense and repeat for each leaf node
   for (int sort = 0; sort < size; sort++)
   {
      //goes to the level above the leaves and then compares and pulls which
      //is greater.

      for (int i = height - 1; i >= 0; i--)
      {
         //finds which spot in the level we are at
         for (int j = 1; j <= pow(2, i); j++)
         {
            //checks which is larger and sets it
            isLarger(tourney.findNode(tourney.getRoot(), i, j));
         }
      }
      isLarger(tourney.getRoot());

      //saves the root into the array 
      newArray[sort] = tourney.getRoot()->getValue();

      //goes and finds where our root is the leaf and replaces it with -1
      for (int i = 1; i < size + 1; i++)
      {
         if (tourney.findNode(tourney.getRoot(), height, i)->getValue() ==
             tourney.getRoot()->getValue())
         {
            tourney.findNode(tourney.getRoot(), height, i)->setValue(-1);
            break;
         }
      }
   }

   //saves the new array into the old array
   for (int i = 0; i < size; i++)
      array[i] = newArray[i];
   
}

/*************************************************************************
 * What was learned.
 *************************************************************************/
void learned()
{
   cout << "Learned: \n";
   cout << "\tRipeness... How ripe can a tree get? We explore trees and\n"
        << "the tournament sort learned in class. We personally were to\n"
        << "implement how to find which node we want given a level and spot\n"
        << "and return it. We also were to implement the tournament sort.\n"
        << "\tI learned that when working on hard problems, collaboration is\n"
        << "vital. Working with Braden, Issac, and Kendall; We were able to\n"
        << "our tournament sort working. Alone, it would have taken us a lot\n"
        << "longer. But by putting our minds together and pooling our\n"
        << "knowledge, we got it done much quicker than anticipated.\n"
        << "\tI also learned that even though you may write a solution,\n"
        << "there is always a way to make it neater and cleaner.";
}

/*************************************************************************
 * How to use this program.
 *************************************************************************/
void usage(const char* programName)
{
   cout << "\n\nUsage: \n"
        << "\tripeness --- This just calls the learned and usage functions\n"
        << "\tripeness <treet OR/AND tsort> --- This calls the tree traversal"
        << "(treet)\n"
        << "\t\t\t\tOR/AND the tournament sort (tsort). It\n"
        << "\t\t\t\twill display according to which you call.\n";
}
