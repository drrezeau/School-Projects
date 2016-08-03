###############################################################
# Program:
#     Lesson 03, QUEUE
#     Brother Helfrich, CS235
# Author:
#     Derek Calkins and David Lambertson
# Summary:
#     this program should allow a user to deal with stocks using a Queue class
#     that we created. David created the queue.h file and Derek did the stock.cpp
#     and stock.h. We were not able to get stocks working fully. 
# Time:
#     Total time: 9 hours.
#     Work split: Derek:40%  & David: 60%
###############################################################

##############################################################
# The main rule
##############################################################
a.out: queue.h lesson03.o dollars.o stock.o
	g++ -o a.out lesson03.o dollars.o stock.o
	tar -cf lesson03.tar *.h *.cpp makefile

dollarsTest: dollars.o dollarsTest.cpp
	g++ -o dollarsTest dollars.o dollarsTest.cpp

##############################################################
# The individual components
#      lesson03.o     : the driver program
#      dollars.o      : the Dollars class
#      stock.o        : the logic for the stock program
##############################################################
lesson03.o: queue.h lesson03.cpp
	g++ -c lesson03.cpp

dollars.o: dollars.h dollars.cpp
	g++ -c dollars.cpp

stock.o: stock.h stock.cpp queue.h
	g++ -c stock.cpp
