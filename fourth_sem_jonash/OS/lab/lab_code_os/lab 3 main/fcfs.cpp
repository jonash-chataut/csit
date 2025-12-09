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
    printf("====================================\n");
    printf("||%16s", "FCFS");
    printf("%16s||\n", " ");
    printf("||%32s||\n", "Compiled by :- Jonash Chataut ");
    printf("====================================\n");

    int n;
    cout << "\nEnter number of processes: ";
    cin >> n;

    Process p[n];

    cout << "Enter process name and burst time:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].name >> p[i].burst;
    }

    int currentTime = 0;
    double totalTAT = 0, totalWT = 0;

    // Calculate Completion, TAT, WT
    for (int i = 0; i < n; i++)
    {
        p[i].completion = currentTime + p[i].burst;
        currentTime = p[i].completion;

        // Formulas
        p[i].turnaround = p[i].completion;           // TAT = CT - AT , here AT = 0
        p[i].waiting = p[i].turnaround - p[i].burst; // WT = TAT - BT

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

    // Print Process Table (with subtraction shown)
    cout << "\nProcess\tBT\tCT\tTAT (CT-AT)\tWT (TAT-BT)\n";
    cout << "---------------------------------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].name << "\t"
             << p[i].burst << "\t"
             << p[i].completion << "\t"
             << p[i].completion << " - 0 = " << p[i].turnaround << "\t"
             << p[i].turnaround << " - " << p[i].burst << " = " << p[i].waiting << "\n";
    }

    cout << "\nAverage Turnaround Time = " << fixed << setprecision(2) << (totalTAT / n);
    cout << "\nAverage Waiting Time = " << fixed << setprecision(2) << (totalWT / n) << "\n";

    return 0;
}
