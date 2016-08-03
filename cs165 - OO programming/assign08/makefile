a.out: driver.o time.o date.o
	g++ driver.o time.o date.o

driver.o: driver.cpp time.h
	g++ -c driver.cpp

time.o: time.cpp time.h
	g++ -c time.cpp
date.o: date.cpp date.h
	g++ -c date.cpp