#include <iostream>
#include "image_menu.h"

int assignment1( std::istream& is, std::ostream& os) {
    return askQuestions3(is, os);
}

int assignment2( std::istream& is, std:: ostream& os ) {
    Image img;
    diagonalQuadPattern(is, os, img);
    drawAsciiImage(is, os, img);
    return 0;
}