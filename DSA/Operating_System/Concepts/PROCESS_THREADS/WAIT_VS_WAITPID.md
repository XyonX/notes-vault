Nice catch ⚡ this is one of those things that often confuses people. Let’s clear it step by step.

---

# 🔹 `wait()` in UNIX/Linux

- **`wait()` is a _blocking_ system call** by default.
    
- When a parent calls `wait()`, it **suspends execution** until one of its child processes finishes.
    
- Once the child terminates, `wait()` _returns_ with the child’s PID and exit status.
    

👉 So yes — **the parent actually waits (is paused)**. It’s not “just monitoring in parallel,” it’s blocked.

---

# 🔹 Behavior in Practice

### Example with Blocking `wait()`

```c
pid_t pid = fork();

if (pid == 0) {
    // Child
    sleep(5); // Child takes 5 seconds
    exit(0);
} else {
    // Parent
    printf("Parent: waiting for child...\n");
    wait(NULL); // BLOCKED until child exits
    printf("Parent: child finished, now I continue.\n");
}
```

- Parent will stop at `wait()` for ~5 seconds until the child finishes.
    
- Only after child exits does the parent resume.
    

---

# 🔹 Non-blocking version exists

If you don’t want the parent to block, you can use:

- `waitpid(child_pid, &status, WNOHANG)` → **non-blocking**.
    
    - If the child hasn’t finished yet, it returns `0` immediately.
        
    - Parent can keep doing other work and “poll” periodically.
        

### Example with Non-blocking `waitpid`

```c
pid_t pid = fork();

if (pid == 0) {
    sleep(5); 
    exit(0);
} else {
    int status;
    while (1) {
        pid_t result = waitpid(pid, &status, WNOHANG);
        if (result == 0) {
            printf("Parent: child still running, doing other work...\n");
            sleep(1);
        } else {
            printf("Parent: child finished, exit status=%d\n", WEXITSTATUS(status));
            break;
        }
    }
}
```

👉 Here parent **does not block** — it checks occasionally while continuing its own tasks.

---

# ✅ Summary

- **`wait()`** → blocking (parent stops until child exits).
    
- **`waitpid(..., WNOHANG)`** → non-blocking (parent keeps running, can check later).
    

---

Do you want me to also show how this differs in **Windows (WaitForSingleObject)**, so you see the parallel across OSes?