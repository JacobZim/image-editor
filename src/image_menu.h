
#ifndef _IMAGE_MENU_H_
#define _IMAGE_MENU_H_
#include <iostream>
#include <string>
#include "MenuData.h"
//#include "NumberGrid.h"
// #include "ComplexFractal.h"

//user_io.cpp
std::string getString( ActionData& action_data, const std::string& prompt );
int getInteger( ActionData& action_data, const std::string& prompt );
double getDouble( ActionData& action_data, const std::string& prompt );
int askQuestions3( ActionData& action_data );
//exam 1
int askHeroQuestions( ActionData& action_data );
//assignment 5 user_io functions
std::string getChoice( ActionData& action_data );
void commentLine( ActionData& action_data );
void quit(ActionData& action_data);

//image_drawing.cpp
void diagonalQuadPattern( ActionData& action_data );
void stripedDiagonalPattern( ActionData& action_data );
//exam 1
void simpleSquaresPattern( ActionData& action_data );
//assignment 5 image_drawing functions
void setSize( ActionData& action_data );
void setMaxColorValue( ActionData& action_data );
void setChannel( ActionData& action_data );
void setPixel( ActionData& action_data );
void clearAll( ActionData& action_data );
//assignment7
void drawCircle(ActionData& action_data);
void drawBox(ActionData& action_data);
//exam 2
void drawSquare(ActionData& action_data);
//assignment 8
void configureGrid(ActionData& action_data);
void setGrid(ActionData& action_data);
void applyGrid(ActionData& action_data);
//assignment 9
void setColorTableSize(ActionData& action_data);
void setColor(ActionData& action_data);
void setRandomColor(ActionData& action_data);
void setColorGradient(ActionData& action_data);
void applyGridColorTable(ActionData& action_data);
//assignment 10
void setFractalPlaneSize(ActionData& action_data);
void calculateFractal(ActionData& action_data);

// image_output.cpp
void drawAsciiImage( ActionData& action_data );
void writeUserImage( ActionData& action_data );
// assignment 5
void copyImage( ActionData& action_data );
void readUserImage1( ActionData& action_data );
void readUserImage2( ActionData& ation_data );

// controllers.cpp
int assignment1( std::istream& is, std::ostream& os );
int assignment2( std::istream& is, std::ostream& os );
int assignment3( std::istream& is, std::ostream& os );
//exam 1 controllers
int hero( std::istream& is, std::ostream& os );
int simple_squares_ascii( std::istream& is, std::ostream& os );
//assignment 5
void showMenu( MenuData& menu_data, ActionData& action_data );
void takeAction(const std::string& choice, MenuData& menu_data, ActionData& action_data);
void configureMenu( MenuData& menu_data );
int imageMenu(std::istream& is, std::ostream& os);

//image_filters.cpp
void plusEquals( ActionData& action_data );
void minusEquals( ActionData& action_data );
void timesEquals( ActionData& action_data );
void divideEquals( ActionData& action_data );
void plus( ActionData& action_data );
void minus( ActionData& action_data );
void times( ActionData& action_data );
void divide( ActionData& action_data );
//assignemnt7
void grayFromRed(ActionData& action_data);
void grayFromGreen(ActionData& action_data);
void grayFromBlue(ActionData& action_data);
void grayFromLinearColorimetric(ActionData& action_data);
//exam2
void orangeFilter(ActionData& action_data);
void timesEqualsPPM(ActionData& action_data);

//colorTable
void configureMenu(MenuData& menu_data);

//manhattan numbers exam 3
void setManhattanNumbers(ActionData& action_data);

#endif /*_IMAGE_MENU_H_*/