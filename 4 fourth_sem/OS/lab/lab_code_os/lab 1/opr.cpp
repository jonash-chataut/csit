#include <iostream>
#include <iomanip>
using namespace std;

bool search(int frames[], int n, int page)
{
    for (int i = 0; i < n; i++)
    {
        if (frames[i] == page)
            return true;
    }
    return false;
}

int predict(int ref_str[], int frames[], int refStrLen, int index, int frame_occupied)
{
    int result = -1;
    int farthest = index;

    for (int i = 0; i < frame_occupied; i++)
    {
        int j;
        for (j = index; j < refStrLen; j++)
        {
            if (frames[i] == ref_str[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    result = i;
                }
                break;
            }
        }
        if (j == refStrLen)
            return i;
    }
    return (result == -1) ? 0 : result;
}

void printFrames(int frames[], int frame_size, int frame_occupied, bool page_hit)
{
    for (int i = 0; i < frame_size; i++)
    {
        if (i < frame_occupied)
            cout << left << setw(5) << frames[i];
        else
            cout << left << setw(5) << "-";
    }
    cout << left << setw(15) << (page_hit ? "Page Hit" : "Page Fault") << "\n";
}

void optimalPage(int pages[], int np, int capacity)
{
    int frames[capacity];
    int frame_occupied = 0;
    int faults = 0;

    cout << "---------------------------------------------\n";
    cout << "--> Page Replacement Process (Using OPR) <--\n";
    cout << "---------------------------------------------\n";

    cout << setw(6) << left << "Page" << setw(5 * capacity) << left << "Frames" << "Status\n";

    cout << setw(6) << left << "----";
    for (int i = 0; i < capacity; i++)
        cout << setw(5) << "-----";
    cout << "------\n";

    for (int i = 0; i < np; i++)
    {
        int page = pages[i];
        cout << setw(6) << left << page;
        bool page_hit = false;

        if (search(frames, frame_occupied, page))
        {
            page_hit = true;
        }
        else
        {
            // Page fault
            faults++;
            if (frame_occupied < capacity)
            {
                frames[frame_occupied++] = page;
            }
            else
            {
                int pos = predict(pages, frames, np, i + 1, frame_occupied);
                frames[pos] = page;
            }
        }

        printFrames(frames, capacity, frame_occupied, page_hit);
    }

    cout << "\nTotal Page Faults: " << faults << "\n";
    cout << "Page Fault Rate: " << fixed << setprecision(3) << (float)faults / np << "\n";
    cout << "Total Page Hits: " << np - faults << "\n";
    cout << "Page Hit Rate: " << fixed << setprecision(3) << (float)(np - faults) / np << "\n";
}

int main()
{
    cout << "Complied by :- Jonash Chataut\n";
    int np, capacity;

    cout << "Enter the number of page requests: ";
    cin >> np;

    if (np <= 0)
    {
        cout << "Error: Invalid number of page requests.\n";
        return 0;
    }

    int pages[np];
    cout << "Enter the page requests: ";
    for (int i = 0; i < np; i++)
    {
        cin >> pages[i];
    }

    cout << "Enter the capacity of the frame: ";
    cin >> capacity;

    if (capacity <= 0)
    {
        cout << "Error: Invalid capacity.\n";
        return 0;
    }

    optimalPage(pages, np, capacity);

    return 0;
}
