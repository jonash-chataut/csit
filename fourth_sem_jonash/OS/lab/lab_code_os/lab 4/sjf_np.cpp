#include <iostream>
#include <iomanip>
using namespace std;

struct Process
{
    string name;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
    bool done;
};

int main()
{
    cout << "===================================" << endl;
    cout << "||     SJF Scheduling (NP)        ||" << endl;
    cout << "|| Compiled by :- Jonash Chataut  ||" << endl;
    cout << "===================================" << endl << endl;
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process p[n];
    cout << "Enter process name, arrival time, and burst time:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].name >> p[i].arrival >> p[i].burst;
        p[i].done = false;
    }

    int currentTime = 0, completed = 0;
    double totalTAT = 0, totalWT = 0;

    // Print Gantt Chart
    cout << "\nGantt Chart:\n";
    cout << "-------------------------------------------------\n";

    while (completed < n)
    {
        int idx = -1;
        int minBT = 1e9;

        // Find the shortest job among arrived processes
        for (int i = 0; i < n; i++)
        {
            if (!p[i].done && p[i].arrival <= currentTime)
            {
                if (p[i].burst < minBT)
                {
                    minBT = p[i].burst;
                    idx = i;
                }
            }
        }

        if (idx == -1)
        {
            currentTime++; // CPU idle
            continue;
        }

        cout << "|   " << p[idx].name << "   ";

        // Calculate times
        p[idx].completion = currentTime + p[idx].burst;
        currentTime = p[idx].completion;

        p[idx].turnaround = p[idx].completion - p[idx].arrival; // TAT = CT - AT
        p[idx].waiting = p[idx].turnaround - p[idx].burst;      // WT = TAT - BT

        totalTAT += p[idx].turnaround;
        totalWT += p[idx].waiting;

        p[idx].done = true;
        completed++;
    }

    cout << "|\n";
    cout << "-------------------------------------------------\n";

    // Print timeline
    currentTime = 0;
    cout << 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].done)
        {
            cout << setw(8) << p[i].completion;
        }
    }
    cout << "\n";

    // Print Process Table
    cout << "\nProcess\tAT\tBT\tCT\tTAT (CT-AT)\tWT (TAT-BT)\n";
    cout << "-------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].name << "\t"
             << p[i].arrival << "\t"
             << p[i].burst << "\t"
             << p[i].completion << "\t"
             << p[i].completion << " - " << p[i].arrival << " = " << p[i].turnaround << "\t"
             << p[i].turnaround << " - " << p[i].burst << " = " << p[i].waiting << "\n";
    }

    cout << "\nAverage Turnaround Time = " << fixed << setprecision(2) << (totalTAT / n);
    cout << "\nAverage Waiting Time = " << fixed << setprecision(2) << (totalWT / n) << "\n";

    return 0;
}
