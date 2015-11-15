CXX := g++
CXXFLAGS := -g -Wall

# all: compile test
all: compile

compile:
	g++ sltest.cpp sorted.lists.h

clean:
	@rm -rf a.out sltest.o sorted.lists.h.gch

test:
	@test -z "`./amoebas | diff test/expect -`"
	@echo 'test passed'

.PHONY: all compile test clean
