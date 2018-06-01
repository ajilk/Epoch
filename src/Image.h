#ifndef DIGIT_H
#define DIGIT_H

#include <string>
#include <vector>
#include <fstream>
#include "Pixel.h"

using namespace std;
/*
	Class: Image refers to a vector of characters
*/
class Image{
private:
	vector<char> image;
	Pixel pixel[8];		// Represents the 8 available colors
public:
	Image() : Image("../resources/default.txt") {};
	Image(std::string path);
	vector<char> get() { return image; }
	void set(std::string path);
	void print(Screen &screen, Coordinate pos, int color = -1);
};

#endif // DIGIT_H