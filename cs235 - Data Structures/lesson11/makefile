###############################################################
# Program:
#     Lesson 11, Hash
#     Brother Helfrich, CS265
# Author:
#     David Lambertson and Derek Calkins
# Summary:
#     This program uses a hash abstract data type to spell check 
#     words in a given file using the dictionary
###############################################################

##############################################################
# The main rule
##############################################################
a.out: lesson11.o spellCheck.o
	g++ -g -o a.out lesson11.o spellCheck.o
	tar -cf lesson11.tar *.h *.cpp makefile

##############################################################
# The individual components
#      lesson11.o     : the driver program
#      spellCheck.o   : the spell-check program and driver
##############################################################
lesson11.o: hash.h lesson11.cpp list.h node.h
	g++ -g -c lesson11.cpp 

spellCheck.o: hash.h spellCheck.h spellCheck.cpp
	g++ -g -c spellCheck.cpp

