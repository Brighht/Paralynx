#include "TaskQueue.h"
#include "Worker.h"
#include "Profiler.h"
#include <iostream>
#include <thread>
#include <vector>
#include <memory>

int main() {
    TaskQueue queue;
    Profiler profiler;
    const int num_workers = 4;
    const int num_tasks = 20;

    std::vector<std::unique_ptr<Worker>> workers;
    for (int i = 0; i < num_workers; ++i)
        workers.push_back(std::make_unique<Worker>(queue, profiler));

    for (auto& w : workers) w->start();

    for (int i = 0; i < num_tasks; ++i) {
        queue.push(Task("task" + std::to_string(i), [i]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(10 + (i % 5) * 5));
        }));
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
    for (auto& w : workers) w->stop();

    std::cout << "Average latency: " << profiler.average_latency_ms() << " ms\n";
    std::cout << "Throughput: " << profiler.throughput() << " tasks\n";
    return 0;
}