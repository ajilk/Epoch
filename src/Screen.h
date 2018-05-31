#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <string>
#include <stdlib.h>	//exit()

class Screen{
private:
	int rows;
	int columns;
public:
	Screen();
	int getRows() { return rows; }
	int getColumns() { return columns; }
	bool kbhit();
	void putch(int Y, int X, char ch);
	void clr();
	void rfresh();
	~Screen();
};

#endif
