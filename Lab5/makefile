#John Link, jwl9vq@virginia.edu, 10/04/2021, makefile
CXX=clang++ $(CXXFLAGS)
all: TreeCalc TreeCalcTest TreeNode make

TreeCalc: TreeCalc.cpp TreeCalc.h TreeNode.h
	$(CXX) -c TreeCalc.cpp

TreeCalcTest: TreeCalcTest.cpp TreeCalc.h TreeNode.h
	$(CXX) -c TreeCalcTest.cpp

TreeNode: TreeNode.cpp TreeNode.h
	$(CXX) -c TreeNode.cpp


OBJECTS = TreeCalc.o TreeNode.o TreeCalcTest.o
make: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
	@echo "Done"
