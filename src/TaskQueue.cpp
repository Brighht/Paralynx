#include "TaskQueue.h"

void TaskQueue::push(const Task& task) {
    std::lock_guard<std::mutex> lock(mutex_);
    queue_.push(task);
    cv_.notify_one();
}

std::optional<Task> TaskQueue::pop() {
    std::unique_lock<std::mutex> lock(mutex_);
    cv_.wait(lock, [&]{ return !queue_.empty() || stopped_; });
    if (queue_.empty()) return std::nullopt;
    Task t = queue_.front();
    queue_.pop();
    return t;
}

void TaskQueue::stop() {
    std::lock_guard<std::mutex> lock(mutex_);
    stopped_ = true;
    cv_.notify_all();
}