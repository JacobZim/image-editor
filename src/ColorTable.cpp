
#include "ColorTable.h"



Color::Color(): mRed(0), mGreen(0), mBlue(0) {}
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

int Color::getChannel( const int& channel ) const {
    switch(channel) {
    case 0:
        return mRed;
    case 1:
        return mGreen;
    case 2:
        return mBlue;
    }
    return -1;
}
void Color::setRed( const int& value ){
    if (value >= 0) {
        mRed = value;
    }
}
void Color::setGreen( const int& value ) {
    if (value >= 0) {
        mGreen = value;
    }
}
void Color::setBlue( const int& value ) {
    if (value >= 0) {
        mBlue = value;
    }
}
void Color::setChannel( const int& channel, const int& value ) {
    if (value < 0) {
        return;
    }
    else if (channel == 0) { 
        mRed = value;
    }
    else if (channel == 1) {
        mGreen = value;
    }
    else if (channel == 2) {
        mBlue = value;
    }
}
void Color::invert( const int& max_color_value ) {
    if((mRed > max_color_value) || (mGreen > max_color_value) || (mBlue > max_color_value)) {
        return;
    } else {
        mRed = max_color_value - mRed;
        mGreen = max_color_value - mGreen;
        mBlue = max_color_value - mBlue;
    }
}
bool Color::operator==( const Color& rhs ) const {
    bool t1, t2, t3;
    t1 = mRed == rhs.mRed;
    t2 = mGreen == rhs.mGreen;
    t3 = mBlue == rhs.mBlue;
    if (t1 && t2 && t3) {
        return true;
    } else {
        return false;
    }
}
std::ostream& operator<<( std::ostream& os, const Color& color ) {
    int r,g,b;
    r = color.getRed();
    g = color.getGreen();
    b = color.getBlue();
    os << r << ":" << g << ":" << b ;
    return os;
}

// my helper functions
void Color::setAllChannels( const int& red, const int& green, const int& blue ) {
    this->setChannel(0, red);
    this->setChannel(1, green);
    this->setChannel(2, blue);
}
void Color::setError() {
    this->mRed = -1;
    this->mGreen = -1;
    this->mBlue = -1;
}


ColorTable::ColorTable( const int& num_color ) {
    mVector.resize(num_color);
}
int ColorTable::getNumberOfColors( ) const {
    return mVector.size();
}
void ColorTable::setNumberOfColors( const int& num_color ) {
    mVector.resize(num_color);
}
const Color& ColorTable::operator[]( const int& i ) const {
    if ((i > (this->getNumberOfColors() - 1)) || (i < 0)) {
        static Color blank(-1, -1, -1);
        return blank;
    } else {
        return mVector[i];
    }
}
Color& ColorTable::operator[]( const int& i ) {
    if ((i > (this->getNumberOfColors() - 1)) || (i < 0)) {
        static Color blank(-1, -1, -1);
        blank.setError();
        return blank;
    } else {
        return mVector[i];
    }
}
void ColorTable::setRandomColor( const int& max_color_value, const int& position ) {
    if ((position > (this->getNumberOfColors() - 1)) || (position < 0) || (max_color_value < 0)) {
        return;
    }
    int mod = max_color_value + 1;
    mVector[position].setRed(std::rand() % mod);
    mVector[position].setGreen(std::rand() % mod);
    mVector[position].setBlue(std::rand() % mod);
}
double ColorTable::gradientSlope(const double y1, const double y2, const double x1, const double x2) const {
    double dx, dy, slope;
    dx = x1 - x2;
    dy = y1 - y2;
    slope = dy / dx;
    return slope;
}
double ColorTable::gradientValue(const double y1, const double x1, const double slope, const double x) const {
    double y2;
    y2 = y1 + (x - x1) * slope;
    return y2;
}
void ColorTable::insertGradient( const Color& color1, const Color& color2, const int& position1, const int& position2 ) {
    if ((position1 >= position2) || (position1 < 0) || (position2 < 0) || (position1 >= getNumberOfColors()) || (position2 >= getNumberOfColors())) {
        return;
    }
    //x is our number of colors
    //steps (color2 - color1 / n -1) 
    //and y is our color value (y1 + slope*step)
    // slope is (color2 - color1 / 
    int colors = position2 - position1;
    double redslope, greenslope, blueslope;

    redslope = double(color2.getRed() - color1.getRed()) / double(colors);
    greenslope = double(color2.getGreen() - color1.getGreen()) / double(colors);
    blueslope = double(color2.getBlue() - color1.getBlue()) / double(colors);

    for (int i = 0; i <= colors; i++) {
        this->mVector[position1 + i].setRed(color1.getRed() + i * redslope);
        this->mVector[position1 + i].setGreen(color1.getGreen() + i * greenslope);
        this->mVector[position1 + i].setBlue(color1.getBlue() + i * blueslope);
    }
}
int ColorTable::getMaxChannelValue( ) const {
    int maxValue = 0;
    for (int i=0; i < getNumberOfColors(); i++) {
        Color x = mVector[i];
        if (x.getRed() > maxValue) 
            maxValue = x.getRed();
        if (x.getGreen() > maxValue)
            maxValue = x.getGreen();
        if (x.getBlue() > maxValue) 
            maxValue = x.getBlue();
    }
    return maxValue;
}
