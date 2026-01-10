## OS Roadmap

### Why Operating System Topics Are Commonly Asked in Product-Based Company Interviews

Product-based companies (like FAANG or similar tech giants) often include MCQ rounds in their hiring processes to assess candidates' foundational knowledge of operating systems (OS). These tests evaluate how well you understand core concepts that underpin software efficiency, resource management, and system reliability—critical for roles involving system design, backend development, or performance optimization. From analyzing various interview prep resources and question banks, OS questions frequently focus on real-world scenarios like multitasking, memory constraints, and concurrency issues. They test not just rote knowledge but the ability to reason about trade-offs, such as preemptive vs. non-preemptive scheduling or paging vs. segmentation.

The topics are drawn from common patterns in MCQs and interview questions across sites like GeeksforGeeks, InterviewBit, and Sanfoundry, which aggregate experiences from candidates at companies like Google, Amazon, Microsoft, and others. Questions emphasize practical implications, like handling deadlocks in multi-threaded applications or optimizing CPU utilization in high-load systems. Mastering these ensures you can explain why certain OS mechanisms prevent issues like thrashing or starvation.

### Full List of OS Topics to Study

Below is a comprehensive, categorized list of topics compiled from analyzed resources. Aim to study definitions, key differences (e.g., process vs. thread), algorithms (with examples and time complexities where applicable), advantages/disadvantages, and real-world applications. Practice MCQs on each, focusing on scenarios like "What happens during a page fault?" or "Which scheduling algorithm minimizes waiting time?" Resources like GeeksforGeeks quizzes or InterviewBit MCQs are excellent for drills.

#### 1. **Basics and Fundamentals**
   - Definition and purpose of an OS (intermediary between user/hardware, resource allocation).
   - Types of OS (batch, multi-programmed, time-sharing, distributed, real-time, embedded).
   - Kernel vs. user mode (dual-mode operation, privileged instructions).
   - System bootstrap process (POST, loading kernel).
   - Goals of OS (efficiency, convenience, resource management).
   - Issues without an OS (poor resource utilization, no error handling).
   - GUI vs. CLI interfaces.

#### 2. **Processes and Threads**
   - Process definition, states (new, ready, running, waiting, terminated), and lifecycle.
   - Process Control Block (PCB) components (registers, priority, quantum).
   - Zombie and orphan processes.
   - Threads: definition, types (user-level vs. kernel-level), benefits (responsiveness, parallelism).
   - Differences between process and thread (resource sharing, context switch time).
   - Multithreading models and advantages.
   - Context switching (saving/loading process state, overhead).

#### 3. **Process Scheduling**
   - CPU scheduling objectives (max throughput, min waiting/turnaround/response time, fairness).
   - Types: preemptive vs. non-preemptive.
   - Algorithms: FCFS (First-Come-First-Served), SJF (Shortest Job First), SRTF (Shortest Remaining Time First), Priority Scheduling, Round Robin (with quantum), Multi-Level Queue/Feedback.
   - Dispatcher role and dispatch latency.
   - Starvation, aging (solution to starvation), convoy effect.
   - Long-term, short-term, and medium-term schedulers.

#### 4. **Synchronization and Concurrency**
   - Critical section problem (mutual exclusion, progress, bounded waiting).
   - Solutions: Peterson's algorithm, semaphores (binary, counting), mutex.
   - Race conditions and synchronization needs.
   - Producer-consumer problem.
   - Monitors and condition variables.
   - Atomic operations.

#### 5. **Deadlocks**
   - Definition and necessary conditions (mutual exclusion, hold-and-wait, no preemption, circular wait).
   - Prevention, avoidance, detection, and recovery strategies.
   - Banker's algorithm.
   - Resource allocation graph.
   - Safe vs. unsafe states.

#### 6. **Memory Management**
   - Logical vs. physical address space, address binding (compile-time, load-time, execution-time).
   - Memory allocation: static vs. dynamic.
   - Fragmentation: internal vs. external, compaction as a solution.
   - Paging: page tables, frames, multi-level paging, PTBR (Page Table Base Register).
   - Segmentation: segments, advantages over paging.
   - Virtual memory: demand paging, page faults, page replacement algorithms (FIFO, LRU, Optimal).
   - Belady's anomaly (in FIFO).
   - Thrashing (causes, detection via CPU utilization, prevention via working-set model).
   - Swapping and overlays.
   - Locality of reference (temporal, spatial).

#### 7. **Interprocess Communication (IPC)**
   - Mechanisms: pipes, message queues, shared memory, sockets, signals.
   - Models: producer-consumer, client-server.
   - Advantages and use cases (data sharing, synchronization).

#### 8. **File and Storage Management**
   - File system structure (directories, attributes, operations).
   - File allocation methods (contiguous, linked, indexed).
   - Free space management (bitmaps, linked lists).
   - Disk scheduling algorithms (FCFS, SSTF, SCAN, LOOK).
   - RAID levels.

#### 9. **System Calls and I/O Management**
   - System calls: types (process control like fork/exec/wait, file manipulation, device management).
   - I/O operations: buffering, caching, spooling.
   - Device drivers and controllers.

#### 10. **Advanced Topics**
   - Multiprocessor and multicore systems (advantages, scheduling).
   - Real-time OS (hard vs. soft, applications like embedded systems).
   - Distributed OS (client-server, peer-to-peer models).
   - Security and protection (access control, authentication).
   - Caching and its levels.
   - Reentrancy in functions.

Study these by starting with basics, then moving to processes/memory (most frequent in MCQs), and practicing 50-100 questions per category. This covers ~90% of OS questions in product-based interviews based on the analyzed tests.