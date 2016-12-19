CPP = g++
CPPFLAGS = -Wall -std=c++14 -pedantic

all:
	make test

test:
	$(CPP) $(CPPFLAGS) test.cpp -o test.out

memcheck:
	make test
	valgrind -v --tool=memcheck ./test.out

clean:
	(rm -f *.out)
