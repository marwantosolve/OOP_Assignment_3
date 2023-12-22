// File name: A3_SheetPb02_20220324.cpp
// Purpose: A Task Manger
// Author: Marwan Osama
// ID: 20220324
// Section: S17,18
// Date: 7/12/2023

#include <bits/stdc++.h>
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
using namespace std;

// Define a struct to represent a process
struct Process {
    string name;
    int pid;
    size_t memory_usage;
};

// Define a class to manage a list of processes
class ProcessList {
public:
    // Constructor and destructor
    ProcessList() = default;
    ~ProcessList() = default;

    // Load the list of processes
    void load_processes() {
        // Initialize the process entry structure
        PROCESSENTRY32 entry;
        entry.dwSize = sizeof(PROCESSENTRY32);

        // Create a snapshot of the system processes
        HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (Process32First(snapshot, &entry)) {
            do {
                // Create a Process object for each process in the snapshot
                Process process;
                process.name = entry.szExeFile;
                process.pid = entry.th32ProcessID;

                // Open the process to get memory information
                HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, process.pid);
                if (hProcess != NULL) {
                    // Get memory information and close the process handle
                    PROCESS_MEMORY_COUNTERS pmc;
                    if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc))) {
                        process.memory_usage = pmc.WorkingSetSize;
                    } else {
                        process.memory_usage = 0;
                    }
                    CloseHandle(hProcess);
                } else {
                    process.memory_usage = 0;
                }

                // Add the process to the list
                processes.push_back(process);
            } while (Process32Next(snapshot, &entry));
        }
        // Close the snapshot handle
        CloseHandle(snapshot);
    }

    // Display the processes sorted by name
    void display_processes_sorted_by_name() const {
        display_processes("name");
    }

    // Display the processes sorted by PID
    void display_processes_sorted_by_pid() const {
        display_processes("pid");
    }

    // Display the processes sorted by memory usage
    void display_processes_sorted_by_memory() const {
        display_processes("memory");
    }

    // Display the main menu to choose sorting criteria
    void display_menu() const {
        cout << "Choose sorting Method: \n";
        cout << "(1) Sort by Name \n";
        cout << "(2) Sort by PID \n";
        cout << "(3) Sort by Memory Usage \n";

        while (true) { // to handle the wrong input
            string c;
            cout << ">>";
            cin >> c;

            // Use if-else statements to determine the chosen sorting criteria
            if (c == "1") {
                display_processes_sorted_by_name();
                break;
            } else if (c == "2") {
                display_processes_sorted_by_pid();
                break;
            } else if (c == "3") {
                display_processes_sorted_by_memory();
                break;
            } else {
                cout << "Invalid choice!.. Choose (1), (2) or (3): \n";
            }
        }
    }

private:
    // Vector to store the list of processes
    vector<Process> processes;

    // Display the processes based on the specified sorting criteria
    void display_processes(const string& sort_by) const {
        // Create a copy of the processes vector for sorting
        vector<Process> sorted_processes = processes;

        // Use lambda functions for sorting based on different criteria
        if (sort_by == "name") {
            sort(sorted_processes.begin(), sorted_processes.end(),
                 [](const Process& a, const Process& b) {
                     return a.name < b.name;
                 });

        } else if (sort_by == "pid") {
            sort(sorted_processes.begin(), sorted_processes.end(),
                 [](const Process& a, const Process& b) {
                     return a.pid < b.pid;
                 });
        } else if (sort_by == "memory") {
            sort(sorted_processes.begin(), sorted_processes.end(),
                 [](const Process& a, const Process& b) {
                     return a.memory_usage < b.memory_usage;
                 });
        }

        // Display the sorted processes in a formatted table
        cout << "----------------------------------\n";
        cout << "| Name | PID | Memory Usage (KB) |\n";
        cout << "----------------------------------\n";

        for (const Process& process : sorted_processes) {
            // Convert memory usage to kilobytes
            double memory_usage_kb = process.memory_usage / 1024.0;
            // Display process information in the table
            cout << "| " << process.name << " | " << process.pid << " | " << memory_usage_kb << " |\n";
        }
        cout << "---------------------------------------------------------------------------------------------------\n";
    }
};

// Main function
int main() {
    // Create a ProcessList object
    ProcessList process_list;
    // Load the list of processes
    process_list.load_processes();
    // Display the main menu for sorting options
    process_list.display_menu(); // to display the process with wanted sorting method
    return 0;
}