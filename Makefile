CXX = g++
CXXFLAGS = -g -O0 -Wall
TARGET = build/prog
SRC = main.cpp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf build
