CXX := g++
CXXFLAGS := -std=c++11

all: compile test

compile: inventory.h inventory.cpp
	@$(CXX) $(CXXFLAGS) -c inventory.cpp
	@$(CXX) $(CXXFLAGS) -c p3.1.cpp
	@$(CXX) $(CXXFLAGS) -o p3.1 p3.1.o inventory.o
	
clean:
	@rm -rf p3.1.o p3.1 inventory.o

test:
	# test 1
	@echo 'test 1: general command test'
	@test -z "`./p3.1 < test/inventory.in > test/inventory.out.temp 2>&1 ; diff test/inventory.out test/inventory.out.temp; rm test/inventory.out.temp`"
	@echo 'passed'
	# test 2
	@echo 'test 2: test blank command'
	@test -z "`./p3.1 < test/blank.in | diff test/blank.out -`"
	@echo 'passed'
	# test 3
	@echo 'test 3: test batch file command'
	@test -z "`./p3.1 < test/batch.in | diff test/batch.out -`"
	@echo 'passed'
	# test 4
	@echo 'test 4: wrong command test'
	@test -z "`./p3.1 < test/wrong_command.in 2> test/wrong_command.out.temp ; diff test/wrong_command.out test/wrong_command.out.temp; rm test/wrong_command.out.temp`"
	@echo 'passed'

.PHONY: all compile test clean 
