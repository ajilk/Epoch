OBJ			= time
CC			= g++
OBJECTS		= main.o Screen.o Pixel.o Color.o Image.o
LDFLAGS		= -lncurses
CXXFLAGS	= -std=c++11
WARNINGS	= -Wall

$(OBJ): $(OBJECTS)
	$(CC) -o $(OBJ) $(OBJECTS) $(CXXFLAGS) $(LDFLAGS) $(WARNINGS)

main.o: main.cpp Screen.h
	$(CC) -c main.cpp $(CXXFLAGS)
Screen.o: Screen.cpp Screen.h
	$(CC) -c Screen.cpp $(CXXFLAGS)
Pixel.o: Pixel.cpp Pixel.h
	$(CC) -c Pixel.cpp $(CXXFLAGS)
Color.o: Color.cpp Color.h
	$(CC) -c Color.cpp $(CXXFLAGS)
Image.o: Image.h Image.cpp Screen.h Pixel.h
	$(CC) -c Image.cpp $(CXXFLAGS)

.PHONY:
clean:
	rm -f $(OBJ) $(OBJECTS)

run:
	./$(OBJ)
