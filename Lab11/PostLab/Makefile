# Makefile for CS 2150 pre-lab 10
# This Makefile shows how to link assembly with C/C++
#John Link, jwl9vq@virginia.edu, 11/15/21, makefile

# Defines the C++ compiler we'll be using
CXX = clang++

# Defines the flags we'll be passing to the C++ compiler
CXXFLAGS = -Wall -g

# All of the .o files for our program
OBJECTS = puzzle.o

# Compile our files into a.out
a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	doxygen Doxyfile
# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	-rm -f *.o *~
