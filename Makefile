# Makefile

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS = -lstdc++

SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

TARGET = snake

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@