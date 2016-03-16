AR = ar
CXX = g++
CXXFLAGS = -Wall -g -I $(INC)
LDFGLAGS = -L.
LDLIBS = -lformas

INC = includes
SRC = src
OBJ = obj
LIB = lib
BIN = bin

all : central area

$(OBJ)/punto.o : $(INC)/punto.h $(SRC)/punto.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/punto.o $(SRC)/punto.cpp
$(OBJ)/circulo.o : $(INC)/punto.h $(INC)/circulo.h $(SRC)/circulo.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/circulo.o $(SRC)/circulo.cpp
$(OBJ)/central.o : $(INC)/punto.h $(INC)/circulo.h $(SRC)/central.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/central.o $(SRC)/central.cpp
central : $(OBJ)/central.o libformas.a
	$(CXX) -o $(BIN)/central $(OBJ)/central.o $(LDFGLAGS) $(LDLIBS)

area : $(OBJ)/area.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/area $(OBJ)/area.o $(LDFGLAGS) $(LDLIBS)

$(OBJ)/area.o : $(INC)/punto.h $(INC)/circulo.h $(SRC)/area.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/area.o $(SRC)/area.cpp

$(LIB)/libformas.a : $(OBJ)/punto.o $(OBJ)/circulo.o
	$(AR) rvs $(LIB)/libformas.a $(OBJ)/punto.o $(OBJ)/circulo.o

clean :
	echo "Limpiando..."
	rm $(OBJ)/*.o $(LIB)/*.a

mrpropper : clean
	rm $(BIN)/central
