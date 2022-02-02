#ifndef _IMAGE_H_
#define _IMAGE_H_
#include <vector>


class Image {
public:
    Image();
    Image( const int& height, const int& width);
    int getHeight() const;
    int getWidth() const;
    int getChannel( const int& row, const int& column, const int& channel) const;
    void setHeight( const int& height);
    void setWidth( const int& width);
    void setChannel( const int& row, const int& column, const int& channel, const int& value );
    bool indexValid( const int& row, const int& column, const int& channel ) const;
    int index( const int& row, const int& column, const int& channel ) const;
protected:
    int width;
    int height;
    std::vector<int> mVector;
private:
};






#endif 