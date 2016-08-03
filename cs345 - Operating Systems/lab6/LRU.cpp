/***********************************************************************
* Program:
*    Lab PageReplacement
*    Brother Jones, CS 345
* Author:
*    Palmer Cluff
* Summary:
*    The LRU algorithm.
************************************************************************/

#include "vmalgorithm.h"
#include <vector>

/**************************************************************************
 * Function:
 *    void LRU::execute() - Executes the LRU page replacement algorithm
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
void LRU::execute()
{
   int page;
   int i = 0;
   bool fault = false;
   vector<int> requests;
   int counter[NUM_FRAMES];
   int count = 0;
   int largest = 0;
   int maxOut = 0;

   for (int i = 0; i < NUM_FRAMES; i++)
   {
      counter[i] = 0;
      frames[i] = 0;
   }

   while ((page = myPageFactory->getPage()) != -1)
   {
      requests.push_back(page);

      if (hit(page) != -1)
      {
         fault = false;
      }

      //No pages in frames
      else
      {
         fault = true;

         if (maxOut< NUM_FRAMES)
         {
            ++maxOut;
            frames[i] = page;
            i++;
         }

         else
         {
            int size = requests.size();

            for (int j = 0; j < NUM_FRAMES; j++)
            {
               for (int n = 0; n < size; n++)
               {
                  if (frames[j] == requests.at(size - (n + 1)))
                  {
                     break;
                  }

                  count++;
               }

               counter[j] = count;
               count = 0;

            }

            int max = counter[0];

            largest = 0;

            for (int j = 0; j < NUM_FRAMES; j++)
            {
               if (counter[j] > max)
               {
                  max = counter[j];

                  largest = j;

               }
            }

            frames[largest] = page;

         }
      }

      display(page, frames, fault);
   }
}

