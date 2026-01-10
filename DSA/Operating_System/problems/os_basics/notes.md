## OS Basics and Fundamentals

Most Asked Questions from OS Basics and Fundamentals

### Most Asked Questions from OS Basics and Fundamentals

Based on common patterns from interview preparation resources, here are the most frequently asked questions on basic and fundamental Operating System (OS) concepts. These are aggregated from popular sites and focus on introductory topics like definitions, types, purposes, kernel, and bootstrap processes. I've included questions in both descriptive and MCQ formats where applicable, along with concise answers/explanations for study purposes. These appear repeatedly in interviews for product-based companies, emphasizing conceptual understanding.

#### Descriptive Questions
1. **What is an operating system?**  
   An operating system is software that acts as an intermediary between the user and computer hardware, managing resources like memory, processing power, and I/O operations to provide an environment for executing programs conveniently and efficiently.

2. **What are the main purposes or goals of an operating system?**  
   The primary goals include providing a user-friendly environment for program execution, managing hardware resources efficiently, ensuring correct system operation, and preventing interference between user programs and the system. It also handles resource allocation, error detection, and security.

3. **What are the basic functions of an operating system?**  
   Key functions: memory and processor management, providing user interfaces (e.g., GUI/CLI), file and device management, resource/job scheduling, error detection, and security.

4. **What are the different types of operating systems?**  
   Types include: Batch OS (e.g., payroll systems), Multi-Programmed/Multitasking OS (e.g., Windows, UNIX), Time-Sharing OS (e.g., Multics), Distributed OS (e.g., LOCUS), and Real-Time OS (e.g., PSOS, VRTX).

5. **What is a kernel?**  
   The kernel is the core component of an OS that manages hardware operations, including memory and CPU time. It bridges applications and hardware using system calls and inter-process communication.

6. **What is the difference between kernel mode and user mode?**  
   Kernel mode (supervisor mode) allows direct hardware access for privileged operations like resource management. User mode restricts applications to prevent direct hardware interaction, relying on the kernel via system calls for safety and isolation.

7. **What are the different types of kernels?**  
   Monolithic Kernels: All services packaged in one module (e.g., larger size, poor maintainability). Microkernels: Modular approach where services are separate, improving maintainability and controlling code size.

8. **What is the system bootstrap process?**  
   Bootstrapping (or booting) involves running diagnostic tests (e.g., POST), configuring devices, and loading the bootloader to initialize the OS when the computer starts.

9. **What is a GUI in operating systems?**  
   Graphical User Interface (GUI) allows users to interact with the OS using visual elements like icons and windows, making it more user-friendly than command-line interfaces (CLI).

#### MCQ-Style Questions
These are common in initial screening rounds; I've included options, correct answers, and brief explanations based on aggregated patterns.

10. **To access the services of an operating system, the interface is provided by the?**  
    Options: a) System calls, b) API, c) Library, d) Assembly instructions.  
    Answer: a) System calls.  
    Explanation: System calls provide the interface for user programs to request OS services like I/O or process creation.

11. **Which of the following is a single-user operating system?**  
    Options: a) MS-DOS, b) UNIX, c) Windows NT, d) None of these.  
    Answer: a) MS-DOS.  
    Explanation: MS-DOS supports only one user at a time, unlike multi-user systems like UNIX.

12. **Which of the following is not an operating system?**  
    Options: a) Windows, b) Linux, c) Oracle, d) DOS.  
    Answer: c) Oracle.  
    Explanation: Oracle is a database management system, not an OS.

13. **UNIX is written in which language?**  
    Options: a) C, b) Assembly, c) Java, d) Python.  
    Answer: a) C.  
    Explanation: UNIX was primarily developed in C for portability.

14. **Which type of OS reads and reacts in terms of actual time?**  
    Options: a) Batch OS, b) Real-Time OS, c) Distributed OS, d) Time-Sharing OS.  
    Answer: b) Real-Time OS.  
    Explanation: Real-Time OS processes data with strict timing constraints, used in embedded systems.

These questions cover ~80% of basics asked in MCQ rounds or initial interviews. Practice by explaining them in your own words, and refer to resources like GeeksforGeeks or InterviewBit for more drills.


## TYPES OF OS


Here are the main types of operating systems
### 1. **Batch Operating System**
- Processes jobs in batches without user interaction
- Jobs are collected, grouped, and processed sequentially
- No direct communication between user and computer during execution
- Example: Early mainframe systems for payroll processing

### 2. **Time-Sharing Operating System**
- Allows multiple users to share CPU time simultaneously
- Rapidly switches between users giving each small time slices
- Provides interactive response to users
- Example: UNIX, Linux

### 3. **Multiprogramming/Multitasking Operating System**
- Multiprogramming: Keeps multiple programs in memory at once, improving CPU utilization
- Multitasking: Allows a single user to run multiple programs concurrently
- CPU switches between processes to give appearance of simultaneous execution
- Example: Windows, macOS, modern Linux distributions

### 4. **Real-Time Operating System (RTOS)**
- Designed to respond to events in a deterministic time frame
- Hard real-time: Critical deadlines must be met (e.g., medical devices)
- Soft real-time: Occasional deadline misses acceptable (e.g., multimedia)
- Example: VxWorks, QNX

### 5. **Distributed Operating System**
- Manages multiple independent computers as a single system
- Resources are shared across machines
- Provides high availability and fault tolerance
- Example: LOCUS, Amoeba

These main categories represent different approaches to resource management and user interaction in operating systems.