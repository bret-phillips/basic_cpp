CXXFLAGS := -std=c++11 -g
CXX := g++
OBJECTS := main.o
PROGRAM := main
TARGETS := $(PROGRAM)

all: $(TARGETS)

$(PROGRAM): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGETS)
	rm -f *.o *~
