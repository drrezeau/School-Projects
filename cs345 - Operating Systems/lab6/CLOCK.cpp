/***********************************************************************
* Program:
*    Lab PageReplacement
*    Brother Jones, CS 345
* Author:
*    Palmer Cluff
* Summary:
*    The CLOCK algorithm.
************************************************************************/
/*
**====================================================================**
* The following will be filled out for the second submission.  For the
* first submission, you may leave it in your code or delete it.
*
* The second submission should be submitted to labPageReplacementT2.
* (Which means the third line of the headers in CLOCK.cpp, FIFO.cpp and
* LRU.cpp files need to have a "T2" added onto the name of the lab.)
**====================================================================**
*
* Changes made to my code for the re-submission:
*   (examples:)
*   -I added comments such that they would help me remember what I did to
*    write this program in another six months.
*   -Fixed an error, ...
*   - ...
*
************************************************************************/

#include "vmalgorithm.h"

/**************************************************************************
 * Function:
 *    void CLOCK::execute() - Executes the CLOCK page replacement algorithm
 * Inherited Variables and Methods:
 *    int NUM_FRAMES: How many frames there are in 'memory'. (eg. 4)
 *    int frames[NUM_FRAMES]: The array that contains the pages resident
 *          in memory.  Use this array for the pages in memory.  
 *          See Also: NUM_FRAMES
 *    int hit(int page): Function that scans the 'frames[]' array, searching
 *          for 'page'.  If 'page' is found, it will return the index of 
 *          the 'frames[]' array.  If the page is not found, the function
 *          returns '-1'.
 *    int myPageFactory->getPage(): Returns the next page the psuedo-program 
 *          requests.  When there are no more pages to return, this function
 *          returns a -1.
 *    void display(int page, int frames[], bool fault): Function to display
 *          the information to stdout.  The parameter 'page' is the current
 *          page (the one returned from myPageFactory->getPage()), 'frames[]'
 *          is the array of the current resident set, and when 'fault' is 
 *          true, the display function will indicate it to the screen. 
 *          This function must be called for every page that is accessed.
 *************************************************************************/ 
void CLOCK::execute()
{
   bool fault;
   int count = 0;
   int reference [NUM_FRAMES];
   int page;

   for (int i = 0; i < NUM_FRAMES; i++)
   {
      reference[i] = 0;
   }

   while ( (page = myPageFactory->getPage()) != -1 )
   {
      int hitLocation = hit(page);
      fault = false;

      if (hitLocation == -1)
      {
         while(reference[count] == 1)
         {
            reference[count] = 0;
            count++;
            count = count % NUM_FRAMES;
         }

         frames[count] = page;

         reference[count] = 1;

         count++;
         count = count % NUM_FRAMES;

         fault = true;
      }
      
      else
      {
         reference[hitLocation] = 1;
      }

      display(page, frames, fault);
   }
}

