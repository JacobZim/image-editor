#include <iostream>
#include "image_menu.h"
#include <string>
#include <cmath>


void diagonalQuadPattern( ActionData& action_data ) {
    action_data.getInputImage1().setMaxColorValue(255);
	int height;
	int width;
	int tophalf;
	
	int row;
	int col;
	
	height = getInteger( action_data, "Image height? ");
	width = getInteger( action_data, "Image width? ");
	action_data.getInputImage1().setHeight(height);
	action_data.getInputImage1().setWidth(width);
	
	tophalf = (action_data.getInputImage1().getHeight() / 2) ;
	
	// top half for red, bottom half for red
	for(row = 0; row < tophalf; row++){
		for(col = 0; col <= action_data.getInputImage1().getWidth(); col++){
			action_data.getInputImage1().setChannel(row, col, 0, 0);
		}};
	for(row = tophalf; row <= action_data.getInputImage1().getHeight(); row++) {
		for(col = 0; col < action_data.getInputImage1().getWidth(); col++) {
			action_data.getInputImage1().setChannel(row, col, 0, 255);
		}};
	
	// left half for blue, right half for blue
	for(row = 0; row <= action_data.getInputImage1().getHeight(); row++){
		for(col = 0; col < action_data.getInputImage1().getWidth() / 2; col++){
			action_data.getInputImage1().setChannel(row, col, 2, 0);
		}};

	for(row = 0; row <= action_data.getInputImage1().getHeight(); row++) {
		for(col = action_data.getInputImage1().getWidth() / 2; col <= action_data.getInputImage1().getWidth(); col++) {
			action_data.getInputImage1().setChannel(row, col, 2, 255);
		}};
	
	// function for designating green based off position
	for(row = 0; row <= action_data.getInputImage1().getHeight(); row++){
		for(col = 0; col <= action_data.getInputImage1().getWidth(); col++){
			action_data.getInputImage1().setChannel(row, col, 1, ((2*row) + (2*col)) % 256);
		}};
	return;
}

void stripedDiagonalPattern( ActionData& action_data ) {
    /*(void) action_data.getIS();
    (void) action_data.getOS();
    (void) action_data.getInputImage1();*/
    int height = 0, width = 0;
    height = getInteger( action_data, "Image height? ");
    width = getInteger( action_data, "Image width? ");
    
    
    action_data.getInputImage1().setHeight(height);
    action_data.getInputImage1().setWidth(width);
    
    int mcv = (height + width) / 3;
    if (mcv > 255) {
        mcv = 255;
    }
    
    action_data.getInputImage1().setMaxColorValue(mcv);
    
    int row, col;
    //define red channel values
    
    for ( row = 0; row < height / 2; row++) {
        for( col = 0; col < width; col++) {
            action_data.getInputImage1().setPixel(row, col, 0, -1, -1);
        }
    } 
    for( row = height / 2; row < height; row++) {
        for( col = 0; col < width; col++ ) {
            if( (row % 3) == 0 ) {
                action_data.getInputImage1().setPixel(row, col, 0, -1, -1);
            } else {
                action_data.getInputImage1().setPixel(row, col, mcv, -1, -1);
            }
        }
    }
    //define green channel values
    
    for( row = 0; row < height; row++) {
        for( col = 0; col < width; col++) {
            action_data.getInputImage1().setPixel(row, col, -1, (row + width - col - 1) % (mcv + 1), -1);
        }
    }
    // define blue channel values
    for( row = 0; row < height; row++) {
        for( col = 0; col < width; col++) {
            if(col < row) {
                action_data.getInputImage1().setPixel(row, col, -1, -1, 0);
            } else {
                action_data.getInputImage1().setPixel(row, col, -1, -1, mcv);
            }
        }
    }/*
    for( row = 0; row < height; row++) {
        for( col = 0; col < width; col++) {
            action_data.getInputImage1().setPixel(row, col, 255, 255, 255);
        }
    }*/

}

void setSize( ActionData& action_data ) {
    int h, w;
    h = getInteger( action_data, "Height? ");
    w = getInteger( action_data, "Width? ");
    action_data.getInputImage1().setHeight(h);
    action_data.getInputImage1().setWidth(w);
}

void setMaxColorValue( ActionData& action_data ) {
    int mcv = getInteger( action_data, "Max color value? ");
    action_data.getInputImage1().setMaxColorValue(mcv);
}

void setChannel( ActionData& action_data ) {
    int row, col, chan, val;
    row = getInteger( action_data, "Row? ");
    col = getInteger( action_data, "Column? ");
    chan = getInteger( action_data, "Channel? ");
    val = getInteger( action_data, "Value? ");
    action_data.getInputImage1().setChannel(row, col, chan, val);
}

void setPixel( ActionData& action_data ) {
    int row, col, red, green, blue;
    row = getInteger( action_data, "Row? ");
    col = getInteger( action_data, "Column? ");
    red = getInteger( action_data, "Red? ");
    green = getInteger( action_data, "Green? ");
    blue = getInteger( action_data, "Blue? ");
    action_data.getInputImage1().setPixel(row, col, red, green, blue);
}

void clearAll( ActionData& action_data ) {
    int width = action_data.getInputImage1().getWidth();
    int height = action_data.getInputImage1().getHeight();
    for( int i=0; i < height; i++ ) {
        for( int j=0; j < width; j++ ) {
            for( int c=0; c<=2; c++ ) {
                action_data.getInputImage1().setChannel(i,j,c,0);
            }
        }
    }
}

void simpleSquaresPattern( ActionData& action_data ) {
    int size, row, col;
    size = getInteger( action_data, "Image size? ");
    action_data.getInputImage1().setHeight(size);
    action_data.getInputImage1().setWidth(size);

    //red
    for(row = 0; row < size / 2; row++) {
        for( col = 0; col < size; col++) {
            action_data.getInputImage1().setChannel(row, col, 0, 127);
        }
    }
    for(row = size / 2; row < size; row++) {
        for( col = 0; col < size; col++) {
            action_data.getInputImage1().setChannel(row, col, 0, 255);
        }
    }
    //blue
    for(row = 0; row < size; row++) {
        for( col = 0; col < size / 2; col++) {
            action_data.getInputImage1().setChannel(row, col, 1, 0);
        }
    }
    for(row = 0; row < size; row++) {
        for( col = size / 2; col < size; col++) {
            action_data.getInputImage1().setChannel(row, col, 1, 255);
        }
    }
    //green
    for(row = size; row < size; row++) {
        for( col = 0; col < size; col++) {
            action_data.getInputImage1().setChannel(row, col, 2, 255);
        }
    }
}


void drawCircle(ActionData& action_data) {
    int cenRow, cenCol, r, g, b, delRow, delCol;
    double distance, rad;

    cenRow = getInteger(action_data, "Center Row? ");
    cenCol = getDouble(action_data, "Center Column? ");
    rad = getInteger(action_data, "Radius? ");
    r = getInteger(action_data, "Red? ");
    g = getInteger(action_data, "Green? ");
    b = getInteger(action_data, "Blue? ");

    int width = action_data.getInputImage1().getWidth();
    int height = action_data.getInputImage1().getHeight();

    for( int i=0; i < height; i++ ) {
        for( int j=0; j < width; j++ ) {
            delRow = i - cenRow;
            delCol = j - cenCol;
            distance = std::sqrt((delRow * delRow) + (delCol * delCol));
            if(distance <= rad) {
                action_data.getInputImage1().setPixel(i, j, r,g,b);
            }
        }
    }
}
void drawBox(ActionData& action_data) {
    int tRow, bRow, lCol, rCol, r, g, b;
    int width = action_data.getInputImage1().getWidth();
    int height = action_data.getInputImage1().getHeight();

    tRow = getInteger(action_data, "Top Row? ");
    lCol = getInteger(action_data, "Left Column? ");
    bRow = getInteger(action_data, "Bottom Row? ");
    rCol = getInteger(action_data, "Right Column? ");

    r = getInteger(action_data, "Red? ");
    g = getInteger(action_data, "Green? ");
    b = getInteger(action_data, "Blue? ");


    for( int row=0; row < height; row++ ) {
        for( int col=0; col < width; col++ ) {
            if((row >= tRow) && (row <= bRow) && (col <= rCol) && (col >= lCol)) {
                action_data.getInputImage1().setPixel(row, col, r,g,b);
            }
        }
    }
}

void drawSquare(ActionData& action_data) {
    int mrow, mcol, r,g,b, height, width;
    double size, hsize;
    mrow = getInteger(action_data, "Row? ");
    mcol = getInteger(action_data, "Column? ");
    size = getDouble(action_data, "Size? ");
    r = getInteger(action_data, "Red? ");
    g = getInteger(action_data, "Green? ");
    b = getInteger(action_data, "Blue? ");
    height = action_data.getInputImage1().getHeight();
    width = action_data.getInputImage1().getWidth();
    hsize = size / 2;

    for( int row=0; row < height; row++ ) {
        for( int col=0; col < width; col++ ) {
            if((row >= mrow - hsize) && (row <= mrow + hsize) && (col <= mcol + hsize) && (col >= mcol - hsize)) {
                action_data.getInputImage1().setPixel(row, col, r,g,b);
            }
        }
    }
}


void configureGrid(ActionData& action_data) {
    int height, width, mcv;
    height = getInteger(action_data, "Grid Height? ");
    width = getInteger(action_data, "Grid Width? ");
    mcv = getInteger( action_data, "Grid Max Value? ");
    action_data.getGrid().setGridSize(height, width);
    action_data.getGrid().setMaxNumber(mcv);
}

void setGrid(ActionData& action_data) {
    int row, col, val;
    row = getInteger(action_data, "Grid Row? ");
    col = getInteger(action_data, "Grid Column? ");
    val = getInteger( action_data, "Grid Value? ");
    action_data.getGrid().setNumber(row, col, val);
}
void applyGrid(ActionData& action_data) {
    action_data.getGrid().setPPM(action_data.getOutputImage());
}

void setColorTableSize(ActionData& action_data) {
    int x = getInteger(action_data, "Size? ");
    action_data.getTable().setNumberOfColors(x);
}
void setColor(ActionData& action_data) {
    int x, y, z, q;
    x = getInteger(action_data, "Position? ");
    y = getInteger(action_data, "Red? ");
    z = getInteger(action_data, "Green? ");
    q = getInteger(action_data, "Blue? ");
    action_data.getTable()[x].setAllChannels(y,z,q);
}
void setRandomColor(ActionData& action_data) {
    int x;
    x = getInteger(action_data, "Position? ");
    action_data.getTable().setRandomColor(255, x);
}
void setColorGradient(ActionData& action_data) {
    int x, y, z, q, a, b, c, d;
    x = getInteger(action_data, "First position? ");
    y = getInteger(action_data, "First red? ");
    z = getInteger(action_data, "First green? ");
    q = getInteger(action_data, "First blue? ");
    a = getInteger(action_data, "Second position? ");
    b = getInteger(action_data, "Second red? ");
    c = getInteger(action_data, "Second green? ");
    d = getInteger(action_data, "Second blue? ");
    Color e(y,z,q);
    Color f(b,c,d);
    action_data.getTable().insertGradient(e,f,x,a);
}
void applyGridColorTable(ActionData& action_data) {
    action_data.getGrid().setPPM(action_data.getOutputImage(), action_data.getTable());
}

void setFractalPlaneSize(ActionData& action_data) {
    ComplexFractal *ptr = dynamic_cast< ComplexFractal* >( &action_data.getGrid() );
  if( ptr != 0 ) {
    double min_x = getDouble( action_data, "Min X? " );
    double max_x = getDouble( action_data, "Max X? " );
    double min_y = getDouble( action_data, "Min Y? " );
    double max_y = getDouble( action_data, "Max Y? " );
    ptr->setPlaneSize( min_x, max_x, min_y, max_y );
  } else {
    action_data.getOS() << "Not a ComplexFractal object. Can't set plane size." << std::endl;
  }
}
void calculateFractal(ActionData& action_data) {
    action_data.getGrid().calculateAllNumbers();
}

void setJuliaParameters(ActionData& action_data) {
    JuliaSet *ptr = dynamic_cast< JuliaSet* >( &action_data.getGrid() );
  if( ptr != 0 ) {
    double a = getDouble( action_data, "Parameter a? " );
    double b = getDouble( action_data, "Parameter b? " );
    ptr->setParameters( a, b);
  } else {
    action_data.getOS() << "Not a JuliaSet object. Can't set plane size." << std::endl;
  }
}