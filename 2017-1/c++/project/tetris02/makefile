CC = g++
TARGET = main
SOURCES = tetris.cpp \
pane.cpp \
boardpane.cpp \
infopane.cpp \
helppane.cpp \
statpane.cpp \
nextpane.cpp \
score.cpp \
block.cpp \
main.cpp
LDFLAGS = -lncursesw
all:
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)
clean:
	rm -rf *.o $(TARGET)
