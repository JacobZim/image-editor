

#include <iostream>
#include "image_menu.h"

int assignment1( std::istream& is, std::ostream& os) {
    ActionData action_data(is, os);
    return askQuestions3(action_data);
}

int assignment2( std::istream& is, std:: ostream& os ) {
    ActionData action_data(is, os);
    diagonalQuadPattern(action_data);
    copyImage(action_data);
    drawAsciiImage(action_data);
    return 0;
}

int assignment3( std::istream& is, std::ostream& os ) {
    ActionData action_data(is, os);
    stripedDiagonalPattern(action_data);
    copyImage(action_data);
    writeUserImage(action_data);
    return 0;
}

int hero( std::istream& is, std::ostream& os ) {
    ActionData action_data(is, os);
    return askHeroQuestions(action_data);
}

int simple_squares_ascii(std::istream& is, std::ostream& os) {
    ActionData action_data(is, os);
    simpleSquaresPattern(action_data);
    copyImage(action_data);
    drawAsciiImage(action_data);
    return 0;
}

void showMenu( MenuData& menu_data, ActionData& action_data ) {
    int num;
    std::string name, des, func;
    num = menu_data.getNames().size();
    for( int i=0; i<num; i++ ) {
        name = menu_data.getNames()[i];
        des = menu_data.getDescription(name);
        action_data.getOS() << name << ") " << des << std::endl;
    }
}

void takeAction(const std::string& choice, MenuData& menu_data, ActionData& action_data) {
    if(menu_data.getFunction(choice)) {
        menu_data.getFunction(choice)(action_data);
    } else if(choice == "menu") {
        showMenu( menu_data, action_data );
    } else {
        std::cout << "Unknown action " << choice << "." << std::endl;
    }
}

void configureMenu( MenuData& menu_data ) {
    ActionFunctionType drawAsciiImage{}, writeUserImage{}, copyImage{}, readUserImage1{}, commentLine{}, setSize{}, setMaxColorValue{}, setChannel{}, setPixel{}, clearAll{}, quit{};
    menu_data.addAction("draw-ascii", drawAsciiImage, "Write output image to terminal as ASCII art.");
    menu_data.addAction("write", writeUserImage, "Write output image to file.");
    menu_data.addAction("copy", copyImage, "Copy input image 1 to output image.");
    menu_data.addAction("read1", readUserImage1, "Read file into input image 1.");
    menu_data.addAction("#", commentLine, "Comment to end of line.");
    menu_data.addAction("size", setSize, "Set the size of input image 1.");
    menu_data.addAction("max-color-value", setMaxColorValue, "Set the max color value of input image 1.");
    menu_data.addAction("channel", setChannel, "Set a channel value in input image 1.");
    menu_data.addAction("pixel", setPixel, "Set a pixel's 3 values in input image 1.");
    menu_data.addAction("clear", clearAll, "Set all pixels to 0,0,0 in input image 1.");
    menu_data.addAction("quit", quit, "Quit.");
}

int imageMenu( std::istream& is, std::ostream& os ) {
    ActionData action_data(is, os);
    MenuData menu_data;
    configureMenu( menu_data );
    std::string choice;
    while( (action_data.getDone() != true) && (action_data.getIS().good())) {
        choice = getChoice( action_data );
        takeAction(choice, menu_data, action_data);
    }
    return 0;
}

