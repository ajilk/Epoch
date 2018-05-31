#ifndef COORDINATE_H
#define COORDINATE_H

struct Coordinate{ 
	int Y, X;
	Coordinate() : Coordinate(0,0) {}
	Coordinate(int Y, int X) : Y(Y), X(X) {}
	bool operator==(const Coordinate& p1){ 
		return ( this->Y == p1.Y && this->X == p1.X);
	}
	void operator=(const Coordinate& p1){ 
		this->Y = p1.Y; this->X = p1.X;
	}
};

#endif