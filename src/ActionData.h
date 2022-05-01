#ifndef _ACTIONDATA_H_
#define _ACTIONDATA_H_
#include <iostream>
#include "PPM.h"
#include "JuliaSet.h"

class ActionData {
public:
    ActionData( std::istream& is, std::ostream& os );
    ~ActionData();
    std::istream& getIS();
    std::ostream& getOS();
    PPM& getInputImage1();
    PPM& getInputImage2();
    PPM& getOutputImage();
    bool getDone() const;
    void setDone();
    NumberGrid& getGrid();
    void setGrid(NumberGrid *grid);
    ColorTable& getTable();
protected:
    std::istream& mIs;
    std::ostream& mOs;
    PPM mInputImageOne;
    PPM mInputImageTwo;
    PPM mOutputImage;
    bool mHasQuit;
    NumberGrid *mNumberGrid;
    ColorTable mColors;
private:
};



#endif