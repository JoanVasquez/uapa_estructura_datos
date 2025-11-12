# Detectar sistema operativo
ifeq ($(OS),Windows_NT)
    CXX = g++
    TARGET = tareas_priorizadas.exe
    DEMO_TARGET = demo.exe
    RM = del /Q
    RUN_CMD = .\\$(TARGET)
else
    CXX = g++
    TARGET = tareas_priorizadas
    DEMO_TARGET = demo
    RM = rm -f
    RUN_CMD = ./$(TARGET)
endif

CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Iinclude
SRC_DIR = src
INC_DIR = include
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/TaskRepository.cpp $(SRC_DIR)/TaskService.cpp $(SRC_DIR)/TaskController.cpp $(SRC_DIR)/TaskView.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	$(RM) $(TARGET) $(DEMO_TARGET)

run: $(TARGET)
	$(RUN_CMD)

demo: $(SRC_DIR)/test_demo.cpp $(SRC_DIR)/TaskRepository.cpp $(SRC_DIR)/TaskService.cpp $(SRC_DIR)/TaskController.cpp $(SRC_DIR)/TaskView.cpp
	$(CXX) $(CXXFLAGS) -o $(DEMO_TARGET) $(SRC_DIR)/test_demo.cpp $(SRC_DIR)/TaskRepository.cpp $(SRC_DIR)/TaskService.cpp $(SRC_DIR)/TaskController.cpp $(SRC_DIR)/TaskView.cpp

.PHONY: clean run demo