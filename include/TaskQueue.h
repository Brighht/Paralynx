#pragma once
#include <queue>
#include <mutex>
#include "Task.h"

using namespace std;

class TaskQueue {
    private:
        queue<Task> queue_;
        mutable mutex mutex_;
    
    public:
        // Add A Task to the queue
        void push(const Task& task);

        //Remove and return the next task from the queue(copy for now)
        Task pop();

        bool isEmpty() const;
};