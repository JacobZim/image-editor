

#ifndef _THREADED_GRID_H_
#define _THREADED_GRID_H_
#include "ThreadedVector.h"
#include "NumberGrid.h"
#include <thread>
#include <exception>
#include <vector>
// #include <cslib>

class ThreadedGrid: public NumberGrid {
public:
    ThreadedGrid();
    ThreadedGrid(const int& height, const int& width);
    virtual ~ThreadedGrid();
    virtual void calculateAllNumbers();
    virtual void worker();
protected:
    ThreadedVector<int> m_task_list;
private:
};





#endif