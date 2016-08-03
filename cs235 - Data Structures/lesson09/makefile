###############################################################
# Program:
#     Lesson 09, Map
#     Brother Helfrich, CS265
# Author:
#     David Lambertson and Derek Calkins
# Summary:
#     This program allows users to create Maps and use them to
#     save keys with values and access those values later through 
#     the square bracket operator. 
# Time:
#     David: 50% & Derek 50%
###############################################################

##############################################################
# The main rule
##############################################################
a.out: lesson09.o wordCount.o
	g++ -g -o a.out lesson09.o wordCount.o 
	tar -cf lesson09.tar *.h *.cpp makefile

##############################################################
# The individual components
#      lesson09.o     : the driver program
#      wordCount.o    : the wordCount() function
##############################################################
lesson09.o: bnode.h bst.h pair.h map.h lesson09.cpp
	g++ -g -c lesson09.cpp

wordCount.o: map.h wordCount.h wordCount.cpp bnode.h bst.h
	g++ -g -c wordCount.cpp 
