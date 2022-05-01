

#include "MandelbrotSet.h"


MandelbrotSet::MandelbrotSet( ): ComplexFractal() {}
MandelbrotSet::MandelbrotSet( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y ):
ComplexFractal(height, width, min_x, max_x, min_y, max_y) {}
MandelbrotSet::~MandelbrotSet( ) {}
void MandelbrotSet::calculateNextPoint( const double x0, const double y0, const double& a, const double& b, double& x1, double &y1 ) const {
    x1 = x0*x0 - y0*y0 + a;
    y1 = 2*x0*y0 + b;
}
int MandelbrotSet::calculatePlaneEscapeCount( const double& a, const double& b ) const {
    double x1 = 0, y1 = 0, xn = 0, yn = 0, distance = 0;
    x1 = a;
    y1 = b;
    int escape;
    for (escape = 0; escape < mMCV; escape++) {
        distance = std::sqrt( x1*x1 + y1*y1 );
        if (distance > 2) {//((x1 < -2.0) | (x1 > 2.0) | (y1 < -2.0) | (y1 > 2.0)) {
            break;
        }
        xn = x1;
        yn = y1;
        calculateNextPoint(xn, yn, a, b, x1, y1);
    }
    return escape;
}
int MandelbrotSet::calculateNumber( const int& row, const int& column ) const {
    if ((row < 0) | (row > mHeight - 1) | (column < 0) | (column > mWidth - 1)) {
        return -1;
    }
    double x, y;
    calculatePlaneCoordinatesFromPixelCoordinates(row, column, x, y);
    return calculatePlaneEscapeCount(x, y);
}