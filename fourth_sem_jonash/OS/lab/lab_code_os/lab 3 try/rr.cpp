#include <iostream>
#include <iomanip>
using namespace std;

struct Process
{
    string name;
    int arrival;
    int burst;
    int remaining; // Remaining burst time
    int completion;
    int turnaround;
    int waiting;
};

int main()
{
    cout << "===================================" << endl;
    cout << "||     Round Robin Scheduling     ||" << endl;
    cout << "|| Compiled by :- Jonash Chataut  ||" << endl;
    cout << "===================================" << endl << endl;
    int n, quantum;
    cout << "Enter number of processes: ";
    cin >> n;

    Process p[n];
    cout << "Enter process name, arrival time, and burst time:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].name >> p[i].arrival >> p[i].burst;
        p[i].remaining = p[i].burst;
        p[i].completion = 0;
    }

    cout << "Enter Time Quantum: ";
    cin >> quantum;

    int currentTime = 0, completed = 0;
    double totalTAT = 0, totalWT = 0;

    cout << "\nGantt Chart:\n";
    cout << "-------------------------------------------------\n";

    // RR Scheduling
    while (completed < n)
    {
        bool idle = true;
        for (int i = 0; i < n; i++)
        {
            if (p[i].remaining > 0 && p[i].arrival <= currentTime)
            {
                idle = false;
                cout << "| " << setw(4) << left << p[i].name << " ";

                if (p[i].remaining <= quantum)
                {
                    currentTime += p[i].remaining;
                    p[i].completion = currentTime;
                    p[i].remaining = 0;
                    completed++;
                }
                else
                {
                    currentTime += quantum;
                    p[i].remaining -= quantum;
                }
            }
        }
        if (idle)
        {
            cout << "| IDLE ";
            currentTime++;
        }
    }
    cout << "|\n";
    cout << "-------------------------------------------------\n";

    // Print Timeline
    cout << "Timeline:\n0";
    currentTime = 0;
    int temp[n];
    for (int i = 0; i < n; i++)
        temp[i] = p[i].burst;

    completed = 0;
    while (completed < n)
    {
        bool idle = true;
        for (int i = 0; i < n; i++)
        {
            if (temp[i] > 0 && p[i].arrival <= currentTime)
            {
                idle = false;
                if (temp[i] <= quantum)
                {
                    currentTime += temp[i];
                    temp[i] = 0;
                    completed++;
                }
                else
                {
                    currentTime += quantum;
                    temp[i] -= quantum;
                }
                cout << setw(5) << currentTime;
            }
        }
        if (idle)
            currentTime++;
    }

    // Print Process Table with calculations
    cout << "\n\nProcess\tAT\tBT\tCT\tTAT (CT-AT)\tWT (TAT-BT)\n";
    cout << "-------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;
        totalTAT += p[i].turnaround;
        totalWT += p[i].waiting;

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
