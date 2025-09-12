#include <iostream>
#include <iomanip>
using namespace std;

void bestFit(int blockSize[], int originalBlockSize[], int m, int processSize[], int n)
{
    int allocation[n];     // Stores block index for each process (-1 if not allocated)
    int holeAfterAlloc[n]; // Stores hole size immediately after allocation

    // Initialize arrays
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
        holeAfterAlloc[i] = -1;
    }

    // Allocate processes
    for (int i = 0; i < n; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
            holeAfterAlloc[i] = blockSize[bestIdx]; // store immediate hole
        }
    }

    // Showing output results
    cout << "\nProcess No.\tProcess Size\tBlock No.\tBlock Size\tHole Size\n";

    for (int i = 0; i < n; i++)
    {
        cout << setw(6) << i + 1 << "\t\t"
             << setw(6) << processSize[i] << "\t\t";
        if (allocation[i] != -1)
        {
            int b = allocation[i];
            cout << setw(5) << b + 1 << "\t\t" << setw(6) << originalBlockSize[b] << "\t\t" << setw(6) << holeAfterAlloc[i] << "\n"; // immediate hole size
        }
        else
        {
            cout << setw(5) << "NA" << "\t\t" << setw(6) << "-" << "\t\t" << setw(6) << "-" << "\n";
        }
    }
}

int main()
{
    cout << "Compiled by:- Jonash Chataut\n";
    cout << "<---- Best fit allocation ---->\n";
    int m, n;
    cout << "Enter number of memory blocks: ";
    cin >> m;

    int blockSize[m], originalBlockSize[m];
    cout << "Enter sizes of the " << m << " blocks:\n";
    for (int i = 0; i < m; i++)
    {
        cin >> blockSize[i];
        originalBlockSize[i] = blockSize[i];
    }
    cout << "Enter number of processes: ";
    cin >> n;
    int processSize[n];
    cout << "Enter sizes of the " << n << " processes:\n";
    for (int i = 0; i < n; i++)
        cin >> processSize[i];

    bestFit(blockSize, originalBlockSize, m, processSize, n);
    return 0;
}
