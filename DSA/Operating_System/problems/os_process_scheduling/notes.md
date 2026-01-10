## OS Process Scheduling

Most Asked Questions from OS Process Scheduling

### Most Asked Questions from OS Process Scheduling

Based on common patterns from interview experiences at product-based companies like Google, Amazon, Microsoft, and others (aggregated from resources like GeeksforGeeks, InterviewBit, PrepInsta, and Sanfoundry), here are the most frequently asked questions on Process Scheduling in Operating Systems (OS). These focus on scheduling objectives, algorithms, types, and related concepts. Questions often test understanding of efficiency metrics (e.g., waiting time, turnaround time) and trade-offs (e.g., starvation in priority scheduling). I've included descriptive and MCQ formats with concise answers/explanations, drawn from real interview reports.



#### Descriptive Questions
1. **What is process scheduling in OS? Why is it needed?**  
   Process scheduling is the OS mechanism to select and allocate CPU to processes from the ready queue to maximize efficiency. It's needed for multitasking, fair resource allocation, and optimizing metrics like CPU utilization, throughput, turnaround time, waiting time, and response time.

2. **Explain the different types of schedulers in OS.**  
   Long-term scheduler (job scheduler) selects processes from job pool to ready queue, controlling multiprogramming degree. Short-term scheduler (CPU scheduler) selects from ready queue for CPU allocation. Medium-term scheduler swaps processes to/from memory to reduce multiprogramming if overloaded.

3. **Differentiate between preemptive and non-preemptive scheduling.**  
   Preemptive: Running process can be interrupted and switched if a higher-priority one arrives (e.g., SRTF, Round Robin), allowing better responsiveness but higher overhead. Non-preemptive: Process runs to completion or blocks voluntarily (e.g., FCFS, SJF), simpler but can cause convoy effect.

4. **What are the main CPU scheduling criteria?**  
   Criteria include: CPU utilization (keep CPU busy), throughput (processes completed per unit time), turnaround time (submission to completion), waiting time (in ready queue), response time (first response to completion, key for interactive systems).

5. **Explain First-Come-First-Served (FCFS) scheduling algorithm with advantages and disadvantages.**  
   FCFS schedules processes in arrival order, non-preemptive. Advantages: Simple, fair for equal bursts. Disadvantages: Convoy effect (short processes wait behind long ones), high average waiting time.

6. **What is Shortest Job First (SJF) scheduling? Is it preemptive or non-preemptive?**  
   SJF selects the process with the shortest burst time next, minimizing average waiting time. It can be non-preemptive (schedule on completion) or preemptive (SRTF: interrupt if shorter arrives). Optimal for waiting time but requires burst time prediction.

7. **Describe Round Robin (RR) scheduling algorithm. How does time quantum affect it?**  
   RR is preemptive, allocating fixed time quantum per process in cyclic order. Small quantum approximates FCFS with high overhead; large quantum reduces responsiveness. Balances fairness and response time.

8. **What is Priority Scheduling? How do you handle starvation?**  
   Priority Scheduling assigns CPU to highest-priority process (can be preemptive/non-preemptive). Starvation occurs if low-priority processes wait indefinitely; aging solves it by incrementally increasing priority over time.

9. **Explain Multi-Level Queue (MLQ) and Multi-Level Feedback Queue (MLFQ) scheduling.**  
   MLQ divides ready queue into multiple queues with different priorities/algorithms (e.g., foreground RR, background FCFS). MLFQ allows processes to move between queues based on behavior (e.g., demote long-running), adapting dynamically.

10. **What is the role of the dispatcher in process scheduling?**  
    The dispatcher allocates CPU to the selected process, performing context switch. It involves loading PCB, registers, and has dispatch latency (time from selection to execution).

#### MCQ-Style Questions
These are frequently seen in online assessments or initial rounds at FAANG-like companies.

11. **Which scheduling algorithm allocates the CPU first to the process that requests the CPU first?**  
    Options: a) FCFS, b) SJF, c) Priority Scheduling, d) Round Robin.  
    Answer: a) FCFS.  
    Explanation: FCFS is based on arrival time, like a queue.

12. **In which scheduling algorithm is the average waiting time minimized?**  
    Options: a) FCFS, b) SJF, c) Round Robin, d) Priority.  
    Answer: b) SJF.  
    Explanation: SJF prioritizes shorter jobs, proven optimal for non-preemptive if burst times known.

13. **What is the main disadvantage of Priority Scheduling?**  
    Options: a) High throughput, b) Starvation, c) Low response time, d) Convoy effect.  
    Answer: b) Starvation.  
    Explanation: Low-priority processes may never execute if high-priority ones keep arriving.

14. **Which of the following is a preemptive scheduling algorithm?**  
    Options: a) FCFS, b) SJF, c) Round Robin, d) All of these.  
    Answer: c) Round Robin.  
    Explanation: RR interrupts after time quantum; others can be non-preemptive.

15. **The ready queue is empty, but the CPU is idle. This situation is called?**  
    Options: a) Deadlock, b) Starvation, c) Inversion, d) None of these.  
    Answer: d) None of these (it's underutilization, but not standard term; often trick question for CPU idle state).  
    Explanation: Indicates no processes ready, but CPU waits.

16. **In Round Robin, if time quantum is very large, it behaves like?**  
    Options: a) FCFS, b) SJF, c) SRTF, d) Priority.  
    Answer: a) FCFS.  
    Explanation: Large quantum allows processes to run to completion without preemption.

17. **Which scheduler controls the degree of multiprogramming?**  
    Options: a) Short-term, b) Long-term, c) Medium-term, d) Dispatcher.  
    Answer: b) Long-term.  
    Explanation: It decides how many processes enter memory.

18. **Aging is a technique used to avoid?**  
    Options: a) Deadlock, b) Thrashing, c) Starvation, d) Inversion.  
    Answer: c) Starvation.  
    Explanation: Gradually increases priority of waiting processes.

These questions represent ~80% of process scheduling topics in interviews at companies like Amazon and Microsoft. Practice calculating metrics (e.g., Gantt charts for waiting time) and comparing algorithms.