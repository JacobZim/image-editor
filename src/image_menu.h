#include <iostream>
#include <string>
#ifndef _IMAGE_MENU_H_
#define _IMAGE_MENU_H_
#include "Image.h"
#include "PPM.h"

std::string getString( std::istream& is, std::ostream& os, const std::string& prompt );
int getInteger( std::istream& is, std::ostream& os, const std::string& prompt );
double getDouble( std::istream& is, std::ostream& os, const std::string& prompt );
int askQuestions3(std::istream& is, std::ostream& os);
int assignment1( std::istream& is, std::ostream& os );

void drawAsciiImage( std::istream& is, std::ostream& os, const Image& image );
void diagonalQuadPattern( std::istream& is, std::ostream& os, Image& image );
int assignment2( std::istream& is, std::ostream& os );

void writeUserImage( std::istream& is, std::ostream& os, const PPM& p );
void stripedDiagonalPattern( std::istream& is, std::ostream& os, PPM& p );
int assignment3( std::istream& is, std::ostream& os );

#endif /*_IMAGE_MENU_H_*/