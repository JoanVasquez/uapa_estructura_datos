CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Iinclude
TARGET = tareas_priorizadas
SRC_DIR = src
INC_DIR = include
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/TaskRepository.cpp $(SRC_DIR)/TaskService.cpp $(SRC_DIR)/TaskController.cpp $(SRC_DIR)/TaskView.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET) demo

run: $(TARGET)
	./$(TARGET)

demo: $(SRC_DIR)/test_demo.cpp $(SRC_DIR)/TaskRepository.cpp $(SRC_DIR)/TaskService.cpp $(SRC_DIR)/TaskController.cpp $(SRC_DIR)/TaskView.cpp
	$(CXX) $(CXXFLAGS) -o demo $(SRC_DIR)/test_demo.cpp $(SRC_DIR)/TaskRepository.cpp $(SRC_DIR)/TaskService.cpp $(SRC_DIR)/TaskController.cpp $(SRC_DIR)/TaskView.cpp

.PHONY: clean run demo
