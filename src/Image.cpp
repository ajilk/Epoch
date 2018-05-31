#include "Image.h"

/*
	Function: Constructor. Constructs an Image based on the passed path 
				to image
*/
Image::Image(string path){
	// Initialize the 8 pixel colors
	for(int i=0; i<8; i++)
		pixel[i].setColor(* new Color(i));

	// Copy file's content on to image vector
	char ch;
	ifstream infile;
	infile.open(path);
	while(infile.get(ch))
		image.push_back(ch);
	infile.close();
}


/*
	Function: 	prints image 
	@param:		screen 	- where image is displayed
				pos		- top left corner of the image's position
	@return:	void
*/
void Image::print(Screen &screen, Coordinate leftCorner){
	int y=0, x=0;
	int current = 0;	// Marks vector index
	int color = 0;		// Default color black
	while(current < image.size()){
		if(image[current] == '\n'){
			// Imagine a typewriter)
			x=0;	// Go all the way to the beginning
			y++;	// Go to the next line
		}
		else{
			x++;
			// Grab the color of the current pixel
			color = image[current] - '0';	
			pixel[color].put(screen, * new Coordinate(y+leftCorner.Y,x+leftCorner.X));
		}
		current++;
	}
}