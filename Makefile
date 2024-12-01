HEADERS = data-extraction.hpp lcs-one.hpp lcs-two.hpp compute-lcs.hpp
TEST_SOURCES = ./tests/data-extraction-test.cpp ./tests/lcs-one-test.cpp ./tests/lcs-two-test.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
MAIN_OBJECTS = data-extraction.o lcs-one.o lcs-two.o compute-lcs.o main.o
TEST_TARGETS = $(TEST_SOURCES:.cpp=.out)
MAIN_TARGET = main_executable

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I.

.PHONY: all run-test main run-main clean

all: $(TEST_TARGETS) $(MAIN_TARGET)

$(TEST_TARGETS): %.out: %.o data-extraction.o lcs-one.o lcs-two.o compute-lcs.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(MAIN_TARGET): $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

./tests/%.o: ./tests/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run-test: $(TEST_TARGETS)
	for test in $(TEST_TARGETS); do ./$$test; done

main: $(MAIN_TARGET)

run-main: main
	./$(MAIN_TARGET)

clean:
	rm -f $(TEST_OBJECTS) $(TEST_TARGETS) $(MAIN_OBJECTS) $(MAIN_TARGET)