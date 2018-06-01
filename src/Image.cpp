#include "Image.h"

/*
	Function: 	Constructor. Constructs an Image based on the passed path 
				to image
	@param:		Path to image file
	@return:	-
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
	Funtion: 	sets image to the image from the given path
	@param:		path: path to image
	@return:	void
*/
void Image::set(std::string path){
	image.clear();
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
				lc		- top left corner of the image's position
				color	- use default color supplied from the file
							(or overwrite by passing color)
	@return:	void
*/
void Image::print(Screen &screen, Coordinate lc, int color){
	int y=0, x=0;
	int current = 0;	// Marks vector index
	int currColor;
	while(current < image.size()){
		if(image[current] == '\n'){
			// Imagine a typewriter)
			x=0;	// Go all the way to the beginning
			y++;	// Go to the next line
		}
		else{
			x++;
			if(color == -1) currColor = image[current] - '0';	
			// Take care of the empty spaces 
			else currColor = (image[current] - '0' > 0) ? color : 0;
			pixel[currColor].put(screen, * new Coordinate(y+lc.Y,x+lc.X));
		}
		current++;
	}
}