###############################################################
# Program:
#     Lesson 02, STACK
#     Brother Helfrich, CS235
# Author:
#     Derek Calkins and David Lambertson
# Summary:
#     Using a stack impelemented by Derek, take an infix
#     equation and turn it into postfix, implemented by David.
# Time:
#     Total hours spent working on this assignment was an average of
#     8 hours. split 50% David and 50% Derek.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: stack.h lesson02.o infix.o 
	g++ -g -o a.out lesson02.o infix.o 
	tar -cf lesson02.tar *.h *.cpp makefile

##############################################################
# The individual components
#      lesson02.o     : the driver program
#      infix.o        : the logic for the infix --> postfix program
##############################################################
lesson02.o: stack.h infix.h lesson02.cpp
	g++ -g -c lesson02.cpp

infix.o: stack.h infix.h infix.cpp
	g++ -g -c infix.cpp

