# Compiler settings
CXX = g++
CXXFLAGS = -Wall -std=c++17
SRC_DIR = src
BUILD_DIR = build
TARGET = Lox

# Find all .cpp files in the src directory and its subdirectories
SOURCES = $(shell find $(SRC_DIR) -type f -name '*.cpp')
# Replace src directory with build directory and change file extension to .o
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Default target
all: $(TARGET)

# Link the application
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

text:
	./$(TARGET) test.lox
