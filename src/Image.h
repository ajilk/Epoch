#ifndef DIGIT_H
#define DIGIT_H

#include <string>
#include <vector>
#include <fstream>
#include "Pixel.h"

using namespace std;
/*
	Class: Image refers an array of vectors that hold characters
*/
class Image{
private:
	// int WIDTH;
	vector<char> image;
	Pixel pixel[8];		// Represents 8 available colors
public:
	Image() : Image("../resources/default.txt") {};
	Image(string path);
	vector<char> get() { return image; }
	void print(Screen &screen, Coordinate pos);
};

#endif // DIGIT_H