#include <unistd.h>
#include <cmath>
#include "Screen.h"
#include "Pixel.h"

int main(){
	Screen screen;
	// Pixel already includes Color.h
	int i = 1;
	char ch;
	while (i < 8 && !(screen.kbhit())){
		screen.clr();
		Pixel pixel(* new Color(i));
		for(int i=1; i<100; i++){
			for(int j=2; j<200; j++){
				pixel.put(i, j, screen);
			}
		}
		if (i == 7) i = 1;
		else i++;
		screen.rfresh();
		usleep(500000);
	}
	return 0;
}


/*
What is happening?
	Screen is created
	Pixel is created
		Pixel takes color as argument if not specified it uses default
		color white. put method puts the pixel on the specified 
		(Y, X) and screen
	What is color?
		Color is just wrapper class that creates pairs for each color
		sets backgroung and foreground. Has one private member and
		that represents color value, which is the true color simplified	

		This should not be a class, will be simpler if it was not. 
		But it is better this way in the future.


	We can have one pixel for each color. We can put the pixel anywhere 
	we want any times we want.
*/