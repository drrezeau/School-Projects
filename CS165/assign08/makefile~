a.out: driver.o time.o
	g++ driver.o time.o

driver.o: driver.cpp time.h
	g++ -c driver.cpp

time.o: time.cpp time.h
	g++ -c time.cpp