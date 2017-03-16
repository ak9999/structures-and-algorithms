CPP = c++
CPPFLAGS = -Wall -std=c++14 -pedantic
EXECUTABLE_DIR = .

# Including
INCLUDES = -I../Algorithms/ -I../DataStructures/

# Libraries
LIBS = -L/usr/lib -L/usr/local/lib

.cpp.o:
	$(CPP) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

# Objects
binary_search_obj = binary_search.o

all: binary_search

binary_search: $(binary_search_obj)
	$(CPP) $(CPPFLAGS) -o $(EXECUTABLE_DIR)/$@ $(binary_search_obj) $(INCLUDES) \
		$(LIBS)

clean:
	(rm -f *.o)
	(rm -f binary_search)
