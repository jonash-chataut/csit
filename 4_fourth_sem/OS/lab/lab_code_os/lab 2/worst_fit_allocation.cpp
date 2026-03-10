#include <iostream>
#include <iomanip>
using namespace std;

void worstFit(int blockSize[], int originalBlockSize[], int m, int processSize[], int n)
{
    int allocation[n];     // Stores block index for each process (-1 if not allocated)
    int holeAfterAlloc[n]; // Stores hole size right after allocation

    // Initialize arrays
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
        holeAfterAlloc[i] = -1;
    }

    // Allocate processes
    for (int i = 0; i < n; i++)
    {
        int worstIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }
        if (worstIdx != -1)
        {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
            holeAfterAlloc[i] = blockSize[worstIdx]; // store hole size immediately
        }
    }

    // Output results
    cout << "\n"
         << left << setw(12) << "Process No." << setw(15) << "Process Size" << setw(12) << "Block No." << setw(15) << "Block Size" << "Hole Size\n";
    for (int i = 0; i < n; i++)
    {
        cout << left << setw(12) << i + 1
             << setw(15) << processSize[i];
        if (allocation[i] != -1)
        {
            int b = allocation[i];
            cout << setw(12) << b + 1 << setw(15) << originalBlockSize[b] << holeAfterAlloc[i] << "\n";
        }
        else
        {
            cout << setw(12) << "NA" << setw(15) << "-" << "-\n";
        }
    }
}

int main()
{
    cout << "Complied by:- Jonash Chataut\n";
    cout << "<---- Worst fit allocation ---->\n";
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

    worstFit(blockSize, originalBlockSize, m, processSize, n);

    return 0;
}
