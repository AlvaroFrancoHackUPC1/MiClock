OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

miclock.exe: main.o alarm.o
	g++ -o miclock.exe main.o alarm.o

main.o: src/main.cc include/alarm.hh
	g++ -c $(OPCIONS) src/main.cc -o main.o

alarm.o: src/alarm.cc include/alarm.hh
	g++ -c $(OPCIONS) src/alarm.cc -o alarm.o

clean:
	rm -f *.o
	rm -f *.exe

practica.tar: src/alarm.cc include/alarm.hh src/main.cc Makefile
	tar -cvf practica.tar src/alarm.cc include/alarm.hh src/main.cc Makefile