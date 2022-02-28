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

    /* old code
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
                /* old code
                //is.read((char*) buffer, sizeof(buffer[0]) ); //read one byte of data
                //int a = ((i * w * 3) + (j * 3)) + k ;
                */
                
                is.read((char*)(&mDataBuffer[0]), 1);
                
                this->setChannel(i,j,k,mDataBuffer[0]);
            }
        }
    }
}


bool PPM::operator==( const PPM& rhs ) const {
    int s1, s2;
    s1 = this->getWidth() * this->getHeight();
    s2 = rhs.getWidth() * rhs.getHeight();
    return s1 == s2;
}
bool PPM::operator!=( const PPM& rhs ) const {
    return !(*this==rhs);
}
bool PPM::operator<( const PPM& rhs ) const {
    int s1, s2;
    s1 = this->getWidth() * this->getHeight();
    s2 = rhs.getWidth() * rhs.getHeight();
    return s1 < s2;
}
bool PPM::operator<=( const PPM& rhs ) const {
    int s1, s2;
    s1 = this->getWidth() * this->getHeight();
    s2 = rhs.getWidth() * rhs.getHeight();
    return s1 <= s2;
}
bool PPM::operator>( const PPM& rhs ) const {
    int s1, s2;
    s1 = this->getWidth() * this->getHeight();
    s2 = rhs.getWidth() * rhs.getHeight();
    return s1 > s2;
}
bool PPM::operator>=( const PPM& rhs ) const {
    int s1, s2;
    s1 = this->getWidth() * this->getHeight();
    s2 = rhs.getWidth() * rhs.getHeight();
    return s1 >= s2;
}
PPM& PPM::operator+=( const PPM& rhs ) {
    int w, h, s;
    w = this->getWidth();
    h = this->getHeight();
    for(int i=0; i < h; i++ ) {
        for(int j=0; j < w; j++ ) {
            for(int c=0; c < 3; c++ ) {
                s = this->getChannel(i,j,c) + rhs.getChannel(i,j,c);
                if(s>this->getMaxColorValue()) {
                    s = this->getMaxColorValue();
                }
                this->setChannel(i,j,c,s);
            }
        }
    }
    return *this;
}
PPM& PPM::operator-=( const PPM& rhs ) {
    int w, h, s;
    w = this->getWidth();
    h = this->getHeight();
    for(int i=0; i < h; i++ ) {
        for(int j=0; j < w; j++ ) {
            for(int c=0; c < 3; c++ ) {
                s = this->getChannel(i,j,c) - rhs.getChannel(i,j,c);
                if(s<0) {
                    s = 0;
                }
                this->setChannel(i,j,c,s);
            }
        }
    }
    return *this;
}
PPM& PPM::operator*=( const double& rhs ) {
    int w, h, s;
    w = this->getWidth();
    h = this->getHeight();
    for(int i=0; i < h; i++ ) {
        for(int j=0; j < w; j++ ) {
            for(int c=0; c < 3; c++ ) {
                s = this->getChannel(i,j,c) * rhs;
                if(s>this->getMaxColorValue()) {
                    s = this->getMaxColorValue();
                } else if(s<0) {
                    s = 0;
                }
                this->setChannel(i,j,c,s);
            }
        }
    }
  return *this;
}
PPM& PPM::operator/=( const double& rhs ) {
    int w, h, s;
    w = this->getWidth();
    h = this->getHeight();
    for(int i=0; i < h; i++ ) {
        for(int j=0; j < w; j++ ) {
            for(int c=0; c < 3; c++ ) {
                s = this->getChannel(i,j,c) / rhs;
                if(s>this->getMaxColorValue()) {
                    s = this->getMaxColorValue();
                } else if(s<0) {
                    s = 0;
                }
                this->setChannel(i,j,c,s);
            }
        }
    }
    return *this;
}
PPM PPM::operator+( const PPM& rhs ) const {
    PPM result( this->getHeight(), this->getWidth());
    result.setMaxColorValue(this->getMaxColorValue());
    int w, h, s;
    w = this->getWidth();
    h = this->getHeight();
    for(int i=0; i < h; i++ ) {
        for(int j=0; j < w; j++ ) {
            for(int c=0; c < 3; c++ ) {
                s = this->getChannel(i,j,c) + rhs.getChannel(i,j,c);
                if(s>this->getMaxColorValue()) {
                    s = this->getMaxColorValue();
                }
                result.setChannel(i,j,c,s);
            }
        }
    }
    return result;
}
PPM PPM::operator-( const PPM& rhs ) const {
    PPM result( this->getHeight(), this->getWidth());
    result.setMaxColorValue(this->getMaxColorValue());
    int w, h, s;
    w = this->getWidth();
    h = this->getHeight();
    for(int i=0; i < h; i++ ) {
        for(int j=0; j < w; j++ ) {
            for(int c=0; c < 3; c++ ) {
                s = this->getChannel(i,j,c) - rhs.getChannel(i,j,c);
                if(s<0) {
                    s = 0;
                }
                result.setChannel(i,j,c,s);
            }
        }
    }
    return result;
}
PPM PPM::operator*( const double& rhs ) const {
    PPM result( this->getHeight(), this->getWidth());
    result.setMaxColorValue(this->getMaxColorValue());
    int w, h, s;
    w = this->getWidth();
    h = this->getHeight();
    for(int i=0; i < h; i++ ) {
        for(int j=0; j < w; j++ ) {
            for(int c=0; c < 3; c++ ) {
                s = this->getChannel(i,j,c) * rhs;
                if(s>this->getMaxColorValue()) {
                    s = this->getMaxColorValue();
                } else if(s<0) {
                    s = 0;
                }
                result.setChannel(i,j,c,s);
            }
        }
    }
    return result;
}
PPM PPM::operator/( const double& rhs ) const {
    PPM result( this->getHeight(), this->getWidth());
    result.setMaxColorValue(this->getMaxColorValue());
    int w, h, s;
    w = this->getWidth();
    h = this->getHeight();
    for(int i=0; i < h; i++ ) {
        for(int j=0; j < w; j++ ) {
            for(int c=0; c < 3; c++ ) {
                s = this->getChannel(i,j,c) / rhs;
                if(s>this->getMaxColorValue()) {
                    s = this->getMaxColorValue();
                } else if( s < 0 ) {
                    s = 0;
                }
                result.setChannel(i,j,c,s);
            }
        }
    }
    return result;
}

PPM& PPM::operator*=( const PPM& rhs ) {
    int w, h, s, r, v;
    w = this->getWidth();
    h = this->getHeight();
    for(int i=0; i < h; i++ ) {
        for(int j=0; j < w; j++ ) {
            for(int c=0; c < 3; c++ ) {
                s = this->getChannel(i,j,c);
                r = rhs.getChannel(i,j,c);
                v = rhs.getMaxColorValue();

                s *= r;
                s /= v;
                
                this->setChannel(i,j,c,s);
            }
        }
    }
    return *this;
}


void PPM::grayFromChannel( PPM& dst, const int& src_channel ) const {
    dst.setHeight(this->getHeight());
    dst.setWidth(this->getWidth());
    dst.setMaxColorValue(this->getMaxColorValue());
    int w, h, v;
    w = this->getWidth();
    h = this->getHeight();
    for( int i=0; i<h; i++) {
        for( int j=0; j<w; j++) {
            v = this->getChannel(i,j,src_channel);
            dst.setPixel(i, j, v, v, v);
        }
    }
}
void PPM::grayFromRed( PPM& dst ) const {
    this->grayFromChannel(dst, 0);
}
void PPM::grayFromGreen( PPM& dst ) const {
    this->grayFromChannel(dst, 1);
}
void PPM::grayFromBlue( PPM& dst ) const {
    this->grayFromChannel(dst, 2);
}
double PPM::linearColorimetricPixelValue( const int& row, const int& column ) const {
    
    int r, g, b;
    double lcpv;
    
    r = this->getChannel(row, column , 0);
    g = this->getChannel(row,column ,1);
    b = this->getChannel(row,column ,2);
    lcpv = (0.2126 * r) + (0.7152 * g) + (0.0722 * b);
    return lcpv;
}
void PPM::grayFromLinearColorimetric( PPM& dst ) const {
    dst.setHeight(this->getHeight());
    dst.setWidth(this->getWidth());
    dst.setMaxColorValue(this->getMaxColorValue());

    int w, h;
    w = this->getWidth();
    h = this->getHeight();

    for( int i=0; i<h; i++) {
        for( int j=0; j<w; j++) {
            for(int c=0; c< 3; c++ ) {
                dst.setChannel(i, j, c, this->linearColorimetricPixelValue(i,j));
            }
        }
    }
}

void PPM::orangeFilter(PPM& dst) const {
    dst.setHeight(this->getHeight());
    dst.setWidth(this->getWidth());
    dst.setMaxColorValue(this->getMaxColorValue());

    int new_red, new_green, new_blue, old_red, old_green, old_blue, h, w, mcv;
    h = this->getHeight();
    w = this->getWidth();
    mcv = this->getMaxColorValue();

    for( int i=0; i<h; i++) {
        for( int j=0; j<w; j++) {
            old_red = this->getChannel(i,j,0);
            old_green = this->getChannel(i,j,1);
            old_blue = this->getChannel(i,j,2);

            new_red = 2*(2*old_red+old_green)/3;
            if( new_red > mcv) {
                new_red = mcv;
            }
            new_green = 2*(2*old_red+old_green)/6;
            if( new_green > mcv) {
                new_green = mcv;
            }
            new_blue = old_blue/2;
            if( new_blue > mcv) {
                new_blue = mcv;
            }
            dst.setPixel(i,j, new_red, new_green, new_blue);
        }
    }
}