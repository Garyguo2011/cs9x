CXX := g++
CXXFLAGS := -std=c++11 -g -Wall

# all: compile test
all: compile

compile:
	@$(CXX) $(CXXFLAGS) -c animals.cpp
	@$(CXX) $(CXXFLAGS) -c cat+mouse.cpp
	@$(CXX) $(CXXFLAGS) -c park.cpp
	@$(CXX) $(CXXFLAGS) -c positions.cpp
	@$(CXX) $(CXXFLAGS) -o a.out animals.o cat+mouse.o park.o positions.o

clean:
	@rm -rf amoebas amoebamain.o amoebas.o

test:
	@test -z "`./amoebas | diff test/expect -`"
	@echo 'test passed'

.PHONY: all compile test clean
