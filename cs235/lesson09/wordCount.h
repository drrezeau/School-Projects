/***********************************************************************
* Header:
*    WORD COUNT
* Summary:
*    This will contain just the prototype for the wordCount()
*    function
* Author
*    Derek Calkins and David Lambertson
************************************************************************/

#ifndef WORD_COUNT_H
#define WORD_COUNT_H

/*******************************************
 * this is a dummy int class so that we can
 * use a default constructor of 0.
 *****************************************/
class Count
{
  public:
   //default constructor
  Count(): count(0) {}
   //non-default constructor
  Count(const int & count) : count(count) {}
   //returns the number for which we want
   int getCount() const { return count; }
   //++ overloaded to increment
   Count operator ++ ()
   {
      ++count;
      return *this;
   }

   //assignment operator overloaded to let us save a new number
   Count operator = (const int & rhs)
   {
      count = rhs;
      return *this;
   }
   
  private:
   int count;
   
};

/*****************************************************
 * WORD COUNT
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/
void wordCount();

#endif // WORD_COUNT_H

