#John Link, jwl9vq@virginia.edu, 10/04/2021, makefile

CXX=clang++ $(CXXFLAGS)
all: BinaryNode BinarySearchTree BSTPathTest make

BinaryNode: BinaryNode.cpp BinaryNode.h
	$(CXX) -c BinaryNode.cpp

BinarySearchTree: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h
	$(CXX) -c BinarySearchTree.cpp

BSTPathTest: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
	$(CXX) -c BSTPathTest.cpp

OBJECTS = BinaryNode.o BinarySearchTree.o BSTPathTest.o
make: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
	@echo "Done"


