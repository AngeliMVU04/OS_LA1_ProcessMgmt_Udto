<<<<<<< HEAD
# OS_LA1_ProcessMgmt_Udto

## 🛠️ BUILD INSTRUCTIONS (VS Code with MinGW)

### Prerequisites
- Visual Studio Code installed
- MinGW installed and added to your system PATH
- Project folder structure:

### SCREENSHOTS











### TASK NOTES


### Task A – Creating a Single Child
- create_basic.c launches child_echo.exe using CreateProcess().
- The parent prints its own PID and waits for the child to finish.
- child_echo.c receives the parent PID as an argument and prints both its own PID and the parent’s.
- The parent then prints the child’s exit code.
- Confirms basic parent-child process creation and communication.


### Task B – Creating Two Children
- create_two_children.c spawns two child processes in parallel.
- Each child runs child_echo.exe and reports its PID.
- The parent waits for both children to finish using either WaitForMultipleObjects() or two separate waits.
- Demonstrates concurrent child creation and synchronization.


### Task C – Simulating exec()
- replace_sim.c launches a new process (e.g., cmd /c dir) and exits with the same code as that process.
- Mimics the behavior of exec() by replacing the parent’s role with the child’s output.
- Shows how a parent can delegate execution and propagate exit status.


### Task D – Managing Processes in PowerShell
- Run any parent program (e.g., create_basic.exe) and monitor child processes using:
Get-Process child_echo
- Terminate a child manually using:
Stop-Process -Id <PID>
- Compare normal vs forced termination:
- Normal: child exits cleanly, parent receives exit code.
- Forced: child is killed abruptly, may affect parent’s behavior.
- Reinforces manual process control and observation using PowerShell.
=======
# OS_LA1_ProcessMgmt_Udto
