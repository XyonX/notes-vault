interrupt are signal that cause cpu to show doing whatever its doing and switch to a special routing called isr (interrupt service routine ) in kernal mode

system calls are softwaare generated interrupts that lets the user programme request os service 

interrupts have priority if no interrupt routeirng is running a new interruopt will cause the os or cpu to execute it immediately but if there is other isr is being executed and its priority is higher than the curretnly being executed isr it will switch to executing this new one 

if interrupt nesting is enabkles then any new interrupt maycause the executing interrupt to oause and new interrupt to be executed 

