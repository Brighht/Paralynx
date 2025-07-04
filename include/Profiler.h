#pragma once
#include <atomic>
#include <chrono>
#include <mutex>
#include <vector>

class Profiler {
public:
    void record_latency(std::chrono::nanoseconds latency);
    double average_latency_ms() const;
    size_t throughput() const;

private:
    mutable std::mutex mutex_;
    std::vector<std::chrono::nanoseconds> latencies_;
    std::atomic<size_t> completed_{0};
};