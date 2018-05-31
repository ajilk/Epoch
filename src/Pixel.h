#ifndef PIXEL_H
#define PIXEL_H

#include "Screen.h"
#include "Color.h"
// #include <ncurses.h>

/*
	class: simple pixel, has color
*/
class Pixel{
private:
	Color color;
public:
	// Call the custom constructor passing the dynamically created Color
	Pixel() : Pixel(* new Color(COLOR_WHITE)) {}
	Pixel(Color color) : color(color){}

	void setColor(Color color) { this->color = color; }
	void put(int Y, int X, Screen& screen){ 
		attron(COLOR_PAIR(color.get())); 
		screen.putch(Y, X, '.');
		attroff(COLOR_PAIR(color.get()));
	}
};


#endif