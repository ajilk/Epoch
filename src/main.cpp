#include <unistd.h>
#include <stdlib.h>
#include <fstream>
#include "Screen.h"
#include "Image.h"


int main(int argc, char **argv){
	Screen screen;
	int font, color;
	ofstream outfile;
	outfile.open("./date.sh");
	switch(argc){
		case 1: 
			font = 2;
			color = -1;
			outfile << "date +%H:%M:%S > date.txt";
			break;
		case 2: 
			font = stoi(argv[1]);
			color = -1;
			outfile << "date +%H:%M:%S > date.txt";
			break;
		case 3:
			font = stoi(argv[1]);
			color = stoi(argv[2]);
			outfile << "date +%H:%M:%S > date.txt";
			break;
		case 4:
			font = stoi(argv[1]);
			color = stoi(argv[2]);
			outfile << "date " << argv[3] << " > date.txt";
			break;
	}	
	outfile.close();


	// Open resorces
	string path = "../resources/numbers/" + to_string(font) +"/";
	Image digit[10];
	for(int i=0; i<10; i++)
		digit[i].set(path+to_string(i)+".txt");
	Image colon("../resources/colon.txt");
	Image dash("../resources/dash.txt");
	Image slash("../resources/slash.txt");

	ifstream infile;
	Coordinate prev(1,2);
	while(!screen.kbhit()){
		system("./date.sh");
		infile.open("date.txt");
		char ch;
		while(infile.get(ch)){
			switch(ch){
				case '0': digit[0].print(screen, prev, color);	break;
				case '1': digit[1].print(screen, prev, color); 	break;
				case '2': digit[2].print(screen, prev, color);	break;
				case '3': digit[3].print(screen, prev, color);	break;
				case '4': digit[4].print(screen, prev, color);	break;
				case '5': digit[5].print(screen, prev, color);	break;
				case '6': digit[6].print(screen, prev, color);	break;
				case '7': digit[7].print(screen, prev, color);	break;
				case '8': digit[8].print(screen, prev, color);	break;
				case '9': digit[9].print(screen, prev, color);	break;
				case ':': colon.print(screen, prev, color);	break;
				default: break;
			}
			prev.X +=10;
		}
		infile.close();
		prev.X = 2;
		prev.Y = 1;
	}
	return 0;
}

/*
	What is happenning?
		Instead of using the complicated chronos library, we are utilizing
		the bash shell. We are using the date command to get the current time.
		The output of date command is written to the text file called date.txt.
		Then the character is read one by one and displayed accordingly.
		Advantages is you get the power of the date command to display
		dates.
*/
