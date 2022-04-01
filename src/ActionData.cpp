#include "ActionData.h"
#include <iostream>


ActionData::ActionData(std::istream& is, std::ostream& os):
    mIs(is), mOs(os), mHasQuit(false), mNumberGrid(0) {
}
ActionData::~ActionData() {
    if (mNumberGrid != 0) {
        delete mNumberGrid;
        mNumberGrid = 0;
    }
}
std::istream& ActionData::getIS() {
    return mIs;
}
std::ostream& ActionData::getOS() {
    return mOs;
}
PPM& ActionData::getInputImage1() {
    return mInputImageOne;
}
PPM& ActionData::getInputImage2() {
    return mInputImageTwo;
}
PPM& ActionData::getOutputImage() {
    return mOutputImage;
}
bool ActionData::getDone() const {
    return mHasQuit;
}
void ActionData::setDone() {
    mHasQuit = true;
}
NumberGrid& ActionData::getGrid() {
    return *mNumberGrid;
}
void ActionData::setGrid(NumberGrid *grid) {
    if (mNumberGrid != 0) {
        delete mNumberGrid;
    }
    mNumberGrid = grid;
}
