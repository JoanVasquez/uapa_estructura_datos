# Makefile for Windows and Linux
CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iincludes
TARGET = office_network

# Detect operating system
ifeq ($(OS),Windows_NT)
    TARGET := $(TARGET).exe
    RM = del /Q
    MKDIR = mkdir
    SOURCES = src\main.cpp \
              src\entities\Office.cpp \
              src\repositories\OfficeNetworkRepository.cpp \
              src\services\OfficeNetworkService.cpp \
              src\controllers\OfficeNetworkController.cpp \
              src\views\OfficeNetworkView.cpp
    OBJ_DIR = obj
    OBJECTS = $(SOURCES:src\%.cpp=$(OBJ_DIR)\%.o)
    CREATE_DIR = if not exist $(subst /,\,$(1)) $(MKDIR) $(subst /,\,$(1))
else
    RM = rm -f
    MKDIR = mkdir -p
    SOURCES = src/main.cpp \
              src/entities/Office.cpp \
              src/repositories/OfficeNetworkRepository.cpp \
              src/services/OfficeNetworkService.cpp \
              src/controllers/OfficeNetworkController.cpp \
              src/views/OfficeNetworkView.cpp
    OBJ_DIR = obj
    OBJECTS = $(SOURCES:src/%.cpp=$(OBJ_DIR)/%.o)
    CREATE_DIR = $(MKDIR) $(1)
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Rule for Windows
$(OBJ_DIR)\%.o: src\%.cpp
	@$(call CREATE_DIR,$(@D))
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule for Linux
$(OBJ_DIR)/%.o: src/%.cpp
	@$(call CREATE_DIR,$(@D))
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(TARGET)
	$(RM) -r $(OBJ_DIR)

run: $(TARGET)
	./$(TARGET)

# For Windows
ifeq ($(OS),Windows_NT)
run: $(TARGET)
	.\$(TARGET)
endif

.PHONY: all clean run
