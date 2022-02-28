#include <iostream>
#include <string>
#include <fstream>
#include "image_menu.h"


void drawAsciiImage( ActionData& action_data ) {
	int row;
	int col;
	int chan;
	double str; //strength
	std::string newLine;
	for(row = 0; row < action_data.getOutputImage().getHeight(); row++) {
		newLine = "";
		for(col = 0; col < action_data.getOutputImage().getWidth(); col++) {
			str = 0;
			for(chan = 0; chan <= 2; chan++) {
				str = str + action_data.getOutputImage().getChannel(row, col, chan);
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
	
	action_data.getOS() << newLine << std::endl ;
    };
}

void writeUserImage( ActionData& action_data ) {
    std::string name = getString( action_data , "Output filename? ");
    std::ofstream fs;
    fs.open(name, std::fstream::binary);
    action_data.getOutputImage().writeStream(fs);
}

void copyImage( ActionData& action_data ) {
    action_data.getOutputImage() = action_data.getInputImage1();
}

void readUserImage1( ActionData& action_data ) {
    std::string name;
    std::ifstream fs;
    fs.open(name, std::fstream::in);
    if( !fs.good() ) {
        std::cout << name << " failed to open." << std::endl;
    }
    action_data.getInputImage1().readStream(fs);
}