#John Link, jwl9vq@virignia.edu, 10/10/21, makefile
CXX=clang++ $(CXXFLAGS)

CXXFLAGS=-Wall

DEBUG=-g


OBJECTS = wordPuzzle.o timer.o hashTable.o
make: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
	@echo "Done"

wordPuzzle.o: wordPuzzle.cpp
	$(CXX) -c wordPuzzle.cpp

timer.o: timer.cpp timer.h
	$(CXX) -c timer.cpp

hashTable.o: hashTable.cpp hashTable.h
	$(CXX) -c hashTable.cpp

.PHONY: clean

clean:
	rm -f *.o
