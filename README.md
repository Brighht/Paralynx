# Paralynx

**Paralynx** is a blazing-fast, modern C++ task execution engine with real-time profiling.

- **Thread pool**: Multiple workers execute queued jobs concurrently.
- **Thread-safe queue**: Robust, lock-protected task management.
- **Profiler**: Tracks latency and throughput for every job.

## Quick Start

```sh
git clone <https://github.com/Brighht/Paralynx>
cd Paralynx
mkdir build && cd build
cmake ..
make
./test_main
```

## Example Output

```
Average latency: 58.2 ms
Throughput: 20 tasks
```

## How it works

1. You define tasks as lambdas or functions.
2. Push them to the queue.
3. Workers pick up and execute tasks in parallel.
4. Profiler reports performance metrics.

## Extend

- Add more workers or tasks.
- Plug in your own job logic.
- Use the profiler to tune your system.

---

**Read `documentation.md` for a deep dive.**

---

10x your backend concurrency with Paralynx.
