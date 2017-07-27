CC = g++
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
DEP = $(patsubst %.cpp, %.d, $(SRC))

.PHONY: all clean

all: $(OBJ)
	$(CC) -o main $^

####   include dependency ####
include $(DEP)


####   pattern rules ####

%.d: %.cpp
	$(CC) -M $< > $@

%.o: %.cpp
	$(CC) -c -o $@ $<


clean:
	-rm $(OBJ) $(DEP)
