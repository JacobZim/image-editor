

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

    ActionFunctionType read2 = &readUserImage2;
    ActionFunctionType pluss = &plus;
    ActionFunctionType plusE = &plusEquals;
    ActionFunctionType minuss = &minus;
    ActionFunctionType minusE = &minusEquals;
    ActionFunctionType timess = &times;
    ActionFunctionType timesE = &timesEquals;
    ActionFunctionType dividee = &divide;
    ActionFunctionType divideE = &divideEquals;

    ActionFunctionType redg = &grayFromRed;
    ActionFunctionType greeng = &grayFromGreen;
    ActionFunctionType blueg = &grayFromBlue;
    ActionFunctionType ling = &grayFromLinearColorimetric;
    ActionFunctionType circ = &drawCircle;
    ActionFunctionType boxe = &drawBox;

    ActionFunctionType square = &drawSquare;
    ActionFunctionType orange = &orangeFilter;
    ActionFunctionType timesEp = &timesEqualsPPM;

    ActionFunctionType cG = &configureGrid;
    ActionFunctionType sG = &setGrid;
    ActionFunctionType aG = &applyGrid;

    ActionFunctionType manh = &setManhattanNumbers;

    ActionFunctionType sCTS = &setColorTableSize;
    ActionFunctionType sC = &setColor;
    ActionFunctionType sRC = &setRandomColor;
    ActionFunctionType sCG = &setColorGradient;
    ActionFunctionType aGCT = &applyGridColorTable;

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

    menu_data.addAction("read2", read2, "Read file into input image 2.");
    menu_data.addAction("+", pluss, "Set output image from sum of input image 1 and input image 2.");
    menu_data.addAction("+=", plusE, "Set input image 1 by adding in input image 2.");
    menu_data.addAction("-", minuss, "Set output image from difference of input image 1 and input image 2.");
    menu_data.addAction("-=", minusE, "Set input image 1 by subtracting input image 2.");
    menu_data.addAction("*", timess, "Set output image from input image 1 multiplied by a number.");
    menu_data.addAction("*=", timesE, "Set input image 1 by multiplying by a number.");
    menu_data.addAction("/", dividee, "Set output image from input image 1 divided by a number.");
    menu_data.addAction("/=", divideE, "Set input image 1 by dividing by a number.");

    menu_data.addAction("red-gray", redg, "Set output image by grayscale from red on input image 1.");
    menu_data.addAction("green-gray", greeng, "Set output image by grayscale from green on input image 1.");
    menu_data.addAction("blue-gray", blueg, "Set output image by grayscale from blue on input image 1.");
    menu_data.addAction("linear-gray", ling, "Set output image by linear colorimetric grayscale on input image 1.");
    menu_data.addAction("circle", circ, "Draw a circle shape in input image 1.");
    menu_data.addAction("box", boxe, "Draw a box shape in input image 1.");

    menu_data.addAction("square", square, "Draw a square shape in input image 1.");
    menu_data.addAction("orange", orange, "Set output image from orange filter on input image 1.");
    menu_data.addAction("*=-ppm", timesEp, "Set input image 1 by multiplying by input image 2.");

    menu_data.addAction("grid", cG, "Configure the grid.");
    menu_data.addAction("grid-set", sG, "Set a single value in the grid.");
    menu_data.addAction("grid-apply", aG, "Use the grid values to set colors in the output image.");

    menu_data.addAction("manhattan", manh, "Choose to make a Manhattan distance grid.");

    menu_data.addAction("set-color-table-size", sCTS, "Change the number of slots in the color table.");
    menu_data.addAction("set-color", sC, "Set the RGB values for one slot in the color table.");
    menu_data.addAction("set-random-color", sRC, "Randomly set the RGB values for one slot in the color table.");
    menu_data.addAction("set-color-gradient", sCG, "Smoothly set the RGB values for a range of slots in the color table.");
    menu_data.addAction("grid-apply-color-table", aGCT, "Use the grid values to set colors in the output image using the color table.");

    ActionFunctionType sFPS = &setFractalPlaneSize;
    ActionFunctionType cF = &calculateFractal;

    ActionFunctionType sJP = &setJuliaParameters;
    ActionFunctionType sCF = &setComplexFractal;
    ActionFunctionType sJF = &setJuliaFractal;

    ActionFunctionType sMF = &setMandelbrotFractal;

    // ActionFunctionType cF = &calculateFractal;
    ActionFunctionType cFST = &calculateFractalSingleThread;

    ActionFunctionType aAF = &antiAliasFilter;
    ActionFunctionType cOITI = &copyOutputImageToImage1;

    menu_data.addAction("fractal-plane-size", sFPS, "Set the dimensions of the grid in the complex plane.");
    menu_data.addAction("fractal-calculate", cF, "Calculate the escape values for the fractal.");

    menu_data.addAction("julia-parameters", sJP, "Set the parameters of the Julia Set function.");
    menu_data.addAction("complex-fractal", sCF, "Choose to make a complex plane.");
    menu_data.addAction("julia", sJF, "Choose to make a Julia set.");

    menu_data.addAction("mandelbrot", sMF, "Choose to make a Mandelbrot set.");

    menu_data.addAction("fractal-calculate-single-thread", cFST, "Calculate the escape values for the fractal, single-thread.");

    menu_data.addAction("anti-alias", aAF, "Set output image from Anti-alias filter on input image 1.");
    menu_data.addAction("copyo1", cOITI, "Copy output image to input image 1.");
    
}

int imageMenu( std::istream& is, std::ostream& os ) {
    ActionData action_data(is, os);
    action_data.setGrid( new ComplexFractal );
    MenuData menu_data;
    configureMenu( menu_data );
    std::string choice;
    while( (action_data.getDone() != true) && (action_data.getIS().good())) {
        choice = getChoice( action_data );
        takeAction(choice, menu_data, action_data);
    }
    return 0;
}

void setManhattanNumbers(ActionData& action_data) {
    action_data.setGrid(new ManhattanNumbers);
}

void setComplexFractal( ActionData& action_data ) {
    ComplexFractal *ptr = new ComplexFractal;
    action_data.setGrid(ptr);
}
void setJuliaFractal( ActionData& action_data ) {
    JuliaSet *ptr = new JuliaSet;
    action_data.setGrid(ptr);
}
void setMandelbrotFractal( ActionData& action_data ) {
    MandelbrotSet *ptr = new MandelbrotSet;
    action_data.setGrid(ptr);
}
