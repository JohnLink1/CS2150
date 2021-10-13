#John Link, jwl9vq@virginia.edu, 10/04/2021, makefile

CXX=clang++ $(CXXFLAGS)

CXXFLAGS=-Wall

DEBUG=-g


OBJECTS = AVLNode.o AVLTree.o AVLPathTest.o
make: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
	@echo "Done"

AVLNode.o: AVLNode.cpp AVLNode.h
	$(CXX) -c AVLNode.cpp

AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h
	$(CXX) -c AVLTree.cpp

AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
	$(CXX) -c AVLPathTest.cpp

.PHONY: clean

clean:
	rm -f *.o

