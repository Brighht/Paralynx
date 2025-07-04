#include "Worker.h"

Worker::Worker(TaskQueue& queue, Profiler& profiler)
    : queue_(queue), profiler_(profiler) {}

Worker::~Worker() {
    stop();
    if (thread_.joinable()) thread_.join();
}

void Worker::start() {
    running_ = true;
    thread_ = std::thread(&Worker::run, this);
}

void Worker::stop() {
    running_ = false;
    queue_.stop();
    if (thread_.joinable()) thread_.join();
}

void Worker::run() {
    while (running_) {
        auto task_opt = queue_.pop();
        if (task_opt) {
            auto start = std::chrono::high_resolution_clock::now();
            task_opt->work();
            auto end = std::chrono::high_resolution_clock::now();
            profiler_.record_latency(end - task_opt->created_at);
        } else {
            break;
        }
    }
}