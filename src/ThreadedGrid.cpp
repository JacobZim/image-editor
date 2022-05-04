#include "ThreadedGrid.h"



ThreadedGrid::ThreadedGrid(): NumberGrid() {}
ThreadedGrid::ThreadedGrid(const int& height, const int& width):
NumberGrid(height, width) {}
ThreadedGrid::~ThreadedGrid() {}


void ThreadedGrid::calculateAllNumbers() {
    std::vector<std::thread> threads;

    unsigned int max_cores = std::thread::hardware_concurrency();
    unsigned int i;

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
        
        for (int i = 0; i < mWidth; i++ ) {
            for (int j = 0; j < mHeight; j++ ) {
                //setNumber(j, i, calculateNumber( j, i));
                setNumber(this_workers_tasks[0], j, calculateNumber(this_workers_tasks[0], j));
            }
        }

        //m_primes.push_back(this_workers_primes);
    }
}