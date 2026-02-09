# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I..
TARGET = sc++

# Directories
SRC_DIR = .
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

# Source files
SRCS = main.cpp \
	   src/lexer/lexer.cpp \
       src/lexer/token.cpp \
       src/jit/interprete.cpp \
       src/utils/core/lenguage.cpp \
       src/utils/core/operator.cpp
# Object files
OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(notdir $(SRCS)))

# Default target
all: $(BUILD_DIR)/$(TARGET)

# Link the executable
$(BUILD_DIR)/$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# Compile source files to object files
$(OBJ_DIR)/main.o: main.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/lexer.o: src/lexer/lexer.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/token.o: src/lexer/token.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/interprete.o: src/jit/interprete.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/lenguage.o: src/utils/core/lenguage.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/operator.o: src/utils/core/operator.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create directories if they don't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Run the program
run: all
	./$(BUILD_DIR)/$(TARGET)

# Phony targets
.PHONY: all clean run

