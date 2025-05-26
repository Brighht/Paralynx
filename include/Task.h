#pragma once
#include <functional>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Task {
    string id;
    function<void()> work;
    high_resolution_clock::time_point created_at = high_resolution_clock::now();

    Task(const string& task_id, function<void()> task_work)
        : id(task_id), work(std::move(task_work)) {}
};