/***********************************************************************
* Program:
*    Lab C_lab, ECEN 324 Learning C Lab
*    Brother Jones, ECEN 324
* Author:
*    David Lambertson
* Summary:
*    This was my first attempt at writing a C program. We were to take the
*    example Brother Jones gave us in C++ into C to get acquainted with
*    C programming.
************************************************************************/

#include <stdio.h>

#define PI 3.1415926

/***********************************************************************
* This program will go through simple C commands to display ints, floats
*  and pointers and a for loop.   
***********************************************************************/
main() {
   
   const char LETTER = 'A';
   printf("24\n");
   printf("%.5f\n", PI);
   printf("%c\n", LETTER);

   float payRate = 10.50;
   int hours = 40;

   printf("Users pay rate: $%.1f\n", payRate);
   printf(" Hours worked: %d\n", hours);
   printf("    Gross Pay: $%.0f\n", hours * payRate);

   int number;
   fprintf(stderr, "Enter number: ");
   scanf("%d", &number);
   printf("Twice %d is %d\n\n", number, number*2);

   /*********************************************************************/
   /*********************** Output an Integer ***************************/
   /*********************************************************************/

   int anInt = 99;
   float aFloat = 43.2;

   /* This prints an integer*/
   printf("Integer: %d ###\n", anInt);
   /* This prints the same integer with space for 10*/
   printf("Integer: %10d ###\n", anInt);
   /* This prints the same integer with space for 10 but left aligned*/
   printf("Integer: %-10d ###\n\n", anInt);


   /*********************************************************************/
   /************************* Output a Float ****************************/
   /*********************************************************************/

   /* This prints a float */
   printf("  Float: %.1f ###\n", aFloat);
   /* This prints a float with space for 10 left aligned*/
   printf("  Float: %-10.1f ###\n", aFloat);
   /* This prints a float with space for 10 and to the second decimal*/
   printf("  Float: %10.2f ###\n", aFloat);
   /* This prints a float to the third decimal*/
   printf("  Float: %.3f ###\n", aFloat);
   /* This prints a float with space for 10 to the third decimal*/
   printf("  Float: %10.3f ###\n", aFloat);
   /* This prints a float with space for 10 left aligned to the fourth decimal*/
   printf("  Float: %-10.4f ###\n\n", aFloat);

   /*********************************************************************/
   /*************** Create some code to output a table ******************/
   /*********************************************************************/
   printf("\tOct   Dec   Hex   Char\n");
   printf("\t----------------------\n");
   int i;
   for (i = 97; i < 123; i++) {
      printf("\t%3o   %-3d   %-3x   %1c\n", i,i,i,i);
   }
   printf("\n");



   /*********************************************************************
    *************** Now play with pointers to finish up *****************
    *********************************************************************/
   int p;
   int *p1;
   int *p2;
   
   p = 42;

   p1 = &p;
   p2 = p1;

   printf("*p1 == %d\n", *p1);
   printf("*p2 == %d\n", *p2);

   p = 53;
   p2 = &p;
   printf("*p1 == %d\n", *p1);
   printf("*p2 == %d\n", *p2);

   int p3 = 88;
   p1 = &p3;

   printf("*p1 == %d\n", *p1);
   printf("*p2 == %d\n", *p2);
   printf("Hope you got the point of this example!\n");

   return 0;
}
