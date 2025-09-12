#include <iostream>
using namespace std;

int main()
{
    int n, m; // n = number of processes, m = number of resources
    cout << "===================================" << endl;
    cout << "||   Deadlock Detection Program   ||" << endl;
    cout << "|| Compiled by :- Jonash Chataut  ||" << endl;
    cout << "===================================" << endl
         << endl;

    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    int allocation[n][m], maxNeed[n][m], available[m];
    int need[n][m];

    cout << "\nEnter Allocation Matrix (" << n << "x" << m << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> allocation[i][j];

    cout << "\nEnter Max Matrix (" << n << "x" << m << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maxNeed[i][j];

    cout << "\nEnter Available Resources (" << m << " values):\n";
    for (int j = 0; j < m; j++)
        cin >> available[j];

    // Calculate Need matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = maxNeed[i][j] - allocation[i][j];
        }
    }

    // Work array = available
    int work[m];
    for (int j = 0; j < m; j++)
        work[j] = available[j];

    bool finish[n];
    for (int i = 0; i < n; i++)
        finish[i] = false;

    int safeSeq[n], count = 0;

    // Safety Algorithm
    bool found;
    while (count < n)
    {
        found = false;
        for (int i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                int j;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                        break;
                }
                if (j == m)
                {
                    // process i can be satisfied
                    for (int k = 0; k < m; k++)
                        work[k] += allocation[i][k];
                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found)
            break; // no process could be satisfied
    }

    // Check if system is safe
    if (count == n)
    {
        cout << "\nSystem is in a SAFE STATE." << endl;
        cout << "Safe Sequence: ";
        for (int i = 0; i < n; i++)
        {
            cout << "P" << safeSeq[i];
            if (i != n - 1)
                cout << " -> ";
        }
        cout << endl;
    }
    else
    {
        cout << "\nSystem is in DEADLOCK (Not Safe)." << endl;
    }

    return 0;
}
