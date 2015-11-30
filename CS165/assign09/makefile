a.out: driver.o checking.o savings.o loan.o
	g++ driver.o checking.o savings.o loan.o

driver.o: driver.cpp account.h checking.h savings.h loan.h
	g++ -c driver.cpp

checking.o: checking.cpp account.h checking.h 
	g++ -c checking.cpp

savings.o: savings.cpp account.h savings.h
	g++ -c savings.cpp

loan.o: loan.cpp account.h loan.h
	g++ -c loan.cpp
