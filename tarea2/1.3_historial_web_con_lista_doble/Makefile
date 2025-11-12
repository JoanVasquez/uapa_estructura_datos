# Detectar sistema operativo
ifeq ($(OS),Windows_NT)
    CXX = g++
    TARGET = historial_web.exe
    DEMO_TARGET = demo.exe
    RM = del /Q
    RUN_CMD = .\\$(TARGET)
else
    CXX = g++
    TARGET = historial_web
    DEMO_TARGET = demo
    RM = rm -f
    RUN_CMD = ./$(TARGET)
endif

CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Iinclude
SRC_DIR = src
INC_DIR = include
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/HistoryRepository.cpp $(SRC_DIR)/HistoryService.cpp $(SRC_DIR)/HistoryController.cpp $(SRC_DIR)/HistoryView.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	$(RM) $(TARGET) $(DEMO_TARGET)

run: $(TARGET)
	$(RUN_CMD)

demo: $(SRC_DIR)/test_demo.cpp $(SRC_DIR)/HistoryRepository.cpp $(SRC_DIR)/HistoryService.cpp $(SRC_DIR)/HistoryController.cpp $(SRC_DIR)/HistoryView.cpp
	$(CXX) $(CXXFLAGS) -o $(DEMO_TARGET) $(SRC_DIR)/test_demo.cpp $(SRC_DIR)/HistoryRepository.cpp $(SRC_DIR)/HistoryService.cpp $(SRC_DIR)/HistoryController.cpp $(SRC_DIR)/HistoryView.cpp

.PHONY: clean run demo