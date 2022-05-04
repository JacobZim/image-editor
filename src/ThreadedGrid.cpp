#include "ThreadedGrid.h"


ThreadedGrid::ThreadedGrid(): NumberGrid(), m_task_list() {
}
ThreadedGrid::ThreadedGrid(const int& height, const int& width):
NumberGrid(height, width),  m_task_list() {}
ThreadedGrid::~ThreadedGrid() {}


void ThreadedGrid::calculateAllNumbers() {
    std::vector<std::thread> threads;

    unsigned int max_cores = std::thread::hardware_concurrency();
    unsigned int i;
    for (int j = 0; j < mHeight * mWidth; j++ ) {
        m_task_list.push_back(j);
    }

    for(i = 0; i < max_cores-1; i++) {
        threads.push_back(std::thread(&ThreadedGrid::worker, this));
    }

    for(i = 0; i < threads.size(); i++) {
        threads[i].join();
    }
}
void ThreadedGrid::worker() {
    std::vector<int> this_workers_tasks;

    while(!m_task_list.empty()) {
        //this_workers_tasks.resize(0);
        //this_workers_primes.resize(0);
        this_workers_tasks.clear();
        m_task_list.pop_back(this_workers_tasks, 1);
        int t;
        for (unsigned int i = 0; i < this_workers_tasks.size(); i++ ) {
            //setNumber(j, i, calculateNumber( j, i));
            t = this_workers_tasks[i];
            setNumber((t / mWidth), t % mWidth, calculateNumber((t / mWidth) , t % mWidth));
        }

        //m_primes.push_back(this_workers_primes);
    }
}