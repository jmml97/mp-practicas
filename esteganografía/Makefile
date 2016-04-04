SRC = src
INC = include
OBJ = obj
BIN = bin

CXX = g++
CXXFLAGS =  -Wall -Wextra -pedantic -std=c++03 -g  -I$(INC)

# ************ All ***********************

all : ocultar revelar

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************

$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/imagenES.o $(SRC)/imagenES.cpp
$(OBJ)/codificar.o : $(SRC)/codificar.cpp $(INC)/imagenES.h $(INC)/codificar.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/codificar.o $(SRC)/codificar.cpp
$(OBJ)/ocultar.o : $(SRC)/ocultar.cpp $(INC)/imagenES.h $(INC)/codificar.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/ocultar.o $(SRC)/ocultar.cpp
$(OBJ)/revelar.o : $(SRC)/revelar.cpp $(INC)/imagenES.h $(INC)/codificar.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/revelar.o $(SRC)/revelar.cpp

ocultar: $(OBJ)/ocultar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o
	$(CXX) -o $(BIN)/ocultar $(OBJ)/ocultar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o
revelar: $(OBJ)/revelar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o
	$(CXX) -o $(BIN)/revelar $(OBJ)/revelar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o



# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
