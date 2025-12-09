#include <iostream>
#include <iomanip>
using namespace std;

struct Process
{
    string name;
    int burst;
    int completion;
    int turnaround;
    int waiting;
};

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process p[n];

    cout << "Enter process name and burst time:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].name >> p[i].burst;
    }

    // Sort processes by Burst Time (SJF logic)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[j].burst < p[i].burst)
            {
                swap(p[i], p[j]);
            }
        }
    }

    int currentTime = 0;
    double totalTAT = 0, totalWT = 0;

    // Calculate Completion, TAT, WT
    for (int i = 0; i < n; i++)
    {
        p[i].completion = currentTime + p[i].burst;
        currentTime = p[i].completion;

        p[i].turnaround = p[i].completion; // since AT=0
        p[i].waiting = p[i].turnaround - p[i].burst;

        totalTAT += p[i].turnaround;
        totalWT += p[i].waiting;
    }

    // Print Gantt Chart
    cout << "\nGantt Chart:\n";
    cout << "-------------------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << "|   " << p[i].name << "   ";
    }
    cout << "|\n";
    cout << "-------------------------------------------------\n";
    cout << 0;
    for (int i = 0; i < n; i++)
    {
        cout << setw(8) << p[i].completion;
    }
    cout << "\n";

    // Print Process Table
    cout << "\nProcess\tBurst Time\tCompletion\tTurnaround\tWaiting\n";
    cout << "---------------------------------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].name << "\t"
             << p[i].burst << "\t\t"
             << p[i].completion << "\t\t"
             << p[i].turnaround << "\t\t"
             << p[i].waiting << "\n";
    }

    cout << "\nAverage Turnaround Time = " << fixed << setprecision(2) << (totalTAT / n);
    cout << "\nAverage Waiting Time = " << fixed << setprecision(2) << (totalWT / n) << "\n";

    return 0;
}
