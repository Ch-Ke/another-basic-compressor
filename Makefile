# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall
INCLUDES = -I./include
SRC = src/compressor.cpp
BUILD_DIR = build

# Output directories and files
TEST_SRC = tests/test.cpp
MAIN_SRC = src/main.cpp
TEST_OUTPUT = $(BUILD_DIR)/test
MAIN_OUTPUT = $(BUILD_DIR)/main

# Targets
.PHONY: all main test runmain runtest clean $(BUILD_DIR)

# Default target (compiles both main and test, doesn't run them)
all: test main

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Build and run test
test: $(BUILD_DIR) $(TEST_SRC) $(SRC)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) $(SRC) $(INCLUDES) -o $(TEST_OUTPUT)
	./$(TEST_OUTPUT)

# Build and run main
main: $(BUILD_DIR) $(MAIN_SRC) $(SRC)
	$(CXX) $(CXXFLAGS) $(MAIN_SRC) $(SRC) $(INCLUDES) -o $(MAIN_OUTPUT)
	./$(MAIN_OUTPUT)

# Run the main binary (without recompiling)
runmain: $(MAIN_OUTPUT)
	./$(MAIN_OUTPUT)

# Run the test binary (without recompiling)
runtest: $(TEST_OUTPUT)
	./$(TEST_OUTPUT)

# Clean the build directory
clean:
	rm -rf $(BUILD_DIR)/*

