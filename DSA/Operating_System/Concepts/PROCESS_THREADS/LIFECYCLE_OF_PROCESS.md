Perfect — this is the **life cycle of a process** 💡.  
Let’s go step by step, with **creation → execution → termination**, and how **parent-child relationships** work.

---

# 🖥️ How a Process Spawns and Ends

---

## 1. **Process Creation**

In Unix-like systems (Linux, macOS, BSD):

- A process is created by another process using **`fork()`**.
    
- The new process is called the **child**, the existing one is the **parent**.
    
- The child gets:
    
    - A new **PID**.
        
    - A **copy** of the parent’s memory space (at first, using copy-on-write).
        
    - Inherits some resources (open file descriptors, environment, etc.).
        

👉 After `fork()`:

- Both parent and child are running the same code.
    
- `fork()` returns **0** in the child, and the **child’s PID** in the parent.
    

📌 Example:

```c
pid_t pid = fork();

if (pid == 0) {
    // Child code
} else {
    // Parent code
}
```

---

## 2. **Program Execution**

- The child often calls **`exec()`** after `fork()`.
    
- `exec()` replaces the child’s memory image with a new program (like running `ls`, `python`, etc.).
    
- Parent continues running its own code.
    

👉 `fork()` = “create a child.”  
👉 `exec()` = “make the child run a new program.”

---

## 3. **Parent–Child Relationship**

- The OS maintains a **process tree**.
    
    - Each process knows its **Parent PID (PPID)**.
        
    - Parent can manage child (wait, send signals, terminate).
        
- **Child inherits** some attributes:
    
    - File descriptors (so both may write to the same file).
        
    - Environment variables.
        
    - Scheduling priority (initially).
        

---

## 4. **Process Termination**

- A process ends by calling **`exit(status)`**.
    
- OS cleans up most of its resources (memory, open files, etc.).
    
- BUT the **exit status is kept in the PCB** until the parent collects it with `wait()` or `waitpid()`.
    
    - If parent collects it → child fully removed (no zombie).
        
    - If parent doesn’t → child becomes a **zombie**.
        

---

## 5. **Special Cases**

- **Zombie Process** → Child finished, parent didn’t `wait()`.
    
- **Orphan Process** → Parent finished first, child still running. Adopted by `init` (PID 1), which later reaps it.
    

---

# ⚡ Visual Diagram (Process Life Cycle)

```
Parent Process (PID 100)
    |
    | fork()
    v
Child Process (PID 101)
    |
    | exec("ls")
    v
Running "ls" program
    |
    | exit(status)
    v
Zombie (until parent calls wait())
    |
    | parent calls wait()
    v
Removed from process table
```

---

✅ **Summary**

- **Spawning** → Parent uses `fork()` to create a child.
    
- **Execution** → Child may run same code or replace itself with another program via `exec()`.
    
- **Relationship** → Parent manages child (waits, signals, etc.).
    
- **Ending** → Child calls `exit()`, becomes zombie until parent calls `wait()`.
    
- **If parent dies** → child becomes orphan, adopted by `init`.
    

---

👉 Would you like me to also explain **how this works in Windows (CreateProcess API)** so you can compare with the Unix/Linux model?