OBJ			= time
CC			= g++
OBJECTS		= main.o Screen.o Pixel.o Color.o
LDFLAGS		= -lncurses
CXXFLAGS	= -std=c++11
WARNINGS	= -Wall

$(OBJ): $(OBJECTS)
	$(CC) -o $(OBJ) $(OBJECTS) $(CXXFLAGS) $(LDFLAGS) $(WARNINGS)

main.o: main.cpp Screen.h
	$(CC) -c main.cpp -std=c++11
Screen.o: Screen.cpp Screen.h
	$(CC) -c Screen.cpp
Pixel.o: Pixel.cpp Pixel.h
	$(CC) -c Pixel.cpp -std=c++11
Color.o: Color.cpp Color.h
	$(CC) -c Color.cpp

.PHONY:
clean:
	rm -f $(OBJ) $(OBJECTS)

run:
	./$(OBJ)
