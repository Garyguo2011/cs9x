CXX := g++
CXXFLAGS := -std=c++11 -g -Wall

all: compile test

compile:
	@$(CXX) $(CXXFLAGS) -c lists.cpp
	@$(CXX) $(CXXFLAGS) -c destr.test.cpp
	@$(CXX) $(CXXFLAGS) -o destr_test lists.o destr.test.o

clean:
	@rm -rf destr_test lists.o destr.test.o

test:
	@test -z "`./destr_test < test/1.in | diff test/1.out -`"
	@echo 'test 1 passed'
	@test -z "`./destr_test < test/2.in | diff test/2.out -`"
	@echo 'test 2 passed'

.PHONY: all compile test clean
