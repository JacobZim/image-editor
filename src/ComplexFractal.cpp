

#include "ComplexFractal.h"

ComplexFractal::ComplexFractal(): 
ThreadedGrid(200, 300), mMinX(-1.5), mMaxX(1.5), mMinY(-1), mMaxY(1), mDX(0.01), mDY(0.01) {}

ComplexFractal::ComplexFractal( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y ):
ThreadedGrid(height, width) {
    mMinX = min_x;
    mMaxX = max_x;
    mMinY = min_y;
    mMaxY = max_y;
    mDX = 0.01;
    mDY = 0.01;
}
ComplexFractal::~ComplexFractal( ) {}
double ComplexFractal::getMinX( ) const {
    return mMinX;
}
double ComplexFractal::getMaxX( ) const {
    return mMaxX;
}
double ComplexFractal::getMinY( ) const {
    return mMinY;
}
double ComplexFractal::getMaxY( ) const {
    return mMaxY;
}
void ComplexFractal::setGridSize( const int& height, const int& width ) {
    if( (height >= 2) & (width >= 2) ) {
        NumberGrid::setGridSize(height, width);
        setDeltas(calculateDeltaX(), calculateDeltaY());
    }
}
void ComplexFractal::setPlaneSize( const double& min_x, const double& max_x, const double& min_y, const double& max_y ) {
    bool a, b, c, d, e, f;
    a = (min_x <= 2.0) & (min_x >= -2.0);
    b = (max_x <= 2.0) & (max_x >= -2.0);
    c = (min_y <= 2.0) & (min_y >= -2.0);
    d = (max_y <= 2.0) & (max_y >= -2.0);
    e = min_x != max_x;
    f = min_y != max_y;

    if (a & b & c & d & e & f) {
        if (min_x > max_x) {
            mMinX = max_x;
            mMaxX = min_x;
        } else {
            mMinX = min_x;
            mMaxX = max_x;
        }
        if (min_y > max_y) {
            mMinY = max_y;
            mMaxY = min_y;
        } else {
            mMinY = min_y;
            mMaxY = max_y;
        }
        setDeltas(calculateDeltaX(), calculateDeltaY());
    }
}
double ComplexFractal::getDeltaX( ) const {
    return mDX;
}
double ComplexFractal::getDeltaY( ) const {
    return mDY;
}
void ComplexFractal::setDeltas( const double& delta_x, const double& delta_y ) {
    if ((delta_x > 0) & (delta_y > 0)) {
        mDX = delta_x;
        mDY = delta_y;
    }
}
double ComplexFractal::calculateDeltaY( ) const {
    double dY;
    dY = (mMaxY - mMinY) / (mHeight - 1);
    return dY;
}
double ComplexFractal::calculateDeltaX( ) const {
    return (mMaxX - mMinX) / (mWidth - 1);
}
double ComplexFractal::calculatePlaneXFromPixelColumn( const int& column ) const {
    if ((column >= mWidth) or (column < 0)) {
        return 0;
    }
    return (mMinX + column * getDeltaX());
}
double ComplexFractal::calculatePlaneYFromPixelRow( const int& row ) const {
    if ((row >= mHeight) or (row < 0)) {
        return 0;
    }
    return (mMaxY - row * getDeltaY());
}
void ComplexFractal::calculatePlaneCoordinatesFromPixelCoordinates( const int& row, const int& column, double& x, double& y ) const {
    if ((row >= mHeight) | (row < 0) | (column >= mWidth) | (column < 0)) {
        x = 0;
        y = 0;
    } else {
        x = calculatePlaneXFromPixelColumn(column);
        y = calculatePlaneYFromPixelRow(row);
    }
}
int ComplexFractal::calculateNumber( const int& row, const int& column ) const {
    if (not indexValid(row, column)) {
        return -1;
    } else {
        double x, y;
        calculatePlaneCoordinatesFromPixelCoordinates(row, column, x, y);
        int z = std::abs(getMaxNumber() * std::sin(10*x) * std::cos(10*y));
        return z;
    }
}
