CXX_LINUX = g++
CXX_WINDOWS = x86_64-w64-mingw32-g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Iinclude -static-libgcc -static-libstdc++

SRC_DIR = src
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/TaskRepository.cpp $(SRC_DIR)/TaskService.cpp $(SRC_DIR)/TaskController.cpp $(SRC_DIR)/TaskView.cpp
DEMO_SOURCES = $(SRC_DIR)/test_demo.cpp $(SRC_DIR)/TaskRepository.cpp $(SRC_DIR)/TaskService.cpp $(SRC_DIR)/TaskController.cpp $(SRC_DIR)/TaskView.cpp

TARGET_LINUX = tareas_priorizadas
TARGET_WINDOWS = tareas_priorizadas.exe
DEMO_LINUX = demo
DEMO_WINDOWS = demo.exe

all: linux windows

linux: $(TARGET_LINUX) $(DEMO_LINUX)

windows: $(TARGET_WINDOWS) $(DEMO_WINDOWS)

$(TARGET_LINUX): $(SOURCES)
	$(CXX_LINUX) $(CXXFLAGS) -o $(TARGET_LINUX) $(SOURCES)

$(TARGET_WINDOWS): $(SOURCES)
	$(CXX_WINDOWS) $(CXXFLAGS) -o $(TARGET_WINDOWS) $(SOURCES)

$(DEMO_LINUX): $(DEMO_SOURCES)
	$(CXX_LINUX) $(CXXFLAGS) -o $(DEMO_LINUX) $(DEMO_SOURCES)

$(DEMO_WINDOWS): $(DEMO_SOURCES)
	$(CXX_WINDOWS) $(CXXFLAGS) -o $(DEMO_WINDOWS) $(DEMO_SOURCES)

clean:
	rm -f $(TARGET_LINUX) $(TARGET_WINDOWS) $(DEMO_LINUX) $(DEMO_WINDOWS)

run-linux: $(TARGET_LINUX)
	./$(TARGET_LINUX)

run-windows: $(TARGET_WINDOWS)
	wine ./$(TARGET_WINDOWS)

demo-linux: $(DEMO_LINUX)
	./$(DEMO_LINUX)

demo-windows: $(DEMO_WINDOWS)
	wine ./$(DEMO_WINDOWS)

.PHONY: all linux windows clean run-linux run-windows demo-linux demo-windows