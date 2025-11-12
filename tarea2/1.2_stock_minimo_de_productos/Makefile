CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Iinclude
TARGET = stock_minimo
SRC_DIR = src
INC_DIR = include
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/ProductRepository.cpp $(SRC_DIR)/ProductService.cpp $(SRC_DIR)/ProductController.cpp $(SRC_DIR)/ProductView.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET) demo

run: $(TARGET)
	./$(TARGET)

demo: $(SRC_DIR)/test_demo.cpp $(SRC_DIR)/ProductRepository.cpp $(SRC_DIR)/ProductService.cpp $(SRC_DIR)/ProductController.cpp $(SRC_DIR)/ProductView.cpp
	$(CXX) $(CXXFLAGS) -o demo $(SRC_DIR)/test_demo.cpp $(SRC_DIR)/ProductRepository.cpp $(SRC_DIR)/ProductService.cpp $(SRC_DIR)/ProductController.cpp $(SRC_DIR)/ProductView.cpp

.PHONY: clean run demo