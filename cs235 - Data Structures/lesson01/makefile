###############################################################
# Program:
#     Lesson 01, SET
#     Brother Helfrich, CS235
# Author:
#     David Lambertson and Derek Calkins
# Summary:
#     this makefile takes our different files and makes a TAR and a.out.
#     The a.out file lets the user run the program and test the Set Class 
#     written by us. It has four tests and lets them play Go Fish using the 
#     goFish.cpp written by us also. The tar lets us submit our assignment.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: set.h lesson01.o goFish.o card.o
	g++ -g -o a.out lesson01.o goFish.o card.o
	tar -cf lesson01.tar *.h *.cpp makefile

##############################################################
# The individual components
#      lesson01.o     : the driver program
#      goFish.o       : the logic for the goFish game
#      card.o         : a single playing card
##############################################################
lesson01.o: set.h goFish.h lesson01.cpp
	g++ -g -c lesson01.cpp

goFish.o: set.h goFish.h goFish.cpp card.h
	g++ -g -c goFish.cpp

card.o: card.h card.cpp
	g++ -g -c card.cpp 
