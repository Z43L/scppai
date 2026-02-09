# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.. -MMD -MP
TARGET = sc++

# Directories
SRC_DIR = .
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

# Source files
SRCS = ../main.cpp \
       lexer/lexer.cpp \
       lexer/token.cpp \
       jit/interprete.cpp \
       utils/core/lenguage.cpp \
       utils/core/operator.cpp

# Object files
OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(notdir $(SRCS)))
DEPS = $(OBJS:.o=.d)

# Default target
all: $(BUILD_DIR)/$(TARGET)

# Link the executable
$(BUILD_DIR)/$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# Compile source files to object files
$(OBJ_DIR)/main.o: ../main.cpp Makefile | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/lexer.o: lexer/lexer.cpp Makefile | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/token.o: lexer/token.cpp Makefile | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/interprete.o: jit/interprete.cpp Makefile | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/lenguage.o: utils/core/lenguage.cpp Makefile | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/operator.o: utils/core/operator.cpp Makefile | $(OBJ_DIR)
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

-include $(DEPS)

