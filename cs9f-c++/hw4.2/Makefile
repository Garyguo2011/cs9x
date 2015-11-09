CXX := g++
CXXFLAGS := -std=c++11 -g -Wall
all: compile test

compile:
	@$(CXX) $(CXXFLAGS) -c dll.cpp
	@$(CXX) $(CXXFLAGS) -c selection.cpp
	@$(CXX) $(CXXFLAGS) -o selection dll.o selection.o

clean:
	@rm -rf selection dll.o selection.o

test:
	@test -z "`./selection | diff test/expect -`"
	@echo 'test passed'

.PHONY: all compile test clean
