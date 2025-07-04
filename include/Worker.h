#pragma once
#include "TaskQueue.h"
#include "Profiler.h"
#include <thread>
#include <atomic>

class Worker {
public:
    Worker(TaskQueue& queue, Profiler& profiler);
    ~Worker();

    void start();
    void stop();

private:
    void run();

    TaskQueue& queue_;
    Profiler& profiler_;
    std::thread thread_;
    std::atomic<bool> running_{false};
};