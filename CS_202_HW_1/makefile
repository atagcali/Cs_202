OBJS	= BinaryNode.o BinarySearchTree.o main.o
SOURCE	= BinaryNode.cpp BinarySearchTree.cpp main.cpp
HEADER	= BinaryNode.h BinarySearchTree.h
OUT	= 
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

BinaryNode.o BinaryNode.cpp
	$(CC) $(FLAGS) BinaryNode.cpp 

BinarySearchTree.o BinarySearchTree.cpp
	$(CC) $(FLAGS) BinarySearchTree.cpp 

main.o main.cpp
	$(CC) $(FLAGS) main.cpp 


clean
	rm -f $(OBJS) $(OUT)