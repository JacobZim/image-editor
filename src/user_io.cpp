#include "image_menu.h"
#include <string>
#include <iostream>

std::string getString( std::istream& is, std::ostream& os, const std::string& prompt) {
    std::string x;
    os << prompt << std::endl;
    is >> x;
    return x;
}

int getInteger( std::istream& is, std::ostream& os, const std::string& prompt) {
    int x;
    os << prompt << std::endl;
    is >> x;
    return x;
}

double getDouble( std::istream& is, std::ostream& os, const std::string& prompt ) {
    double x;
    os << prompt << std::endl;
    is >> x;
    return x;
}

int askQuestions3(std::istream& is, std::ostream& os) {
    std::string p1 = "What is your favorite color?";
    std::string p2 = "What is your favorite integer?";
    std::string p3 = "What is your favorite number?";

    std::string color;
    color = getString(is, os, p1);
    int integer;
    integer = getInteger(is, os, p2);
    double number;
    number = getDouble(is, os, p3);

    for (int i = 1; i <= integer; i++) {
        std::cout << i << " " << color << " " << number << std::endl;
    }

    return number;
}