OBJS	= Computer.o heap.o PriorityQueue.o Request.o simulator.o main.o
SOURCE	= Computer.cpp heap.cpp PriorityQueue.cpp Request.cpp simulator.cpp main.cpp
HEADER	= Computer.h heap.h HeapException.h PQException.h PriorityQueue.h Request.h simulator.h
OUT	= simulator.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Computer.o: Computer.cpp
	$(CC) $(FLAGS) Computer.cpp 

heap.o: heap.cpp
	$(CC) $(FLAGS) heap.cpp 

PriorityQueue.o: PriorityQueue.cpp
	$(CC) $(FLAGS) PriorityQueue.cpp 

Request.o: Request.cpp
	$(CC) $(FLAGS) Request.cpp 

simulator.o: simulator.cpp
	$(CC) $(FLAGS) simulator.cpp 

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 


clean:
	rm -f $(OBJS) $(OUT)