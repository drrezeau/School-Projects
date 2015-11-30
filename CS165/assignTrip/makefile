a.out: date.o time.o driver.o leg.o
	g++ date.o time.o driver.o leg.o

date.o: date.cpp date.h time.h
	g++ -c date.cpp

time.o: time.cpp time.h
	g++ -c time.cpp

driver.o: driver.cpp date.h leg.h node.h
	g++ -c driver.cpp

leg.o: leg.h leg.cpp node.h date.h
	g++ -c leg.cpp 
