#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

struct Process
{
    string name;
    int burst;
    int remaining;
    int completion;
    int turnaround;
    int waiting;
};

int main()
{
    printf("===================================\n");
    printf("||\t\tFCFS \t\t ||\n");
    printf("|| Complied by :- Jonash Chataut ||\n");
    printf("===================================\n");
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    Process p[n];

    cout << "Enter process name and burst time:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].name >> p[i].burst;
        p[i].remaining = p[i].burst;
        p[i].completion = 0;
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    queue<int> q;
    for (int i = 0; i < n; i++)
        q.push(i);

    int currentTime = 0;
    double totalTAT = 0, totalWT = 0;

    cout << "\nGantt Chart:\n";
    cout << "-------------------------------------------------\n";

    // RR Execution
    while (!q.empty())
    {
        int i = q.front();
        q.pop();

        if (p[i].remaining > tq)
        {
            cout << "|   " << p[i].name << "   ";
            currentTime += tq;
            p[i].remaining -= tq;
            q.push(i);
        }
        else if (p[i].remaining > 0)
        {
            cout << "|   " << p[i].name << "   ";
            currentTime += p[i].remaining;
            p[i].remaining = 0;
            p[i].completion = currentTime;
        }
    }

    cout << "|\n";
    cout << "-------------------------------------------------\n";

    // Print timeline
    currentTime = 0;
    cout << 0;
    for (int i = 0; i < n; i++)
        p[i].remaining = p[i].burst; // reset
    queue<int> q2;
    for (int i = 0; i < n; i++)
        q2.push(i);
    while (!q2.empty())
    {
        int i = q2.front();
        q2.pop();
        if (p[i].remaining > tq)
        {
            currentTime += tq;
            cout << setw(8) << currentTime;
            p[i].remaining -= tq;
            q2.push(i);
        }
        else if (p[i].remaining > 0)
        {
            currentTime += p[i].remaining;
            cout << setw(8) << currentTime;
            p[i].remaining = 0;
        }
    }
    cout << "\n";

    // Calculate TAT and WT
    for (int i = 0; i < n; i++)
    {
        p[i].turnaround = p[i].completion; // AT=0
        p[i].waiting = p[i].turnaround - p[i].burst;
        totalTAT += p[i].turnaround;
        totalWT += p[i].waiting;
    }

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
