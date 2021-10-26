#John Link, jwl9vq@virignia.edu, 10/10/21, makefile
CXX=clang++ $(CXXFLAGS)

CXXFLAGS=-Wall

DEBUG=-g


OBJECTS = counter.o timer.o
make: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
	@echo "Done"

counter.o: counter.cpp timer.h
	$(CXX) -c counter.cpp

timer.o: timer.cpp timer.h
	$(CXX) -c timer.cpp

.PHONY: clean

clean:
	rm -f *.o
