#COMPILER VERSION
CC = g++ 
#COMPILER FLAGS
CCFLAGS = -std=c++11 -Iinc -W -pedantic
#MAKEFILE OPTIONS
APP_NAME = projekt
EX = .cpp
SRC = src/
OBJ = obj/
INC = inc/

#Creating executable program

start: $(OBJ)main.o $(INC)stack.hpp $(INC)linkedList.hh $(INC)fileFunctions.hh $(INC)table.hh $(INC)queue.hh
	$(CC) $(OBJ)main.o -o $(APP_NAME)

obj/main.o: $(SRC)main$(EX)
	$(CC) $(CCFLAGS) -c -o $(OBJ)main.o $(SRC)main$(EX)

#Cleaning all .o stuff
clean: 
	rm $(OBJ)*.o $(APP_NAME)