CXX := g++
CXXFLAGS := -std=c++11 -g

all: hw1

hw1.o: hw1.cpp
	@$(CXX) $(CXXFLAGS) -c hw1.cpp

hw1: hw1.o
	@$(CXX) $(CXXFLAGS) -o hw1 hw1.o

clean:
	@rm -rf hw1 hw1.o

check: hw1
	@test -z "`./hw1 < test.in.txt | diff test.out.txt -`"
	@echo 'Pass'

.PHONY: clean all check