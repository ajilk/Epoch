#include <unistd.h>
#include <cmath>
#include "Screen.h"
#include "Image.h"

int main(int argc, char **argv){
	Screen screen;
	Image image;
	image.print(screen, * new Coordinate(10,10));
	return 0;
}
