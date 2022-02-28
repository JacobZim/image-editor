#ifndef _PPM_H_
#define _PPM_H_
#include "Image.h"
#include <iostream>


class PPM: public Image {
public:
    PPM();
    PPM( const int& height, const int& width );
    int getMaxColorValue() const;
    bool valueValid( const int& value ) const;
    void setMaxColorValue( const int& max_color_value );
    void setChannel( const int& row, const int& column, const int& channel, const int& value );
    void setPixel( const int& row, const int& column, const int& red, const int& green, const int& blue );
    void writeStream( std::ostream& os ) const;
    //added during assignment 4, action data menu
    void readStream( std::istream& is );
    //assignment6 operator overloading
    bool operator==( const PPM& rhs ) const;
    bool operator!=( const PPM& rhs ) const;
    bool operator<( const PPM& rhs ) const;
    bool operator<=( const PPM& rhs ) const;
    bool operator>( const PPM& rhs ) const;
    bool operator>=( const PPM& rhs ) const;
    PPM& operator+=( const PPM& rhs );
    PPM& operator-=( const PPM& rhs );
    PPM& operator*=( const double& rhs );
    PPM& operator/=( const double& rhs );
    PPM operator+( const PPM& rhs ) const;
    PPM operator-( const PPM& rhs ) const;
    PPM operator*( const double& rhs ) const;
    PPM operator/( const double& rhs ) const;
    //assignment7 image_filters
    void grayFromChannel( PPM& dst, const int& src_channel ) const;
    void grayFromRed( PPM& dst ) const;
    void grayFromGreen( PPM& dst ) const;
    void grayFromBlue( PPM& dst ) const;
    double linearColorimetricPixelValue( const int& row, const int& column ) const;
    void grayFromLinearColorimetric( PPM& dst ) const;
    //exam2
    void orangeFilter(PPM& dst) const;
    PPM& operator*=( const PPM& rhs );
protected:
    int mMaxColorValue;
private:
};



#endif