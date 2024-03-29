#ifndef _GLUTAPP_H_
#define _GLUTAPP_H_

#include "ActionData.h"
#include "MenuData.h"
#include <sstream>

class GlutApp {
public:
  GlutApp(int height, int width);
  void setSize(int height, int width);
  int getHeight() const;
  int getWidth() const;
  void display();

  void selectJulia();
  void selectMandelbrot();
  void selectComplexFractal();
  void configureGrid(int max);
  void juliaParameters(double a, double b);
  void fractalPlaneSize(double x_min, double x_max, double y_min, double y_max);
  void fractalCalculate();
  void gridApplyColorTable();

  void createJulia();
  void createJulia2();
  void createMandelbrot();
  void createMandelbrot2();
  void createComplexFractal();
  void createComplexFractal2();

  enum InteractionMode { IM_FRACTAL, IM_COLORTABLE };
  enum FractalMode { M_MANDELBROT, M_JULIA, M_COMPLEX };

  void displayColorTable();
  void setInteractionMode(InteractionMode mode);
  void setColorTable();
  void decreaseColorTableSize();
  void increaseColorTableSize();
  void zoomIn();
  void zoomOut();
  void moveLeft();
  void moveRight();
  void moveDown();
  void moveUp();
  void setFractalMode(FractalMode mode);
  void increaseMaxNumber();
  void decreaseMaxNumber();
  void setAB(int x, int y);
  void resetPlane();
  void createFractal();

  FractalMode getFractalMode();

  void copyOutputToInput1();
  void antiAlias(int reduction_count);
  void applyAntiAlias();
  void toggleAntiAlias();
  void increaseAntiAliasReductionCount();
  void decreaseAntiAliasReductionCount();

protected:
  int mHeight, mWidth;
  std::stringstream mInputStream;
  std::stringstream mOutputStream;
  ActionData mActionData;
  MenuData mMenuData;

  double mMinX, mMaxX, mMinY, mMaxY;
  double mA, mB;
  InteractionMode mInteractionMode;
  FractalMode mFractalMode;
  int mMaxNumber;
  Color mColor1;
  Color mColor2;
  int mNumColor;

  int mAntiAliasReductionCount;
  bool mAntiAlias;
};

#endif /* _GLUTAPP_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */