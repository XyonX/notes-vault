## OS Deadlocks

Most Asked Questions from OS Deadlocks

### Most Asked Questions from OS Deadlocks

Based on common patterns from interview experiences at product-based companies like Google, Amazon, Microsoft, and others (aggregated from resources like GeeksforGeeks, InterviewBit, Sanfoundry, and Testbook), here are the most frequently asked questions on Deadlocks in Operating Systems (OS). These focus on definitions, conditions, prevention, avoidance, detection, and recovery. Questions often test understanding of scenarios where processes are blocked indefinitely and strategies to handle them, including algorithms like Banker's. I've included descriptive and MCQ formats with concise answers/explanations, drawn from real interview reports.

#### Descriptive Questions
1. **What is a deadlock in an operating system?**  
   A deadlock is a situation where two or more processes are unable to proceed because each is waiting for a resource held by another, leading to a standstill. It occurs in multiprogramming environments and can halt system progress.

2. **What are the necessary conditions for a deadlock to occur?**  
   The four Coffman conditions must hold: Mutual Exclusion (resources can't be shared), Hold and Wait (processes hold resources while waiting for others), No Preemption (resources can't be forcibly taken), and Circular Wait (processes form a cycle of waiting).

3. **Differentiate between deadlock prevention and deadlock avoidance.**  
   Prevention eliminates one of the Coffman conditions upfront (e.g., no hold and wait by allocating all resources at start). Avoidance dynamically checks requests to ensure safe states (e.g., using Banker's algorithm), allowing more flexibility but with runtime overhead.

4. **Explain the Banker's algorithm for deadlock avoidance.**  
   Banker's algorithm simulates resource allocation to check if granting a request leads to a safe state (where all processes can complete). It uses need, available, max, and allocation matrices to find a safe sequence, avoiding unsafe states.

5. **What is a resource allocation graph (RAG)? How does it help in deadlock detection?**  
   RAG is a directed graph with processes as circles and resources as squares; request edges (process to resource) and assignment edges (resource to process). A cycle indicates potential deadlock; if resources are single-instance, a cycle means deadlock.

6. **What is a safe state in deadlock avoidance?**  
   A safe state is one where there exists a sequence for allocating resources to all processes without deadlock. An unsafe state may lead to deadlock, but not necessarily.

7. **How can deadlocks be prevented? Give strategies.**  
   Strategies: Ensure no mutual exclusion (use shareable resources), no hold and wait (allocate all at once or release before requesting), allow preemption (take resources from waiting processes), or break circular wait (order resource requests numerically).

8. **Explain deadlock detection and recovery methods.**  
   Detection uses algorithms like wait-for graphs (cycle detection) or modified Banker's. Recovery: Preempt resources, rollback processes, or terminate one/more processes (e.g., by priority or cost).

9. **What is the difference between deadlock and starvation?**  
   Deadlock is a circular wait where no process proceeds; starvation is when a low-priority process waits indefinitely due to higher-priority ones, but others may progress.

10. **Can deadlock occur with a single resource? Explain.**  
    No, because circular wait requires at least two resources and processes. With one resource, it's just mutual exclusion and hold/wait, but no cycle.

#### MCQ-Style Questions
These are common in screening rounds; I've included options, correct answers, and brief explanations based on aggregated patterns.

11. **Which of the following is NOT a necessary condition for deadlock?**  
    Options: a) Mutual Exclusion, b) Hold and Wait, c) No Preemption, d) Starvation.  
    Answer: d) Starvation.  
    Explanation: Starvation is a different issue; the four conditions are mutual exclusion, hold and wait, no preemption, and circular wait.

12. **A system is in a safe state if?**  
    Options: a) The system can allocate resources to each process in some order and still avoid a deadlock, b) All processes are deadlocked, c) Resources are unlimited, d) Circular wait exists.  
    Answer: a) The system can allocate resources to each process in some order and still avoid a deadlock.  
    Explanation: Safe state ensures a finishing sequence exists for all processes.

13. **In resource allocation graph, a cycle always indicates?**  
    Options: a) Deadlock, b) Potential deadlock, c) Safe state, d) No deadlock.  
    Answer: b) Potential deadlock.  
    Explanation: For multiple-instance resources, a cycle may not mean deadlock; for single-instance, it does.

14. **The Banker's algorithm is used for?**  
    Options: a) Deadlock prevention, b) Deadlock avoidance, c) Deadlock detection, d) Deadlock recovery.  
    Answer: b) Deadlock avoidance.  
    Explanation: It checks requests to prevent unsafe states dynamically.

15. **Which strategy breaks the circular wait condition to prevent deadlock?**  
    Options: a) Resource ordering, b) Preemption, c) Hold and wait allowance, d) Mutual exclusion removal.  
    Answer: a) Resource ordering.  
    Explanation: Assigning a total order to resources prevents cycles by enforcing acquisition in sequence.

16. **If a resource-allocation graph has no cycle, then?**  
    Options: a) Deadlock exists, b) No deadlock, c) Unsafe state, d) Starvation.  
    Answer: b) No deadlock.  
    Explanation: Absence of cycle means no circular wait, so no deadlock.

17. **Which of the following is a deadlock recovery technique?**  
    Options: a) Process termination, b) Resource preemption, c) Rollback, d) All of these.  
    Answer: d) All of these.  
    Explanation: Recovery involves breaking the deadlock by terminating, preempting, or rolling back processes.

18. **A reusable resource is one that?**  
    Options: a) Can be used by one process at a time and is not depleted, b) Is depleted after use, c) Can be shared without limit, d) Causes deadlock always.  
    Answer: a) Can be used by one process at a time and is not depleted.  
    Explanation: Examples include printers; they contribute to deadlocks via mutual exclusion.

These questions cover ~80% of deadlock topics in interviews. Practice scenarios like dining philosophers or Banker's calculations, and refer to resources like GeeksforGeeks or Sanfoundry for variations.