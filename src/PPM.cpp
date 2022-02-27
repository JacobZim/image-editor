#include "PPM.h"
#include <stdio.h>
#include <iostream>


PPM::PPM( ) : mMaxColorValue(1) {}
PPM::PPM( const int& height, const int& width) {
    setHeight(height);
    setWidth(width);
    mMaxColorValue = 1;
}
int PPM::getMaxColorValue( ) const {
    return mMaxColorValue;
}
bool PPM::valueValid( const int& value) const {
    if(value <= mMaxColorValue) {
        if(value >= 0) {
            return true;
        }
    }
    return false;
}
void PPM::setMaxColorValue( const int& max_color_value) {
    if(max_color_value <= 255 && max_color_value >= 1) {
        mMaxColorValue = max_color_value;
    }
}
void PPM::setChannel( const int& row, const int& column, const int& channel, const int& value) {
    if(valueValid(value)) {
        Image::setChannel(row, column, channel, value);
    }
}
void PPM::setPixel( const int& row, const int& column, const int& red, const int& green, const int& blue ) {
    setChannel(row, column, 0, red);
    setChannel(row, column, 1, green);
    setChannel(row, column, 2, blue);
}
void PPM::writeStream( std::ostream& os) const {
    os << "P6 " << width << " " << height << " " << mMaxColorValue << "\n";

    for(unsigned long i = 0; i < mVector.size(); i++) {
        unsigned char x = mVector[i];
        os.write((char *) &x, sizeof(x));
        
    }
}

void PPM::readStream( std::istream& is ) {
    int w, h, mcv, current, end, leftover;
    std::string format_code, na;
    is >> format_code;
    is >> w;
    is >> h;
    is >> mcv;

    current = is.tellg(); //mark current location

    is.seekg(0, is.end); //mark end of file
    end = is.tellg();

    is.seekg(current); // move back to current location

    leftover = end - current; //find left over length

    char *PPMdata = new char [leftover];
    is.read( PPMdata, leftover ); //read leftover data
}
