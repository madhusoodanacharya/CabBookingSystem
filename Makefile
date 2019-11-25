#makefile

CC = g++
TARGET = main

all:
	$(CC) main.cpp backend.cpp frontend.cpp -o $(TARGET)

clean:
	rm $(TARGET)
