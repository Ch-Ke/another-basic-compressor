
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall
INCLUDES = -I./include
SRC_DIR = src
BUILD_DIR = build

# Output directories and files
TEST_SRC = tests/test.cpp
MAIN_SRC = src/main.cpp
TEST_OUTPUT = $(BUILD_DIR)/test
MAIN_OUTPUT = $(BUILD_DIR)/main

# Collect all source files in the src directory except main.cpp
SRC_FILES = $(filter-out $(SRC_DIR)/main.cpp, $(wildcard $(SRC_DIR)/*.cpp))
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Targets
.PHONY: all main test runmain runtest clean $(BUILD_DIR)

# Default target (compiles both main and test, doesn't run them)
all: test main

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Build and run test
test: $(BUILD_DIR) $(OBJ_FILES) $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) $(TEST_SRC) $(INCLUDES) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)

# Build main
main: $(BUILD_DIR) $(OBJ_FILES) $(BUILD_DIR)/main.o
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) $(BUILD_DIR)/main.o $(INCLUDES) -o $(MAIN_OUTPUT)

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Run the main binary (without recompiling)
runmain: $(MAIN_OUTPUT)
	./$(MAIN_OUTPUT) input.txt output.txt enc

# Run the test binary (without recompiling)
runtest: $(TEST_OUTPUT)
	./$(TEST_OUTPUT)

# Clean the build directory
clean:
	rm -rf $(BUILD_DIR)

