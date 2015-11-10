CXX := g++
CXXFLAGS := -std=c++11 -g -Wall

# all: compile test
all: compile test

compile:
	@$(CXX) $(CXXFLAGS) -c amoebas.cpp
	@$(CXX) $(CXXFLAGS) -c amoebamain.cpp
	@$(CXX) $(CXXFLAGS) -o amoebas amoebas.o amoebamain.o

clean:
	@rm -rf amoebas amoebamain.o amoebas.o

test:
	@test -z "`./amoebas | diff test/expect -`"
	@echo 'test passed'

.PHONY: all compile test clean
