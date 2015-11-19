CXX := g++
CXXFLAGS := -std=c++11 -g -Wall

all: compile

compile:
	@$(CXX) $(CXXFLAGS) -c positions.cpp
	@$(CXX) $(CXXFLAGS) -c cat+mouse.cpp
	@$(CXX) $(CXXFLAGS) -o cat+mouse cat+mouse.o positions.o	

clean:
	@rm -f positions.o cat+mouse.o cat+mouse

test:
	@test -z "`./cat+mouse < test/test1.in | diff test/test1.out -`"
	@echo 'test 1 passed'
	@test -z "`./cat+mouse < test/test2.in | diff test/test2.out -`"
	@echo 'test 2 passed'
	@echo 'All test passed!'

.PHONY: all clean test
