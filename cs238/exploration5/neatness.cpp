/***********************************************************************
 * Program:
 *    Exploration 5, Neatness
 *    Brother Neff, CS238
 *
 * Author:
 *    Your Name Here
 *
 * Summary:
 *    Boolean Network building and simulating.
 *
 * Note:
 *    Some of this code is uncommented --- this is deliberate.
 *
 ***********************************************************************/

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;

/*******************************************************************
 * A class that represents a Wire with a current and a new boolean
 * value.  The new value is set by the operation of a Cell, and it
 * will become the current value after being updated, which typically
 * happens right before showing (outputting) the value.
 *******************************************************************/
class Wire
{
private:
   bool mValue;
   bool mNewValue;
   bool mUseStarAndBlank;

public:
   /****************************************************************
    * Constructs a new wire instance with a default value (false).
    ****************************************************************/
   Wire()
   {
      setValue(false);
      setNewValue(false);
      setUseStarAndBlank(true);
   }

   /****************************************************************
    * Constructs a new wire instance with a given value.
    ****************************************************************/
   Wire(bool pValue, bool pUseStarAndBlank = true)
   {
      setValue(pValue);
      setNewValue(false);
      setUseStarAndBlank(pUseStarAndBlank);
   }

   /******************************
    * Gets this wire's value.
    *******************************/
   bool getValue() const { return mValue; }

   /******************************
    * Gets this wire's new value.
    *******************************/
   bool getNewValue() const { return mNewValue; }

   /******************************
    * Sets this wire's value.
    *******************************/
   void setValue(bool pValue) { mValue = pValue; }

   /******************************
    * Sets this wire's new value.
    *******************************/
   void setNewValue(bool pNewValue) { mNewValue = pNewValue; }

   /******************************
    * Sets this wire's value to its new value.
    *******************************/
   void setValueToNew() { mValue = mNewValue; }

   /******************************
    * Gets this wire's display mode.
    *******************************/
   bool isUsingStarAndBlank() const
   {
      return mUseStarAndBlank;
   }

   /******************************
    * Sets this wire's display mode.
    *******************************/
   void setUseStarAndBlank(bool pUseStarAndBlank)
   {
      mUseStarAndBlank = pUseStarAndBlank;
   }

   /****************************************************
    * Gets the character representing this wire's value.
    ****************************************************/
   char getCharacterRepresentingValue() const
   {
      return
         (isUsingStarAndBlank() ?
          (getValue() ? '*' : ' ') :
          (getValue() ? '1' : '0'));
   }
};

/****************************************************************
 * Outputs a Wire.
 ****************************************************************/
ostream& operator<<(ostream& os, const Wire& w)
{
   os << w.getCharacterRepresentingValue();
   return os;
}

/****************************************************************
 * A class representing a Boolean function of degree 3.
 ****************************************************************/
class BooleanFunction3
{
protected:
   bool mValues[8];
public:
   BooleanFunction3()
   {
      for (int i = 0; i < 8; i++)
      {
         mValues[i] = false;
      }
   }

   BooleanFunction3(int values)
   {
      populate(values);
   }

   bool evaluate(bool p1, bool p2, bool p3)
   {
      int i = 0;
      if (p3)
      {
         i |= 1;
      }
      if (p2)
      {
         i |= 2;
      }
      if (p1)
      {
         i |= 4;
      }
      return mValues[i];
   }

   void populate(int values)
   {
      int i = 0;
      while (values > 0)
      {
         mValues[i++] = ((values & 1) == 1);
         values /= 2;
      }
   }
};

/****************************************************************
 * A Cell evaluating a boolean function of degree 3.
 ****************************************************************/
class Cell
{
public:
   /****************************************************************
    * Constructs a new Cell instance with a pointer to a Boolean
    * Function of degree 3, and three wires.
    *
    * This merely has the side effect of computing the boolean
    * function on the three wire inputs, storing the result in the
    * middle (output) wire.
    ****************************************************************/
   Cell(BooleanFunction3 * bfp, Wire& x, Wire& y, Wire& z)
   {
      y.setNewValue(bfp->evaluate(
         x.getValue(), y.getValue(), z.getValue()));
   }
};

/****************************************************************
 * getArgs gets command-line arguments.
 ****************************************************************/
void getArgs(int argc, char* argv[],
             unsigned int& booleanFunctionNumber,
             unsigned int& numberOfCells,
             unsigned int& numberOfSteps)
{
   // TODO 1: get program input a better way.

   assert(argc > 1);

   booleanFunctionNumber = atoi(argv[1]);

   numberOfCells = 100;

   if (argc > 2)
   {
      numberOfCells = atoi(argv[2]);
   }

   numberOfSteps = numberOfCells;

   if (argc > 3)
   {
      numberOfSteps = atoi(argv[3]);
   }
}

void updateAndDisplay(Wire wires[], unsigned int numberOfSteps)
{
   for (int i = 1; i <= numberOfSteps; i++)
   {
      wires[i-1].setValueToNew();
      cout << wires[i-1];
   }
   cout << endl;
}

/****************************************************************
 * buildNetworkAndStartItRunning should do just that.
 ****************************************************************/
void buildNetworkAndStartItRunning(unsigned int booleanFunctionNumber,
                                   unsigned int numberOfCells,
                                   unsigned int numberOfSteps)
{

   //creates numberOfCells Wires.
   Wire wires[numberOfCells];

   //set to true the new value of the middle-most Wire
   //(the middle of the whole array, *NOT* the middle wire of each cell).
   wires[(numberOfCells/2)].setNewValue(true);
   
   //update values to new values and show (output) all Wires.
   updateAndDisplay(wires, numberOfSteps);

   //create a BooleanFunction3 given the booleanFunctionNumber.
   BooleanFunction3 *BF = new BooleanFunction3(booleanFunctionNumber);
   
   for (int i = 0; i < numberOfSteps; i++)
   {
      for (int j = 0; j < numberOfCells-1; j++) {
         //create the network of Cells evaluating the BooleanFunction3
         // and connect them to the already-created Wires in the desired fashion.
         Cell(BF, wires[j-1], wires[j], wires[j+1]);
      }
      //update values to new values and show (output) all wires.
      updateAndDisplay(wires, numberOfSteps);
   }
}

/****************************************************************
 * For reporting on what was learned.
 ****************************************************************/
void howIcategorizedThePatternsIobserved()
{
   cout << "\tPatterns are all around us. We see it in food. We can see it in math. One of the many\n"
        << "things explored in discrete math are patterns. Pulling from our first exploration, that is\n"
        << "example of seeing patterns. We were able to see the different patterns that form through\n"
        << "doing computations over and over again. We are able to see patterns in this exploration,\n"
        << "especially when we run the boolean function 90. We see Pascal's triangle (commonly known as\n"
        << "the Tri-force from Zelda) form. Although these patterns were formed differently, they all\n"
        << "encompass the same thing: patterns can be found in and through anything around us.\n\n";
}

void howIMasteredTheBasicTerminologyAndOperationsOfBooleanLogicAndGatingNetworks()
{
   cout << "\tMastering the basic terminology and operations of boolean logic and gating Networks\n"
        << "is not the easiest. Through writing code to help solve and explore different discrete\n"
        << "math exercises and problems, I was able to help myself understand when, where and how\n"
        << "to use the proper operations. I am able to say, while I may not be a master, I have futhered\n"
        << "my understanding of the various operations available and also their relations to gating networks.\n\n";
}

void howIDemonstratedDiscreteMathematicalReasoningThroughSolvingProblems()
{
   cout << "\tThrough solving problems, I was able to demonstrate discrete mathmatical reasoning.\n"
        << "I learned that there are many problems in life which, when applied, can be solved through\n"
        << "discrete mathmatical reasoning. While many of these problems could have been solved in\n"
        << "different ways, using discrete mathmatical reasoning greatly increased the time and labor\n"
        << "put into solving these problems.\n\n";
}

void howIDiscernedBetweenEffectiveAndIneffectiveApproachesToProblemSolving()
{
   cout << "\tIn discrete math, there are a number of different problems which we are introduced\n"
        << "to during the semester. Each problem has different ways to approach from. Majority of\n"
        << "are ineffective at solving the problem, but great at causing stress and anger. Realizing\n"
        << "before hand if your solution is not going to work before you get too far is key in saving\n"
        << "precious time. The easiest way to do this is by talking to Brother Neff or whom ever is your\n"
        << "teacher. Realizing this without any aid is not easy. I learned to do this when I am working\n"
        << "and my solution or my current method of thinking is not making sense. I try to take an absract\n"
        << "look at the problem to see if there is a better path to take.\n\n";
}

void howISolvedProblemsUsingLimitedOrConstrainedResources()
{
   cout << "\tIn Brother Neff's discrete math class, when we are given an exploration, we are also\n"
        << "given code with it. Now, this code was not always easy to read and did not have comments.\n"
        << "Being able to take this though and analyzing the code to figure out what was going on was\n"
        << "key. Other times, we are given nothing and have to start from scratch. (Not in discrete math).\n"
        << "Whatever the case, being able to still solve the problem is key for a computer scientist.\n"
        << "In the workplace, we will be given guidelines of what is wanted, but it will be up to us to\n"
        << "solve the problem with our limited knowledge. Sometimes our current knowledge is not enough\n"
        << "and we need to search how to do something. That is still using your resources though.\n\n";
}

void howISynthesizedNewProblemSolvingConceptsByPuttingOldConceptsTogetherInNovelWays()
{
   cout << "\tNew problem solving techniques and concepts are always being created. Whether by me\n"
        << "or someone else, this is a part of life. To get these new concepts though, it takes old\n"
        << "solutions and concepts. Taking an old formula which you used and slightly changing it can\n"
        << "do the job. An example of this is when we had to do the amortization table. We were given\n"
        << "three of the four formulas to use in the exploration. The last one we had to take the same\n"
        << "formula over all, but mess with it and tweak it to fit our purpose. This included running\n"
        << "it through a loop to figure out our desired value.\n\n";
}

void howIRecognizedTheRelativeImportanceOfDifferentElementsOfAMathematicalOrComputerScienceProblem()
{
   cout << "\tRecogizing different elements in problems is a key step in solving the problem. If you\n"
        << "are not able to discern between what is what, how do you expect to know where to start?\n"
        << "Knowing the different elements in the problem is like knowing the different tools you have\n"
        << "to work with. The better you know them, the easier it is to find a solution/use them.\n\n";
}

void howIMadeConnectionsBetweenDiscreteMathematicsAndRealWorldApplications()
{
   cout << "\tIn class, we were always relating the problems we did and the concepts we learned\n"
        << "to real world applications. Being able to see where things can actually apply greatly\n"
        << "helped me to see the benefits of discrete math. An example of this is when we were talking\n"
        << "about logic and gates and had the homework problem of the vending machine. It showed me that\n"
        << "when we have a problem which can have logic situations, I can draw a map out using the logic\n"
        << "maps we learned in class to help me figure out what needs to happen when certain conditions are\n"
        << "met.\n\n";
}

void howIKnowHowDiscreteMathematicsAppliesToAllPartsOfComputerScience()
{
   cout << "\tHow does discrete math applies to all parts of computer science? I honestly cannot say. I know\n"
        << "that I can say that I see discrete math in all computer science things I have done to date. Learning\n"
        << "about the different sorts in 235, then actually learning how they work and apply in discrete math.\n"
        << "Knowing when to use something, or a certain algorithm is key to discrete math and also computer science.\n"
        << "I do know that discrete math is important in most applications of computer science, even web applications.\n"
        << "Knowing how to protect data and information using encryption is using discrete math. I am glad to say I know\n"
        << "discrete math, although not as well as I probably should.\n\n";
}

/*************************************************************************
 * How to use this program to be implemented here.
 *************************************************************************/
void usage(const char* programName)
{
   cout << "Usage: " << endl;
   cout << "\t" << programName << endl;
   cout << "\tThis displays the learned and useage function\n\n";
   cout << "\t" << programName << " [booleanFunctionNumber]                 (e.g. neatness 90)" << endl;
   cout << "\tThis allows you to set which boolean function you would like to use. Uses a default number of cells\n\n";
   cout << "\t" << programName << " [booleanFunctionNumber] [numberOfCells] (e.g. neatness 90 175)" << endl;
   cout << "\tThis allows you to also add how many cells you desire to use.\n\n";
}

