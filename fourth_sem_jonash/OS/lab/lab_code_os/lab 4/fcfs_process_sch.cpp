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
};

void sortByArrival(Process p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].arrival > p[j + 1].arrival)
            {
                swap(p[j], p[j + 1]);
            }
        }
    }
}

int main()
{
    cout << "===================================" << endl;
    cout << "||       FCFS Scheduling          ||" << endl;
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
    }

    sortByArrival(p, n);

    int currentTime = 0;
    double totalTAT = 0, totalWT = 0;

    // Calculate CT, TAT, WT
    for (int i = 0; i < n; i++)
    {
        if (p[i].arrival > currentTime)
        {
            currentTime = p[i].arrival; // CPU idle
        }

        p[i].completion = currentTime + p[i].burst;
        currentTime = p[i].completion;

        p[i].turnaround = p[i].completion - p[i].arrival; // TAT = CT - AT
        p[i].waiting = p[i].turnaround - p[i].burst;      // WT = TAT - BT

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
    cout << p[0].arrival;
    for (int i = 0; i < n; i++)
    {
        cout << setw(8) << p[i].completion;
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
