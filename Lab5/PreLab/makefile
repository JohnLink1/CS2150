#John Link, jwl9vq@virginia.edu, 10/04/2021, makefile
CXX=clang++ $(CXXFLAGS)

CXXFLAGS=-Wall

DEBUG=-g

OBJECTS = TreeCalc.o TreeNode.o TreeCalcTest.o
make: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
	@echo "Done"

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h
	$(CXX) -c TreeCalc.cpp

TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h
	$(CXX) -c TreeCalcTest.cpp

TreeNode.o: TreeNode.cpp TreeNode.h
	$(CXX) -c TreeNode.cpp

.PHONY: clean

clean:
	rm -f *.o
