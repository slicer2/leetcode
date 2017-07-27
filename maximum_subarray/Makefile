CXX = g++
CXXFLAGS = -g -std=c++0x -I ~/program/leetcode/c++/ -Wall
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
DEP = $(patsubst %.cpp, %.d, $(SRC))

.PHONY: all clean

all: $(OBJ)
	$(CXX) $(CXFLAGS) -o main $^

####   include dependency ####
include $(DEP)


####   pattern rules ####

%.d: %.cpp
	$(CXX) $(CXXFLAGS) -M $< > $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<


clean:
	-rm $(OBJ) $(DEP)
