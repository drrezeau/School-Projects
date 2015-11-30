###############################################################
# Program:
#     Lesson 04, DEQUE
#     Brother Helfrich, CS235
# Author:
#     Derek Calkins and David Lambertson
# Summary:
#     This program will allow a user to use the deque
#     to create a line and be able to insert at front or back
#     and remove from front or back and can access front or back.
# Time:
#     total of 8.5 hours. David 2.5 and Derek 6 
# Work Load:
#     Derek: 50% and David: 50%
###############################################################

##############################################################
# The main rule
##############################################################
a.out: deque.h lesson04.o nowServing.o
	g++ -o a.out lesson04.o nowServing.o
	tar -cf lesson04.tar *.h *.cpp makefile

##############################################################
# The individual components
#      lesson04.o     : the driver program
#      nowServing.o   : the logic for the now serving program
##############################################################
lesson04.o: deque.h lesson04.cpp
	g++ -c lesson04.cpp

nowServing.o: nowServing.h nowServing.cpp deque.h
	g++ -c nowServing.cpp
