# Builds and Tests the Conway's Game of Life simulation
#
# Author: Jake Colbert

# default target
all: project1

# compile the code into an executable called 'project1' using C++ 2011
project1:	main.cc board.cc board.h
	g++ -std=c++11 -o project1 main.cc board.cc

# test the code against an expected output file
# this test should grow into a spaceship and end with blinkers
sample_test:
	./project1 < tests/test1.in > tests/project1.out
	diff tests/project1.out tests/test1.out > sample.diff
	wc -l sample.diff
	
# this test is the same as the one above but tranposed
sample_test_transposed:
	./project1 < tests/test2.in > tests/project1.out
	diff tests/project1.out tests/test2.out > sample_transposed.diff
	wc -l sample_transposed.diff
	
# test the code against an expected output file
# this test should simulate a glider gun
glider_test:
	./project1 < tests/glider.in > tests/project1.out
	diff tests/project1.out tests/glider.out > glider.diff
	wc -l glider.diff
