###############################################################
# Program:
#     Lesson 06, LIST
#     Brother Helfrich, CS235
# Author:
#     David Lambertson and Derek Calkins
# Summary:
#     Created a List class to be able to display Nodes
#     to allow for constant time of inserting and removing
#     also made a whole number class to display a large number
#     such as a fibonacci number.
# Time:
#     20 hours total, 10 Derek, 10 David
# Amount of work:
#                    45% Derek, 55% David 
###############################################################

##############################################################
# The main rule
##############################################################
a.out: list.h lesson06.o fibonacci.o
	g++ -g -o a.out lesson06.o fibonacci.o
	tar -cf lesson06.tar *.h *.cpp makefile

##############################################################
# The individual components
#      lesson06.o     : the driver program
#      fibonacci.o    : the logic for the fibonacci-generating function
#      <anything else?>
##############################################################
lesson06.o: list.h lesson06.cpp
	g++ -g -c lesson06.cpp

fibonacci.o: fibonacci.h fibonacci.cpp list.h
	g++ -g -c fibonacci.cpp

