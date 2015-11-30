#include <cstdlib>
#include <NTL/ZZ.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>

NTL_CLIENT

/******************************************************************************
 * Find b^n % m.
m ******************************************************************************/
ZZ modExp(ZZ b, ZZ n, ZZ m)
{
   return to_ZZ(PowerMod(b,n, m));
}

/******************************************************************************
 * Find i such that a * i is congruent to 1 (mod m).
 ******************************************************************************/
ZZ findInverse(ZZ a, ZZ m)
{
   return InvMod(a, m);
}

/******************************************************************************
 * Convert from a text message representing a base 27 number to a ZZ number.
 ******************************************************************************/
ZZ fromBase27(string message)
{
   ZZ value;
   ZZ number;

   for (long i = message.length() - 1; i >=0; i--)
   {
      double n;
      if (message[n] == '@')
      {  
         value = 0;
      }
      else
      {
         value = int(message[n]) - 64;
         value = value * power(to_ZZ(27),i);
      }
      
      n++;

      number += value;
   }
      return number;
}

/******************************************************************************
 * Convert from a ZZ number to a base 27 number represented by a text message.
 ******************************************************************************/
string toBase27(ZZ n)
{
   string decrypted;
   
   for ( long i = 10; i > 0; i--)
   {
      long newV = n % 27;
      n /= 27;
       decrypted[i] = char(newV+64);
   }
      
}

/******************************************************************************
 * Find a suitable e for a ZZ number that is the "totient" of two primes.
 ******************************************************************************/
ZZ findE(ZZ t)
{
   ZZ num = to_ZZ(100);
   for (ZZ i = to_ZZ(2); i < num; i++ )
      if ( GCD(i, t) == 1)
         return i;
   
}

/******************************************************************************
 * Find suitable primes p and q for encrypting a ZZ number that is the message.
 ******************************************************************************/
void findPandQ(ZZ m, ZZ& p, ZZ& q)
{
   long err = 10;
   long l = 50;
   p = GenPrime_ZZ(l, err);

   q = GenPrime_ZZ(l, err);

}

/******************************************************************************
 * Replace all '@' characters in a string with ' ' (space) characters.
 ******************************************************************************/
void replaceAllAtSignsWithSpaces(string& message)
{
   size_t index = 0;
   while ((index = message.find_first_of('@', index)) >= 0 &&
          index <= message.length())
   {
      message.replace(index++, 1, 1, ' ');
   }
}

/******************************************************************************
 * Drive the RSA Encryption/Decryption process.
 ******************************************************************************/
int main(int argc, char* argv[])
{
   if (argc < 2)
   {
      cout << "Usage: " << argv[0] << " message\n";
      return 1;
   }
   
   if (isalpha(argv[1][0])) // if message is alphabetic (encrypting)
   {
      // Get the message to encrypt
      string message;

      for (int i = 1; i < argc; i++)
      {
         int j = 0;
         while (argv[i][j] != '\0') // until end of word
         {
            if (isalpha(argv[i][j])) // Make sure chars are text
            {
               message += toupper(argv[i][j]);
               j++;
            }
            else
            {
               cerr << "\n--ERROR--  Can only use text and spaces.\n\n";
               return 1;
            }
         }
         if (i != argc - 1) // if not the last word
         {
            message += "@";
         }
      }

      ZZ m = fromBase27(message);
      ZZ p;
      ZZ q;

      findPandQ(m, p, q);

      ZZ n = p * q;
      ZZ t = (p - 1) * (q - 1);
      ZZ e = findE(t);

      ZZ encrypted = modExp(m, e, n);

      cout << encrypted << " " << p << " " << q << " " << e << endl;

      replaceAllAtSignsWithSpaces(message);

      // output verbose results to standard error to not interfere with test
      cerr << endl
           << "Text (base 27) = " << message << endl
           << "Message        = " << m << endl
           << "Encrypted      = " << encrypted << endl
           << endl
           << "p = " << p << endl
           << "q = " << q << endl
           << "n = " << n << endl
           << "t = " << t << endl
           << "e = " << e << endl
           << endl;
   }
   else // if message is a number (decrypting)
   {
      ZZ encrypted = to_ZZ(argv[1]);

      ZZ p = to_ZZ(argv[2]);
      ZZ q = to_ZZ(argv[3]);
      ZZ e = to_ZZ(argv[4]);

      ZZ n = p * q;
      ZZ t = (p - 1) * (q - 1);
      ZZ d = findInverse(e, t);

      ZZ m = modExp(encrypted, d, n);
      string message = toBase27(m);
      replaceAllAtSignsWithSpaces(message);

      cout << message << endl;

      // output verbose results to standard error to not interfere with test
      cerr << endl
           << "Encrypted      = " << encrypted << endl
           << "Message        = " << m << endl
           << "Text (base 27) = " << message << endl
           << endl
           << "p = " << p << endl
           << "q = " << q << endl
           << "n = " << n << endl
           << "t = " << t << endl
           << "e = " << e << endl
           << "d = " << d << endl
           << endl;
   }

   return 0;
}
