

#include "JuliaSet.h"

JuliaSet::JuliaSet() :
ComplexFractal(), mA(-0.650492), mB(-0.478235) {}

JuliaSet::JuliaSet( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y, const double& a, const double& b ) {
    mHeight = height;
    mWidth = width;
    mMinX = min_x;
    mMaxX = max_x;
    mMinY = min_y;
    mMaxY = max_y;
    mA = a;
    mB = b;
}
JuliaSet::~JuliaSet() {}
double JuliaSet::getA( ) const {
    return mA;
}
double JuliaSet::getB( ) const {
    return mB;
}
void JuliaSet::setParameters( const double& a, const double& b ) {
    if ((a < -2.0) | (a > 2.0) | (b < -2.0) | (b > 2.0)) {
        return;
    }
    mA = a;
    mB = b;
}
void JuliaSet::calculateNextPoint( const double x0, const double y0, double& x1, double &y1 ) const {
    x1 = (x0 * x0) - (y0 * y0) + mA;
    y1 = 2 * x0 * y0 + mB;
}
int JuliaSet::calculatePlaneEscapeCount( const double& x0, const double& y0 ) const {
    double x1 = 0, y1 = 0, xn = 0, yn = 0, distance = 0;
    x1 = x0;
    y1 = y0;
    int escape;
    for (escape = 0; escape < mMCV; escape++) {
        distance = std::sqrt( x1*x1 + y1*y1 );
        if (distance > 2) {//((x1 < -2.0) | (x1 > 2.0) | (y1 < -2.0) | (y1 > 2.0)) {
            break;
        }
        xn = x1;
        yn = y1;
        calculateNextPoint(xn, yn, x1, y1);
    }
    return escape;
}
int JuliaSet::calculateNumber( const int& row, const int& column ) const {
    if ((row < 0) | (row > mHeight - 1) | (column < 0) | (column > mWidth - 1)) {
        return -1;
    }
    double x, y;
    calculatePlaneCoordinatesFromPixelCoordinates(row, column, x, y);
    return calculatePlaneEscapeCount(x, y);
}