CC = g++
TARGET = main
SOURCES = tetris.cpp \
pane.cpp \
boardpane.cpp \
infopane.cpp \
helppane.cpp \
statpane.cpp \
nextpane.cpp \
main.cpp
LDFLAGS = -lncurses
all:
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)
clean:
	rm -rf *.o $(TARGET)
