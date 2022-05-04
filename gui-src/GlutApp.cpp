#include "GlutApp.h"
#include "glut_app.h"
#include "image_menu.h"

GlutApp::GlutApp(int height, int width)
  : mHeight(height), mWidth(width), mActionData(mInputStream, mOutputStream), mMinX(-2.0), mMaxX(2.0), mMinY(-2.0), mMaxY(2.0),
  mInteractionMode(IM_FRACTAL), mFractalMode(M_MANDELBROT), mMaxNumber(200), mColor1(255, 255, 25), mColor2(255, 25, 255), mNumColor(32) {
  configureMenu(mMenuData);
  mActionData.setGrid(new ComplexFractal);
  setColorTable();
  createFractal();
}

void GlutApp::setSize(int height, int width) {
  mHeight = height;
  mWidth = width;
}

int GlutApp::getHeight() const {
  return mHeight;
}
int GlutApp::getWidth() const {
  return mWidth;
}

void GlutApp::display() {
    if (mInteractionMode == IM_FRACTAL) {
        PPM& p = mActionData.getOutputImage();
        double max = static_cast<double>(p.getMaxColorValue());
        double r, g, b;
        int row, column;
        glBegin( GL_POINTS );
        for(row = 0; row < p.getHeight(); row++) {
            for(column = 0; column < p.getWidth(); column++) {
            r = p.getChannel(row, column, 0) / max;
            g = p.getChannel(row, column, 1) / max;
            b = p.getChannel(row, column, 2) / max;
            glColor3d(r, g, b);
            glVertex2i(column, p.getHeight()-row-1);
            }
        }
        glEnd( );
    } else if (mInteractionMode == IM_COLORTABLE) {
        displayColorTable();
    }
}

/*
void GlutApp::createJulia() {

    // julia
    mOutputStream.clear();
    mOutputStream.str("");
    mInputStream.clear();
    mInputStream.str("");
    takeAction("julia", mMenuData, mActionData);
    
    // grid
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    {
        std::stringstream tmp;
        tmp << mHeight << " " << mWidth << " " << 200;
        mInputStream.str(tmp.str());
    }
    takeAction("grid", mMenuData, mActionData);

    // julia-parameters
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    {
        std::stringstream tmp;
        tmp << 0.45 << " " << -0.32;
        mInputStream.str(tmp.str());
    }
    takeAction("julia-parameters", mMenuData, mActionData);

    // fractal-plane-size
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    {
        std::stringstream tmp;
        tmp << -2.0 << " " << 2.0 << " "<< -2.0 << " " << 2.0;
        mInputStream.str(tmp.str());
    }
    takeAction("fractal-plane-size", mMenuData, mActionData);

    
    // fractal-calculate
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    takeAction("fractal-calculate", mMenuData, mActionData);

    // grid-apply-color-table
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    takeAction("grid-apply-color-table", mMenuData, mActionData);
} */


void GlutApp::selectJulia() {
    // julia
    mOutputStream.clear();
    mOutputStream.str("");
    mInputStream.clear();
    mInputStream.str("");
    takeAction("julia", mMenuData, mActionData);
}
void GlutApp::selectMandelbrot() {
    //mandelbrot
    mOutputStream.clear();
    mOutputStream.str("");
    mInputStream.clear();
    mInputStream.str("");
    takeAction("mandelbrot", mMenuData, mActionData);
}
void GlutApp::selectComplexFractal() {
    //complexFractal
    mOutputStream.clear();
    mOutputStream.str("");
    mInputStream.clear();
    mInputStream.str("");
    takeAction("complex-fractal", mMenuData, mActionData);
}
void GlutApp::configureGrid(int max) {
    // grid
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    {
        std::stringstream tmp;
        tmp << mHeight << " " << mWidth << " " << max;
        mInputStream.str(tmp.str());
    }
    takeAction("grid", mMenuData, mActionData);
}
void GlutApp::juliaParameters(double a, double b) {
    // julia-parameters
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    {
        std::stringstream tmp;
        tmp << a << " " << b;
        mInputStream.str(tmp.str());
    }
    takeAction("julia-parameters", mMenuData, mActionData);
}
void GlutApp::fractalPlaneSize(double x_min, double x_max, double y_min, double y_max) {
    // fractal-plane-size
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    {
        std::stringstream tmp;
        tmp << x_min << " " << x_max << " "<< y_min << " " << y_max;
        mInputStream.str(tmp.str());
    }
    takeAction("fractal-plane-size", mMenuData, mActionData);
}
void GlutApp::fractalCalculate() {
    // fractal-calculate
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    takeAction("fractal-calculate", mMenuData, mActionData);
}
void GlutApp::gridApplyColorTable() {
    // grid-apply-color-table
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    
    takeAction("grid-apply-color-table", mMenuData, mActionData);
}



void GlutApp::createJulia() {
    selectJulia();
    configureGrid(200);
    juliaParameters(0.45, -0.31);
    fractalPlaneSize(-1.0, 1.0, -1.25, 1.25);
    fractalCalculate();
    gridApplyColorTable();
}

void GlutApp::createJulia2() {
    selectJulia();
    configureGrid(200);
    fractalPlaneSize(-1.5, 1.5, -1.0, 1.0);
    juliaParameters(-0.714, -0.271);
    fractalCalculate();
    gridApplyColorTable();
}
void GlutApp::createMandelbrot() {
    selectMandelbrot();
    configureGrid(200);
    fractalPlaneSize(-0.4, 0.15, 0.5, 1.20);
    fractalCalculate();
    gridApplyColorTable();
}
void GlutApp::createMandelbrot2() {
    selectMandelbrot();
    configureGrid(200);
    fractalPlaneSize(-2.0, 0.5, -1.1, 1.1);
    fractalCalculate();
    gridApplyColorTable();
}
void GlutApp::createComplexFractal() {
    selectComplexFractal();
    configureGrid(175);
    fractalPlaneSize(-2.0, 2.0, -2.0, 2.0);
    fractalCalculate();
    gridApplyColorTable();
}
void GlutApp::createComplexFractal2() {
    selectComplexFractal();
    configureGrid(300);
    fractalPlaneSize(0.25, 0.70, -0.20, 0.20);
    fractalCalculate();
    gridApplyColorTable();
}



void GlutApp::displayColorTable() {
    glBegin( GL_POINTS );
    for (int row = 0; row < mHeight; row++ ) {
        for (int column = 0; column< mWidth; column++ ) {
            int x = column * mNumColor / (mWidth * 2);
            Color tmp = mActionData.getTable()[x];
            glColor3d(tmp.getRed()/255.0, tmp.getGreen()/255.0, tmp.getBlue()/255.0);
            glVertex2i(column, row);
        }
    } 
    glEnd( );
}
void GlutApp::setInteractionMode(InteractionMode mode) {
    mInteractionMode = mode;
}
void GlutApp::setColorTable() {
    //set-color-table-size
    mOutputStream.clear();
    mInputStream.clear();
    mOutputStream.str("");
    mInputStream.str("");
    {
        std::stringstream tmp;
        tmp << mNumColor;
        mInputStream.str(tmp.str());
    } 
    takeAction("set-color-table-size", mMenuData, mActionData);

    //set-color-gradient
    mInputStream.clear();
    mOutputStream.clear();
    mInputStream.str("");
    mOutputStream.str("");
    int pos2 = mNumColor - 1;
    {
        std::stringstream tmp;
        tmp << 0 << " " << mColor1.getRed() << " " << mColor1.getGreen() << " " << mColor1.getBlue() << " " << pos2 << " " << mColor2.getRed() << " " << mColor2.getGreen() << " " << mColor2.getBlue();
        mInputStream.str(tmp.str());
    } 
    takeAction("set-color-gradient", mMenuData, mActionData);
}
void GlutApp::decreaseColorTableSize() {
    if (mNumColor > 10) {
        mNumColor = mNumColor / 1.1;

        setColorTable();
        gridApplyColorTable();
    }
}
void GlutApp::increaseColorTableSize() {
    if (mNumColor < 1024) {
        mNumColor = mNumColor * 1.1;

        setColorTable();
        gridApplyColorTable();
    }
}
void GlutApp::zoomIn() {
    double dx = (1.0 - 0.9) * (mMaxX - mMinX) / 2.0;
    double dy = (1.0 - 0.9) * (mMaxY - mMinY) / 2.0;
    mMinX += dx;
    mMaxX -= dx;
    mMinY += dy;
    mMaxY -= dy;
}
void GlutApp::zoomOut() {
    double dx = (1.0 - 0.9) * (mMaxX - mMinX) / 2.0;
    double dy = (1.0 - 0.9) * (mMaxY - mMinY) / 2.0;
    mMinX -= dx;
    mMaxX += dx;
    mMinY -= dy;
    mMaxY += dy;
}
void GlutApp::moveLeft() {
    double dx = (1.0 - 0.9) * (mMaxX-mMinX) / 2.0;
    if ( (mMinX - dx) >= -2.0 ) {
        mMinX -= dx;
        mMaxX -= dx;
    }
}
void GlutApp::moveRight() {
    double dx = (1.0 - 0.9) * (mMaxX-mMinX) / 2.0;
    if ( (mMaxX + dx) <= 2.0 ) {
        mMinX += dx;
        mMaxX += dx;
    }
}
void GlutApp::moveDown() {
    double dy = (1.0 - 0.9) * (mMaxY-mMinY) / 2.0;
    if ( (mMinY - dy) >= -2.0 ) {
        mMinY -= dy;
        mMaxY -= dy;
    }
}
void GlutApp::moveUp() {
    double dy = (1.0 - 0.9) * (mMaxY-mMinY) / 2.0;
    if ( (mMaxY + dy) <= 2.0 ) {
        mMinY += dy;
        mMaxY += dy;
    }
}
void GlutApp::setFractalMode(FractalMode mode) {
    mFractalMode = mode;
}
void GlutApp::increaseMaxNumber() {
    if (mMaxNumber < 2048 ) {
        mMaxNumber *= 1.1;
    }
}
void GlutApp::decreaseMaxNumber() {
    if (mMaxNumber > 11 ) {
        mMaxNumber /= 1.1;
    }
}
void GlutApp::setAB(int x, int y) {
    ComplexFractal *ptr = dynamic_cast< ComplexFractal* >( &mActionData.getGrid() );
    
    if ((mFractalMode == M_MANDELBROT) && (ptr != 0)) {
        double delta_x = ptr->getDeltaX();
        double delta_y = ptr->getDeltaY();
        mA = mMinX + x * delta_x;
        mB = mMinY + y * delta_y;
    }
}
void GlutApp::resetPlane() {
    mMinX = -2.0;
    mMaxX = 2.0;
    mMinY = -2.0;
    mMaxY = 2.0;
}
void GlutApp::createFractal() {
    if (mFractalMode == M_MANDELBROT) {
        selectMandelbrot();
    } else if (mFractalMode == M_JULIA) {
        selectJulia();
        juliaParameters(mA, mB);
    } else if (mFractalMode == M_COMPLEX) {
        selectComplexFractal();
    }
    configureGrid(mMaxNumber);
    fractalPlaneSize(mMinX, mMaxX, mMinY, mMaxY);
    fractalCalculate();
    gridApplyColorTable();
}


GlutApp::FractalMode GlutApp::getFractalMode() {
    return mFractalMode;
}