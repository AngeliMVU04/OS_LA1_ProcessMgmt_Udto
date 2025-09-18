#include <stdio.h>
#include <windows.h>

int main(int argc, char *argv[]) {
    DWORD pid = GetCurrentProcessId();
    DWORD ppid = argc > 1 ? atoi(argv[1]) : 0;
    printf("Child PID: %lu\n", pid);
    printf("Parent PID (passed): %lu\n", ppid);
    // Delay for 60 seconds so you can observe/control the process
    Sleep(60000); // 60000 milliseconds = 60 seconds
    return 0;
}