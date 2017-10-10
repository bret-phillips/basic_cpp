CXXFLAGS := -std=c++11 -g
CXX := g++
OBJECTS := tester.o bubble_sort.o
PROGRAM := bubble_sort
TARGETS := $(PROGRAM)

all: $(TARGETS)

$(PROGRAM): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGETS)
	rm -f *.o *~
