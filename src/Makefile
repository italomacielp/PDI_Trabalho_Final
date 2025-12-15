CXX = g++
CXXFLAGS = -std=c++17 `pkg-config --cflags opencv4`
LDFLAGS = `pkg-config --libs opencv4`

SRC = $(wildcard *.cpp)

all:
	$(CXX) $(SRC) -o crosswalk $(CXXFLAGS) $(LDFLAGS)

clean:
	rm -f crosswalk

