#include <windows.h>
#include <stdio.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    DWORD exitCode;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Command to simulate exec() — runs 'dir' in a new shell
    char command[] = "cmd /c dir";

    // Create the new process
    if (!CreateProcess(NULL, command, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        printf("Failed to launch command. Error code: %lu\n", GetLastError());
        return 1;
    }

    // Wait for the process to finish
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Get the exit code of the spawned process
    if (!GetExitCodeProcess(pi.hProcess, &exitCode)) {
        printf("Failed to get exit code. Error code: %lu\n", GetLastError());
        exitCode = 1; // Default to error
    }

    // Clean up handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    // Exit with the same code as the spawned process
    return exitCode;
}