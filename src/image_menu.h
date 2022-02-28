
#ifndef _IMAGE_MENU_H_
#define _IMAGE_MENU_H_
#include <iostream>
#include <string>
#include "MenuData.h"

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

// image_output.cpp
void drawAsciiImage( ActionData& action_data );
void writeUserImage( ActionData& action_data );
// assignment 5
void copyImage( ActionData& action_data );
void readUserImage1( ActionData& action_data );

// controllers.cpp
int assignment1( std::istream& is, std::ostream& os );
int assignment2( std::istream& is, std::ostream& os );
int assignment3( std::istream& is, std::ostream& os );
//exam 1 controllers
int hero( ActionData& action_data );
int simple_squares_ascii( ActionData& action_data );
//assignment 5
void showMenu( MenuData& menu_data, ActionData& action_data );
void takeAction(const std::string& choice, MenuData& menu_data, ActionData& action_data);
void configureMenu( MenuData& menu_data );
int imageMenu(std::istream& is, std::ostream& os);



#endif /*_IMAGE_MENU_H_*/