# Main executable
a.out: time.o driver.o
	g++ time.o driver.o

time.o: time.cpp time.h
	g++ -c time.cpp

driver.o: driver.cpp time.h
	g++ -c driver.cpp

