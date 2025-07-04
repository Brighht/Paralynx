#pragma once
#include <functional>
#include <string>
#include <chrono>

struct Task {
    std::string id;
    std::function<void()> work;
    std::chrono::high_resolution_clock::time_point created_at;

    Task(const std::string& task_id, std::function<void()> task_work)
        : id(task_id), work(std::move(task_work)), created_at(std::chrono::high_resolution_clock::now()) {}
};