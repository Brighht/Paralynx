#include "TaskQueue.h"
#include <stdexcept> 

void TaskQueue::push(const Task& task) {
    std::lock_guard<std::mutex> lock(mutex_);
    queue_.push(task);
}

Task TaskQueue::pop() {
    std::lock_guard<std::mutex> lock(mutex_);

    if (queue_.empty()) {
        throw std::runtime_error("Attempted to pop from an empty queue");
    }

    Task task = queue_.front();
    queue_.pop();
    return task;
}

bool TaskQueue::isEmpty() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return queue_.empty();
}
