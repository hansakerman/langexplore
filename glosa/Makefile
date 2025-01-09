# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17

# Target executable name
TARGET = glosa

# Source file
SRC = glosa.cpp

# Default target to compile and link in one step
all: $(TARGET)

# Rule to compile and link into an executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean target to remove the executable
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
