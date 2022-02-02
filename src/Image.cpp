#include "Image.h"


Image::Image() : height(0), width(0) {}  // default constructor
Image::Image(const int& height, const int& width) {;
    setHeight(height);
    setWidth(width);
    }
	
int Image::getHeight() const {
	return height ;
	}
int Image::getWidth() const {
	return width ;
	}
bool Image::indexValid(const int& row, const int& column, const int& channel) const {
	bool ifRow = false;
	bool ifColumn = false;
	bool ifChannel = false;
	bool answer = false;
	if((row <= height) and (row >= 0)) {
		ifRow = true ;
		}
	if((column <= width) and (column >= 0)) {
		ifColumn = true;
	};
	if((channel <= 2) and (channel >= 0)) {
		ifChannel = true;
		};
	if(ifRow and ifColumn and ifChannel) {
		answer = true;
		};
	return answer;
	}
int Image::index(const int& row, const int& column, const int& channel) const {
	int i;
	i = ((row * width * 3) + (column * 3)) + channel;
	return i;
	}
int Image::getChannel( const int& row, const int& column, const int& channel) const {
	int i;
	i = index(row, column, channel);
	if(not indexValid(row, column, channel)){
		return -1;}
	else {
	return mVector[i];}
}
void Image::setHeight(const int& Height) {
	if(Height >= 0) {
		height = Height;
		mVector.resize(width * height * 3);
		}
	return;
	}
void Image::setWidth(const int& Width) {
	if(Width >= 0) {
		width = Width;
		mVector.resize(width * height * 3);
		}
	return;
	}
void Image::setChannel( const int& row, const int& column, const int& channel, const int& value ) {
	int i;
	if(not indexValid(row, column, channel)){
		return;}
	i = index(row, column, channel);
	mVector[i] = value;
}