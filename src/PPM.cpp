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
    int w, h, mcv;// current, end, leftover;
    std::string format_code, na;
    is >> format_code;
    is >> w;
    is >> h;
    is >> mcv;

    this->setWidth(w);
    this->setHeight(h);
    this->setMaxColorValue(mcv);

    char *PPMdata = new char [1]; 
    is.read(PPMdata, 1); //get rid of newline character

    /*
    current = is.tellg(); //mark current location
    is.seekg(0, is.end); //mark end of file
    end = is.tellg();
    is.seekg(current); // move back to current location
    leftover = end - current; //find left over length
    is.read( PPMdata, leftover ); //read leftover data
    */

    //char *buffer = new char [0];
    unsigned char mDataBuffer[1];

    for(int i = 0; i < h; i++) {
        for( int j = 0; j < w; j++) {
            for( int k = 0; k <= 2; k++) {
                /*
                //is.read((char*) buffer, sizeof(buffer[0]) ); //read one byte of data
                //int a = ((i * w * 3) + (j * 3)) + k ;
                */
                
                is.read((char*)(&mDataBuffer[0]), 1);
                
                this->setChannel(i,j,k,mDataBuffer[0]);
            }
        }
    }
}
