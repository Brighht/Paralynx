#pragma once
#include "Task.h"
#include <queue>
#include <mutex>
#include <condition_variable>
#include <optional>

class TaskQueue {
public:
    void push(const Task& task);
    std::optional<Task> pop();
    void stop();

private:
    std::queue<Task> queue_;
    std::mutex mutex_;
    std::condition_variable cv_;
    bool stopped_ = false;
};