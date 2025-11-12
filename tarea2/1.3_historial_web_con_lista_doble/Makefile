CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Iinclude
TARGET = historial_web
SRC_DIR = src
INC_DIR = include
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/HistoryRepository.cpp $(SRC_DIR)/HistoryService.cpp $(SRC_DIR)/HistoryController.cpp $(SRC_DIR)/HistoryView.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET) demo

run: $(TARGET)
	./$(TARGET)

demo: $(SRC_DIR)/test_demo.cpp $(SRC_DIR)/HistoryRepository.cpp $(SRC_DIR)/HistoryService.cpp $(SRC_DIR)/HistoryController.cpp $(SRC_DIR)/HistoryView.cpp
	$(CXX) $(CXXFLAGS) -o demo $(SRC_DIR)/test_demo.cpp $(SRC_DIR)/HistoryRepository.cpp $(SRC_DIR)/HistoryService.cpp $(SRC_DIR)/HistoryController.cpp $(SRC_DIR)/HistoryView.cpp

.PHONY: clean run demo