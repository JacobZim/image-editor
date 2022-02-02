#include <iostream>
#include "image_menu.h"


void drawAsciiImage( std::istream& is, std::ostream& os, const Image& image ) {
	int row;
	int col;
	int chan;
	double str; //strength
	std::string newLine;
	(void) is;
	for(row = 0; row < image.getHeight(); row++) {
		newLine = "";
		for(col = 0; col < image.getWidth(); col++) {
			str = 0;
			for(chan = 0; chan <= 2; chan++) {
				str = str + image.getChannel(row, col, chan);
				};
			str = str / 765.0;
			if(str >= 1.0) {newLine.append("@");
			} else if(str >= 0.9) {newLine.append("#");
			} else if(str >= 0.8) {newLine.append("%");
			} else if(str >= 0.7) {newLine.append("*");
			} else if(str >= 0.6) {newLine.append("|");
			} else if(str >= 0.5) {newLine.append("+");
			} else if(str >= 0.4) {newLine.append(";");
			} else if(str >= 0.3) {newLine.append("~");
			} else if(str >= 0.2) {newLine.append("-");
			} else if(str >= 0.1) {newLine.append(".");
			} else if(str >= 0.0) {newLine.append(" ");
			}
		};
	
	os << newLine << std::endl ;
    };
}