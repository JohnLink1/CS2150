#John Link, jwl9vq@virignia.edu, 10/10/21, makefile
CXX=clang++ $(CXXFLAGS)

CXXFLAGS=-Wall

DEBUG=-g


OBJECTS = getWordInGrid.o primenumber.o timer.o timer_test.o
make: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
	@echo "Done"

getWordInGrid.o: getWordInGrid.cpp
	$(CXX) -c getWordInGrid.cpp

wordPuzzle.o: wordPuzzle.cpp
	$(CXX) -c wordPuzzle.cpp

primenumber.o: primenumber.cpp
	$(CXX) -c primenumber.cpp

timer.o: timer.cpp timer.h
	$(CXX) -c timer.cpp

timer_test.o: timer_test.cpp timer.h
	$(CXX) -c timer_test.cpp

.PHONY: clean

clean:
	rm -f *.o
