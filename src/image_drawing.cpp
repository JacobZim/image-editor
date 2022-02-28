#include <iostream>
#include "image_menu.h"
#include <string>



void diagonalQuadPattern( ActionData& action_data ) {
    action_data.getInputImage1().setMaxColorValue(255);
	int height;
	int width;
	int tophalf;
	
	int row;
	int col;
	
	height = getInteger( action_data, "Image height? ");
	width = getInteger( action_data, "Image width? ");
	action_data.getInputImage1().setHeight(height);
	action_data.getInputImage1().setWidth(width);
	
	tophalf = (action_data.getInputImage1().getHeight() / 2) ;
	
	// top half for red, bottom half for red
	for(row = 0; row < tophalf; row++){
		for(col = 0; col <= action_data.getInputImage1().getWidth(); col++){
			action_data.getInputImage1().setChannel(row, col, 0, 0);
		}};
	for(row = tophalf; row <= action_data.getInputImage1().getHeight(); row++) {
		for(col = 0; col < action_data.getInputImage1().getWidth(); col++) {
			action_data.getInputImage1().setChannel(row, col, 0, 255);
		}};
	
	// left half for blue, right half for blue
	for(row = 0; row <= action_data.getInputImage1().getHeight(); row++){
		for(col = 0; col < action_data.getInputImage1().getWidth() / 2; col++){
			action_data.getInputImage1().setChannel(row, col, 2, 0);
		}};

	for(row = 0; row <= action_data.getInputImage1().getHeight(); row++) {
		for(col = action_data.getInputImage1().getWidth() / 2; col <= action_data.getInputImage1().getWidth(); col++) {
			action_data.getInputImage1().setChannel(row, col, 2, 255);
		}};
	
	// function for designating green based off position
	for(row = 0; row <= action_data.getInputImage1().getHeight(); row++){
		for(col = 0; col <= action_data.getInputImage1().getWidth(); col++){
			action_data.getInputImage1().setChannel(row, col, 1, ((2*row) + (2*col)) % 256);
		}};
	return;
}

void stripedDiagonalPattern( ActionData& action_data ) {
    /*(void) action_data.getIS();
    (void) action_data.getOS();
    (void) action_data.getInputImage1();*/
    int height = 0, width = 0;
    height = getInteger( action_data, "Image height? ");
    width = getInteger( action_data, "Image width? ");
    
    
    action_data.getInputImage1().setHeight(height);
    action_data.getInputImage1().setWidth(width);
    
    int mcv = (height + width) / 3;
    if (mcv > 255) {
        mcv = 255;
    }
    
    action_data.getInputImage1().setMaxColorValue(mcv);
    
    int row, col;
    //define red channel values
    
    for ( row = 0; row < height / 2; row++) {
        for( col = 0; col < width; col++) {
            action_data.getInputImage1().setPixel(row, col, 0, -1, -1);
        }
    } 
    for( row = height / 2; row < height; row++) {
        for( col = 0; col < width; col++ ) {
            if( (row % 3) == 0 ) {
                action_data.getInputImage1().setPixel(row, col, 0, -1, -1);
            } else {
                action_data.getInputImage1().setPixel(row, col, mcv, -1, -1);
            }
        }
    }
    //define green channel values
    
    for( row = 0; row < height; row++) {
        for( col = 0; col < width; col++) {
            action_data.getInputImage1().setPixel(row, col, -1, (row + width - col - 1) % (mcv + 1), -1);
        }
    }
    // define blue channel values
    for( row = 0; row < height; row++) {
        for( col = 0; col < width; col++) {
            if(col < row) {
                action_data.getInputImage1().setPixel(row, col, -1, -1, 0);
            } else {
                action_data.getInputImage1().setPixel(row, col, -1, -1, mcv);
            }
        }
    }/*
    for( row = 0; row < height; row++) {
        for( col = 0; col < width; col++) {
            action_data.getInputImage1().setPixel(row, col, 255, 255, 255);
        }
    }*/

}

void setSize( ActionData& action_data ) {
    int h, w;
    h = getInteger( action_data, "Height? ");
    w = getInteger( action_data, "Width? ");
    action_data.getInputImage1().setHeight(h);
    action_data.getInputImage1().setWidth(w);
}

void setMaxColorValue( ActionData& action_data ) {
    int mcv = getInteger( action_data, "Max color value? ");
    action_data.getInputImage1().setMaxColorValue(mcv);
}

void setChannel( ActionData& action_data ) {
    int row, col, chan, val;
    row = getInteger( action_data, "Row? ");
    col = getInteger( action_data, "Column? ");
    chan = getInteger( action_data, "Channel? ");
    val = getInteger( action_data, "Value? ");
    action_data.getInputImage1().setChannel(row, col, chan, val);
}

void setPixel( ActionData& action_data ) {
    int row, col, red, green, blue;
    row = getInteger( action_data, "Row? ");
    col = getInteger( action_data, "Column? ");
    red = getInteger( action_data, "Red? ");
    green = getInteger( action_data, "Green? ");
    blue = getInteger( action_data, "Blue? ");
    action_data.getInputImage1().setPixel(row, col, red, green, blue);
}

void clearAll( ActionData& action_data ) {
    int width = action_data.getInputImage1().getWidth();
    int height = action_data.getInputImage1().getHeight();
    for( int i=0; i < height; i++ ) {
        for( int j=0; j < width; j++ ) {
            for( int c=0; c<=2; c++ ) {
                action_data.getInputImage1().setChannel(i,j,c,0);
            }
        }
    }
}

void simpleSquaresPattern( ActionData& action_data ) {
    int size, row, col;
    size = getInteger( action_data, "Image size? ");
    action_data.getInputImage1().setHeight(size);
    action_data.getInputImage1().setWidth(size);

    //red
    for(row = 0; row < size / 2; row++) {
        for( col = 0; col < size; col++) {
            action_data.getInputImage1().setChannel(row, col, 0, 127);
        }
    }
    for(row = size / 2; row < size; row++) {
        for( col = 0; col < size; col++) {
            action_data.getInputImage1().setChannel(row, col, 0, 255);
        }
    }
    //blue
    for(row = 0; row < size; row++) {
        for( col = 0; col < size / 2; col++) {
            action_data.getInputImage1().setChannel(row, col, 1, 0);
        }
    }
    for(row = 0; row < size; row++) {
        for( col = size / 2; col < size; col++) {
            action_data.getInputImage1().setChannel(row, col, 1, 255);
        }
    }
    //green
    for(row = size; row < size; row++) {
        for( col = 0; col < size; col++) {
            action_data.getInputImage1().setChannel(row, col, 2, 255);
        }
    }
}