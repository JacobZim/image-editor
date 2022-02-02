#include <iostream>
#include "image_menu.h"
#include <string>



void diagonalQuadPattern( std::istream& is, std::ostream& os, Image& image ) {
	int height;
	int width;
	int tophalf;
	
	int row;
	int col;
	
	height = getInteger(is, os, "Image height? ");
	width = getInteger(is, os, "Image width? ");
	image.setHeight(height);
	image.setWidth(width);
	
	tophalf = (image.getHeight() / 2) ;
	
	// top half for red, bottom half for red
	for(row = 0; row < tophalf; row++){
		for(col = 0; col <= image.getWidth(); col++){
			image.setChannel(row, col, 0, 0);
		}};
	for(row = tophalf; row <= image.getHeight(); row++) {
		for(col = 0; col < image.getWidth(); col++) {
			image.setChannel(row, col, 0, 255);
		}};
	
	// left half for blue, right half for blue
	for(row = 0; row <= image.getHeight(); row++){
		for(col = 0; col < image.getWidth() / 2; col++){
			image.setChannel(row, col, 2, 0);
		}};

	for(row = 0; row <= image.getHeight(); row++) {
		for(col = image.getWidth() / 2; col <= image.getWidth(); col++) {
			image.setChannel(row, col, 2, 255);
		}};
	
	// function for designating green based off position
	for(row = 0; row <= image.getHeight(); row++){
		for(col = 0; col <= image.getWidth(); col++){
			image.setChannel(row, col, 1, ((2*row) + (2*col)) % 256);
		}};
	return;
}

void stripedDiagonalPattern( std::istream& is, std::ostream& os, PPM& p ) {
    
    int height = 0, width = 0;
    height = getInteger( is, os, "Image height? ");
    width = getInteger( is, os, "Image width? ");
    os << "flag";
    p.setHeight(height);
    p.setWidth(width);
    
    int mcv = (height + width) / 3;
    if (mcv > 255) {
        mcv = 255;
    }
    
    p.setMaxColorValue(mcv);
    int row, col;
    //define red channel values
    
    for ( row = 0; row < height / 2; row++) {
        for( col = 0; col < width; col++) {
            p.setPixel(row, col, 0, -1, -1);
        }
    }
    for( row = height / 2; row < height; row++) {
        if(row % 3 == 0) {
            for( col = 0; col < width; col++) {
                p.setPixel(row, col, 0, -1, -1);
            }
        } else {
            for( col = 0; col < width; col++) {
                p.setPixel(row, col, mcv, -1, -1);
            }
        }
    }
    //define green channel values
    
    for( row = 0; row < height; row++) {
        for( col = 0; col < width; col++) {
            p.setPixel(row, col, -1, (row + width - col - 1)/mcv, -1);
        }
    }
    // define blue channel values
    for( row = 0; row < height; row++) {
        for( col = 0; col < width; col++) {
            if(col < row) {
                p.setPixel(row, col, -1, -1, 0);
            } else {
                p.setPixel(row, col, -1, -1, mcv);
            }
        }
    }


}