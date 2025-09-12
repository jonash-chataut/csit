#include <iostream>
#include <iomanip>
using namespace std;

// function to check pagehit
bool isPageHit(int frames[], int n, int page)
{
    for (int i = 0; i < n; i++)
        if (frames[i] == page)
            return true;
    return false;
}

// function to get index of least used page
int getLRUPageIndex(int count[], int frameCount)
{
    int minIndex = 0;
    for (int i = 1; i < frameCount; i++)
    {
        if (count[i] < count[minIndex])
            minIndex = i;
    }
    return minIndex;
}

void printFrames(int frames[], int frame_size, int frame_occupied, bool page_hit)
{
    for (int i = 0; i < frame_size; i++)
    {
        if (i < frame_occupied)
            cout << setw(5) << frames[i];
        else
            cout << setw(5) << "-";
    }
    cout << setw(15) << (page_hit ? "Page Hit" : "Page Fault") << "\n";
}

void lru(int pages[], int np, int capacity)
{
    int frames[capacity];   // stores pages in frames
    int count[capacity];    // stores last used time for each frame
    int frame_occupied = 0; // how many frames currently occupied
    int pageFaults = 0;     // count page faults
    int time = 0;           // global counter to track usage

    // Initialize frames as empty (-1) and count as 0
    for (int i = 0; i < capacity; i++)
    {
        frames[i] = -1;
        count[i] = 0;
    }

    // Print headers for output table
    cout << "---------------------------------------------\n";
    cout << "--> Page Replacement Process (Using LRU) <--\n";
    cout << "---------------------------------------------\n";

    cout << setw(6) << left << "Page" << setw(5 * capacity) << left << "Frames" << "Status\n";

    for (int i = 0; i < np; i++)
    {
        int page = pages[i];
        cout << setw(6) << left << page;

        // Check if page is already in frames (page hit)
        bool page_hit = isPageHit(frames, frame_occupied, page);

        if (!page_hit)
        {
            // Page fault occurred so incrementing
            pageFaults++;

            if (frame_occupied < capacity)
            {
                // Still space in frames so adding page directly
                frames[frame_occupied] = page;
                count[frame_occupied] = time++; // record last used time
                frame_occupied++;
            }
            else
            {
                // Need to replace the LRU page
                int lruIndex = getLRUPageIndex(count, capacity);
                frames[lruIndex] = page;
                count[lruIndex] = time++;
            }
        }
        else
        {
            // Page hit: update last used time of that frame
            for (int j = 0; j < frame_occupied; j++)
            {
                if (frames[j] == page)
                {
                    count[j] = time++;
                    break;
                }
            }
        }

        // Print current state of frames and status
        printFrames(frames, capacity, frame_occupied, page_hit);
    }

    // Print stats
    cout << "\nTotal Page Faults: " << pageFaults << "\n";
    cout << "Page Fault Rate: " << fixed << setprecision(3) << (float)pageFaults / np << "\n";
    cout << "Total Page Hits: " << np - pageFaults << "\n";
    cout << "Page Hit Rate: " << fixed << setprecision(3) << (float)(np - pageFaults) / np << "\n";
}

int main()
{
    cout << "Complied by :- Jonash Chataut\n";
    int np, capacity;

    cout << "Enter the number of page requests: ";
    cin >> np;
    if (np <= 0)
    {
        cout << "Invalid number of page requests.\n";
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
        cout << "Invalid capacity.\n";
        return 0;
    }

    lru(pages, np, capacity);
    return 0;
}
