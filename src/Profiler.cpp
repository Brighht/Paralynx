#include "Profiler.h"

void Profiler::record_latency(std::chrono::nanoseconds latency) {
    std::lock_guard<std::mutex> lock(mutex_);
    latencies_.push_back(latency);
    ++completed_;
}

double Profiler::average_latency_ms() const {
    std::lock_guard<std::mutex> lock(mutex_);
    if (latencies_.empty()) return 0.0;
    auto total = std::chrono::nanoseconds(0);
    for (auto l : latencies_) total += l;
    return (double)total.count() / latencies_.size() / 1e6;
}

size_t Profiler::throughput() const {
    return completed_;
}