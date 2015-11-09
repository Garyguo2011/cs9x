CXX := g++
CXXFLAGS := -std=c++11

all: compile test

compile:
	@$(CXX) $(CXXFLAGS) -c board.cpp
	@$(CXX) $(CXXFLAGS) -o board board.o
	
clean:
	@rm -rf board board.o

test:
	@test -z "`./board | diff test/expect -`"
	@echo 'test passed'

.PHONY: all compile test clean 
