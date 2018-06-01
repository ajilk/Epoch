#include <unistd.h>
#include <stdlib.h>
#include "Screen.h"
#include "Image.h"

int main(int argc, char **argv){
	Screen screen;
	string path = "../resources/numbers/2/";
	Image digit[10];
	for(int i=0; i<10; i++)
		digit[i].set(path+to_string(i)+".txt");

	Coordinate previous(2, 3);
	srand(time(NULL));
	while(!screen.kbhit()){
		int num = rand() % 7 + 0;
		// if(num < 0 || num > 7) num = 1;
		digit[rand()%9+0].print(screen, previous, num);
		if(previous.X > screen.getColumns()-20){
			previous.X = 3;
			previous.Y += 10;
		}
		else if(previous.Y > screen.getRows())
			previous.Y = 2;
		else
			previous.X += 10;
	}
	return 0;
}

/*
	What is happenning?
		We are creating an array of images. which are digits from 0 to 9. 
		In the while loop we are choosing a random number with a random 
		color displaying it relatively to the last display digit while 
		user does not hit a key.
*/
