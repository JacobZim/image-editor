#include "image_menu.h"
#include <string.h>
#include <iostream>


std::string getString( ActionData& action_data, const std::string& prompt) {
    std::string x;
    action_data.getOS() << prompt;
    action_data.getIS() >> x;
    return x;
}

int getInteger( ActionData& action_data, const std::string& prompt) {
    int x;
    action_data.getOS() << prompt;
    action_data.getIS() >> x;
    return x;
}

double getDouble( ActionData& action_data, const std::string& prompt ) {
    double x;
    action_data.getOS() << prompt;
    action_data.getIS() >> x;
    return x;
}

int askQuestions3(ActionData& action_data) {
    std::string p1 = "What is your favorite color? ";
    std::string p2 = "What is your favorite integer? ";
    std::string p3 = "What is your favorite number? ";

    std::string color;
    color = getString( action_data, p1);
    int integer;
    integer = getInteger( action_data, p2);
    double number;
    number = getDouble( action_data, p3);

    for (int i = 1; i <= integer; i++) {
        action_data.getOS() << i << " " << color << " " << number << std::endl;
    }

    return integer;
}
int askHeroQuestions( ActionData& action_data) {
    std::string hero;
    int year;
    hero = getString( action_data, "Who is your hero? ");
    year = getInteger( action_data, "What year were they born? ");
    action_data.getOS() << hero << " was born in " << year << "." << std::endl ;
    return year;
}

// assignment 5
std::string getChoice( ActionData& action_data ) {
    return getString( action_data, "Choice? ");
}
void commentLine( ActionData& action_data ) {
    char *buffer[1];
    do {
        action_data.getIS().read( buffer[0], sizeof(buffer[0]));
     } while( action_data.getIS().good() && (strcmp(buffer[0], "\n") != 0));
}
void quit( ActionData& action_data ) {
    action_data.setDone();
}