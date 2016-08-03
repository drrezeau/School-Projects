###############################################################
# Program:
#     Lesson 12, Graph
#     Brother Helfrich, CS265
# Author:
#     Derek Calkins and David Lambertson
# Summary:
#     This program will allow a user to take a maze file 
#     full of cordinates and use them to draw a maze. Then, using
#     a graph data type, solve the path from one end of the maze,
#     to another.
# Time and Work Load:
#     Together-time:8 hours; David: 50% Derek: 50%
###############################################################

##############################################################
# The main rule
##############################################################
a.out: lesson12.o graph.o maze.o
	g++ -g -o a.out lesson12.o graph.o maze.o
	tar -cf lesson12.tar *.h *.cpp makefile

##############################################################
# The individual components
#      lesson12.o     : the driver program
##############################################################
lesson12.o: graph.h vertex.h lesson12.cpp
	g++ -g -c lesson12.cpp 

graph.o: graph.h set.h vertex.h graph.cpp vector.h list.h queue.h
	g++ -g -c graph.cpp

maze.o: maze.cpp maze.h vertex.h graph.h
	g++ -g -c maze.cpp
