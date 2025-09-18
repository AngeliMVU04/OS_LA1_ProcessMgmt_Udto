#include <windows.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    DWORD parentPID = GetCurrentProcessId();
    printf("Parent PID: %lu\n", parentPID);

    // Command line to launch child_echo.exe with parent PID as argument
    char cmdLine[256];
    sprintf(cmdLine, "bin\\child_echo.exe %lu", parentPID);

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Create the child process
    if (!CreateProcess(
        NULL,       // Application name
        cmdLine,    // Command line
        NULL,       // Process security attributes
        NULL,       // Thread security attributes
        FALSE,      // Inherit handles
        0,          // Creation flags
        NULL,       // Environment
        NULL,       // Current directory
        &si,        // Startup info
        &pi))       // Process info
    {
        printf("CreateProcess failed (%lu).\n", GetLastError());
        return 1;
    }

    // Wait until child process exits
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Get the exit code
    DWORD exitCode;
    if (GetExitCodeProcess(pi.hProcess, &exitCode)) {
        printf("Child exited with code: %lu\n", exitCode);
    } else {
        printf("Failed to get exit code (%lu).\n", GetLastError());
    }

    // Close handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
