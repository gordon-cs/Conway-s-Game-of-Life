# Builds and Tests the Conway's Game of Life simulation
#
# Author: Jake Colbert

# default target
all: project1

# compile the code into an executable called 'project1' using C++ 2011
project1:	main.cc board.cc board.h
	g++ -std=c++11 -o project1 main.cc board.cc

# test the code against an expected output file
test:
	./project1 < tests/test1.in > tests/project1.out
	diff tests/project1.out tests/test1.out
