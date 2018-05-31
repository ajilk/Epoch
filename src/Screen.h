#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <string>
#include <stdlib.h>	//exit()
#include "Coordinate.h"

class Screen{
private:
	int rows;
	int columns;
public:
	Screen();
	int getRows() { return rows; }
	int getColumns() { return columns; }
	bool kbhit();
	void putch(Coordinate pos, char ch);
	void clr();
	void rfresh();
	~Screen();
};

#endif
