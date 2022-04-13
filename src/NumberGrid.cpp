#include "NumberGrid.h"
#include <cmath>



NumberGrid::NumberGrid( ) {
    this->mHeight = 300;
    this->mWidth = 400;
    this->mMCV = 255;
    int x = 0;
    std::vector<int> cpy( mHeight * mWidth, x );
    this->mGrid = cpy;
}
NumberGrid::NumberGrid( const int& height, const int& width ) {
    this->mHeight = height;
    this->mWidth = width;
    this->mMCV = 255;
    int x = 0;
    std::vector<int> cpy( mHeight * mWidth, x );
    this->mGrid = cpy;
}

NumberGrid::~NumberGrid() {}

int NumberGrid::getHeight( ) const {
    return this->mHeight;
}
int NumberGrid::getWidth() const{
    return this->mWidth;
}
int NumberGrid::getMaxNumber() const {
    return this->mMCV;
}
void NumberGrid::setGridSize( const int& height, const int& width ) {
    if( (height >= 2) & (width >= 2) ) {
        this->mHeight = height;
        this->mWidth = width;
        int x = this->mHeight * this->mWidth;
        
        this->mGrid.resize(x);
    }
}
void NumberGrid::setMaxNumber( const int& number ) {
    if( number > 0 ) {
        this->mMCV = number; 
    }
}

const std::vector<int>& NumberGrid::getNumbers( ) const {
    return this->mGrid;
}
int NumberGrid::index( const int& row, const int& column ) const {
    return (row * this->mWidth) + column;
}
bool NumberGrid::indexValid( const int& row, const int& column ) const {
    return (row < this->mHeight) && (column < this->mWidth) && (row >= 0) && (column >= 0);
    //return (uint)index(row, column) < this->mGrid.size();
}
bool NumberGrid::numberValid( const int& number ) const {
    return (number >= 0) && (number <= this->mMCV);
}
int NumberGrid::getNumber( const int& row, const int& column ) const {
    if (indexValid(row, column)) {
        return this->mGrid[index(row, column)];
    } else {
        return -1;
    }
}
void NumberGrid::setNumber( const int& row, const int& column, const int& number ) {
    if ( (numberValid( number )) && (indexValid( row, column ) ) ) 
        this->mGrid[index(row, column)] = number;
}
void NumberGrid::setPPM( PPM& ppm ) const {
    ppm.setHeight(this->mHeight);
    ppm.setWidth(this->mWidth);
    ppm.setMaxColorValue(63);
    int y;
    for ( int i = 0; i < this->mWidth; i++ ) {
        for ( int j = 0; j < this->mHeight; j++ ) {

            y = this->getNumber( j, i ) % 8;

            if ( this->getNumber(j,i) == 0 ) {
                ppm.setPixel(j, i, 0, 0, 0);
            } else if ( this->getNumber(j,i) == this->mMCV ) {
                ppm.setPixel(j, i, 63, 31, 31);
            } else if ( y == 0 ) {
                ppm.setPixel(j, i, 63, 63, 63);
            } else if ( y == 1 ) {
                ppm.setPixel(j, i, 63, 31, 31);
            } else if ( y == 2 ) {
                ppm.setPixel(j, i, 63, 63, 31);
            } else if ( y == 3 ) {
                ppm.setPixel(j, i, 31, 63, 31);
            } else if ( y == 4 ) {
                ppm.setPixel(j, i, 0, 0, 0);
            } else if ( y == 5 ) {
                ppm.setPixel(j, i, 31, 63, 63);
            } else if ( y == 6 ) {
                ppm.setPixel(j, i, 31, 31, 63);
            } else if ( y == 7 ) {
                ppm.setPixel(j, i, 63, 31, 63);
            } 
            
        }
    }
}
void NumberGrid::setPPM( PPM& ppm, const ColorTable& colors ) const {
    if (colors.getNumberOfColors() < 2) {
        return;
    }
    ppm.setHeight(this->getHeight());
    ppm.setWidth(this->getWidth());
    ppm.setMaxColorValue(colors.getMaxChannelValue());
    for (int i=0; i<ppm.getWidth(); i++) {
        for (int y=0; y<ppm.getHeight(); y++) {
            int j = this->getNumber(y, i);

            Color c;
            if (j == this->getMaxNumber()) {
                c = colors[colors.getNumberOfColors()-1];
            } else {
                c = colors[j % colors.getNumberOfColors()];
            }
            ppm.setPixel(y, i, c.getRed(), c.getGreen(), c.getBlue());
        }
    }
}


ManhattanNumbers::ManhattanNumbers( ) {
    this->mHeight = 600;
    this->mWidth = 800;
}
ManhattanNumbers::ManhattanNumbers( const int& height, const int& width ) {
    this->mHeight = height;
    this->mWidth = width;
}
ManhattanNumbers::~ManhattanNumbers() {}
int ManhattanNumbers::calculateNumber( const int& row, const int& column) const {
    int dx, dy, total;
    dx = std::abs((mWidth / 2) - column);
    dy = std::abs((mHeight / 2) - row);
    total = dx + dy;
    return total;
 }