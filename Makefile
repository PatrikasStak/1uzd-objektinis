CXX := g++
CXXFLAGS := -O2 -std=c++14 -Wall -Wextra -pedantic

SRC := main.cpp func.cpp
OBJ := $(SRC:.cpp=.o)
BIN := main

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(BIN)

.PHONY: all clean
