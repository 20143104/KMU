HEADERS = vec.hpp mat.hpp operator.hpp
SOURCES = main.cpp
CC = g++
CFLAGS = -std=c++11 -lGL -lglut -lGLEW
EXECUTABLE = hello
RM = rm -rf

all: $(SOURCES) $(HEADERS)
	$(CC) -o $(EXECUTABLE) $(SOURCES) $(CFLAGS)

clean:
	$(RM) *.o $(EXECUTABLE)
