###############################################################
# Program:
#     Lesson 07, Binary Tree
#     Brother Helfrich, CS265
# Author:
#     David Lambertson and Derek Calkins
# Summary:
#     this program allows users to make binary nodes which
#     they can link together to create a binary tree. 
# Time:
#     David:60%  Derek: 40%
###############################################################

##############################################################
# The main rule
##############################################################
a.out: lesson07.o huffman.o 
	g++ -g -o a.out lesson07.o huffman.o 
	tar -cf lesson07.tar *.h *.cpp makefile

##############################################################
# The individual components
#      lesson07.o     : the driver program
#      huffman.o      : the logic for the huffman code program
##############################################################
lesson07.o: bnode.h huffman.h lesson07.cpp
	g++ -g -c lesson07.cpp

huffman.o: bnode.h huffman.h vector.h huffman.cpp
	g++ -g -c huffman.cpp

