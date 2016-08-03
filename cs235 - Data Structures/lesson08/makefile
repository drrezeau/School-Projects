###############################################################
# Program:
#     Lesson 08, Binary Search Tree
#     Brother Helfrich, CS265
# Author:
#     Derek Calkins and David Lambertson
# Summary:
#     This program allows a user to take an array of data
#     sort it using a Binary Search Tree and then send it back 
#     to the array.
# Time:
#     bst.h: 8 Hours sortBinary.h: 10 minutes.
#     David:60%   Derek:40%  
###############################################################

##############################################################
# The main rule
##############################################################
a.out: lesson08.o
	g++ -g -o a.out lesson08.o 
	tar -cf lesson08.tar *.h *.cpp makefile

##############################################################
# The individual components
#      lesson08.o     : the driver program
##############################################################
lesson08.o: bnode.h bst.h lesson08.cpp sortBinary.h
	g++ -g -c lesson08.cpp

