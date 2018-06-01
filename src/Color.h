#ifndef COLOR_H
#define COLOR_H

#include <ncurses.h>
/*
	class: specifies color, generates identity pairs
		(basically houses the pairs)
*/
class Color{
private:
	int color;
public:
	Color() : color(COLOR_WHITE){ init(); }
	Color(int color) : color(color){ init(); }
	int get() { return color; }
	void init();
};

#endif // COLOR_H