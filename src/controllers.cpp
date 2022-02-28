

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
        action_data.getOS() << "Unknown action '" << choice << "'." << std::endl;
    }
}

void configureMenu( MenuData& menu_data ) {
    ActionFunctionType drawAsci = &drawAsciiImage;
    ActionFunctionType write = &writeUserImage;
    ActionFunctionType cpyImage = &copyImage;
    ActionFunctionType readImage1 = &readUserImage1;
    ActionFunctionType comment = &commentLine;
    ActionFunctionType size = &setSize;
    ActionFunctionType setMCV = &setMaxColorValue;
    ActionFunctionType setChan = &setChannel;
    ActionFunctionType setPix = &setPixel;
    ActionFunctionType clear = &clearAll;
    ActionFunctionType qit = &quit;

    menu_data.addAction("draw-ascii", drawAsci, "Write output image to terminal as ASCII art.");
    menu_data.addAction("write", write, "Write output image to file.");
    menu_data.addAction("copy", cpyImage, "Copy input image 1 to output image.");
    menu_data.addAction("read1", readImage1, "Read file into input image 1.");
    menu_data.addAction("#", comment, "Comment to end of line.");
    menu_data.addAction("size", size, "Set the size of input image 1.");
    menu_data.addAction("max-color-value", setMCV, "Set the max color value of input image 1.");
    menu_data.addAction("channel", setChan, "Set a channel value in input image 1.");
    menu_data.addAction("pixel", setPix, "Set a pixel's 3 values in input image 1.");
    menu_data.addAction("clear", clear, "Set all pixels to 0,0,0 in input image 1.");
    menu_data.addAction("quit", qit, "Quit.");
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

