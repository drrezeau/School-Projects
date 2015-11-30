###############################################################
# Program:
#     Lesson 00, Vector
#     Brother Helfrich, CS235
# Author:
#     David Lambertson
# Summary:
#     This program wil take the Vector.h file and use it to implement
#     the vector class using the functions I have created for it.
#     Using lesson00.cpp, it will show the functionality of vector.h
###############################################################

##############################################################
# The main rule
##############################################################
a.out: vector.h lesson00.o
	g++ -o a.out lesson00.o 
	tar -cf lesson00.tar vector.h lesson00.cpp makefile

##############################################################
# The individual components
#      lesson00.o     : the driver program
##############################################################
lesson00.o: vector.h lesson00.cpp
	g++ -c lesson00.cpp
