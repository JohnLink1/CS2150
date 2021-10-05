#John Link, jwl9vq@virginia.edu, 10/04/2021, makefile

CXX=clang++ $(CXXFLAGS)

CXXFLAGS=-Wall

DEBUG=-g


OBJECTS = BinaryNode.o BinarySearchTree.o BSTPathTest.o
make: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
	@echo "Done"

BinaryNode.o: BinaryNode.cpp BinaryNode.h
	$(CXX) -c BinaryNode.cpp

BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h
	$(CXX) -c BinarySearchTree.cpp

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
	$(CXX) -c BSTPathTest.cpp

.PHONY: clean

clean:
	rm -f *.o

