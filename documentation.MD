# Paralynx Documentation

## Overview

**Paralynx** is a simple, modern C++ multithreaded task execution engine.  
It demonstrates how to queue jobs, execute them concurrently using a thread pool, and profile their performance (latency and throughput).

---

## File-by-File Explanation

### 1. `Task.h`

Defines a **Task**:  
- `id`: A string identifier for the task.
- `work`: A `std::function<void()>` holding the code to execute.
- `created_at`: Timestamp when the task was created.

**Constructor:**  
Initializes all fields and records the creation time.

---

### 2. `TaskQueue.h` & `TaskQueue.cpp`

A **thread-safe queue** for tasks.

- `push(const Task&)`: Adds a task to the queue and notifies waiting threads.
- `pop()`: Waits for a task to be available, then returns it. Returns `std::nullopt` if stopped and empty.
- `stop()`: Signals all waiting threads to wake up and exit.

**Thread Safety:**  
Uses `std::mutex` and `std::condition_variable` to synchronize access.

---

### 3. `Profiler.h` & `Profiler.cpp`

Tracks **performance metrics**:

- `record_latency(std::chrono::nanoseconds)`: Records how long a task took.
- `average_latency_ms()`: Returns the average task latency in milliseconds.
- `throughput()`: Returns the number of completed tasks.

Uses a `std::vector` for latencies and an atomic counter for throughput.

---

### 4. `Worker.h` & `Worker.cpp`

A **worker thread** that pulls tasks from the queue and executes them.

- **Constructor:** Takes a reference to the shared `TaskQueue` and `Profiler`.
- `start()`: Launches the worker thread.
- `stop()`: Signals the thread to stop and joins it.
- `run()`: Main loop: pops tasks, executes them, and records latency.

**Thread Management:**  
Uses `std::thread` and `std::atomic<bool>` for safe start/stop.

---

### 5. `test_main.cpp`

A **demo/test program**:

- Creates a `TaskQueue`, `Profiler`, and several `Worker` threads.
- Starts all workers.
- Pushes 20 tasks into the queue, each simulating work by sleeping for a short time.
- Waits for a second, then stops all workers.
- Prints the average latency and throughput.

---

## How It Works

1. **Initialization:**  
   - Create a shared `TaskQueue` and `Profiler`.
   - Create and start several `Worker` threads.

2. **Task Submission:**  
   - Push tasks into the queue. Each task is a lambda (anonymous function) that simulates work.

3. **Task Execution:**  
   - Each `Worker` thread waits for tasks, executes them, and records how long they took.

4. **Profiling:**  
   - The `Profiler` collects timing data for each task.

5. **Shutdown:**  
   - After a delay, all workers are stopped, and the program prints performance stats.

---

## Key Concepts

- **Thread Pool:** Multiple worker threads process tasks concurrently.
- **Thread-Safe Queue:** Ensures safe access from multiple threads.
- **Profiling:** Measures and reports performance metrics.
- **Modern C++:** Uses smart pointers, `std::optional`, lambdas, and atomics.

---

## How To Rebuild

1. **Clone or copy the source files.**
2. **Ensure you have CMake and a C++17 compiler.**
3. **Build:**
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```
4. **Run:**
   ```sh
   ./test_main
   ```

---

## How To Extend

- Add more complex tasks.
- Increase the number of workers or tasks.
- Add more profiling (e.g., per-task breakdown).
- Implement dynamic thread pool resizing.

---

# End of Documentation