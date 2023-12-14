# Variables de compilación
CXX = g++
CXXFLAGS = -std=c++11 

# Directorios de origen
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

# Obtener la lista de archivos .cpp y .h
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
HEADERS = $(wildcard $(INC_DIR)/*.h)

# Obtener la lista de archivos objeto
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Nombre del ejecutable
TARGET = main

# Crear directorio obj si no existe
$(shell mkdir -p $(OBJ_DIR))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) ./main.cpp -I$(INC_DIR) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

entrega:
	zip -r 40_lab4.zip Makefile main.cpp ./src/*.cpp ./include/*.h ./obj

clean:
	rm -f $(TARGET) $(OBJECTS)

