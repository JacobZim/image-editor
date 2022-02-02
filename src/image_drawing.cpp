#include <iostream>
#include "image_menu.h"
#include <iostream>


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