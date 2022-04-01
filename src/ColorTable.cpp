/*
#include "ColorTable.h"



Color::Color() mRed(0), mGreen(0), mBlue(0) {}
Color::Color( const int& red, const int& green, const int& blue ) {
    mRed = red;
    mGreen = green;
    mBlue = blue;
}
int Color::getRed( ) const {
    return mRed;
}
int Color::getGreen( ) const {
    return mGreen;
}
int Color::getBlue( ) const {
    return mBlue;
}
"""
int Color::getChannel( const int& channel ) const {
    return 
}"""
void Color::setRed( const int& value ){
    if (value > 0) {
        mRed = value;
    }
}
void Color::setGreen( const int& value );
void Color::setBlue( const int& value );
void Color::setChannel( const int& channel, const int& value );
void Color::invert( const int& max_color_value );
bool Color::operator==( const Color& rhs ) const;


ColorTable::ColorTable( const int& num_color );
int ColorTable::getNumberOfColors( ) const;
void ColorTable::setNumberOfColors( const int& num_color );
const ColorTable::Color& operator[]( const int& i ) const;
Color& ColorTable::operator[]( const int& i );
void ColorTable::setRandomColor( const int& max_color_value, const int& position );
double ColorTable::gradientSlope(const double y1, const double y2, const double x1, const double x2) const;
double ColorTable::gradientValue(const double y1, const double x1, const double slope, const double x) const;
void ColorTable::insertGradient( const Color& color1, const Color& color2, const int& position1, const int& position2 );
int ColorTable::getMaxChannelValue( ) const;
*/