
CXX=clang++ $(CXXFLAGS)

target: TreeCalc.o TreeCalcTest.cpp TreeNode.cpp
	$(CXX) TreeCalc.o TreeCalcTest.cpp TreeNode.cpp -o target

TreeCalc.o: TreeCalc.cpp
	$(CXX) -c TreeCalc.cpp

TreeCalcTest.o: TreeCalcTest.cpp
	$(CXX) -c TreeCalcTest.cpp

TreeNode.o: TreeNode.cpp
	$(CXX) -c TreeNode.cpp

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h
TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h
TreeNode.o: TreeNode.cpp TreeNode.h

OBJECTS = TreeCalc.o TreeNode.o TreeCalcTest.o
make: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o make
	@echo "Done"
