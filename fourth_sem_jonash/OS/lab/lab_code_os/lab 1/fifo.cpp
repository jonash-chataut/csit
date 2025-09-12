#include <iostream>
#include <iomanip>
using namespace std;

int search(int frames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return i; // Page found in frame
        }
    }
    return -1; // Page not found in frame
}

void printFrames(int frames[], int n) {
    cout << "| ";
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1) {
            cout << "  | ";
        } else {
            cout << frames[i] << " | ";
        }
    }
    cout << "\n";
}

void fifo(int pages[], int n, int capacity) {
    int frames[capacity]; 
    int faults = 0;
    int nextFrame = 0; // Index of the next frame to be replaced

    // Initialize frames with -1 to indicate an empty frame
    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
    }

    cout << "Page Replacement Process (Using FIFO):\n";
    cout << "--------------------------\n";

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        cout << "Page Requested: " << page << "\n";

        if (search(frames, capacity, page) == -1) {
            // Page fault
            frames[nextFrame] = page;
            nextFrame = (nextFrame + 1) % capacity;
            faults++;
            cout << "Page Fault!\n";
        } else {
            cout << "Page Found in Frame ->(Page hit)\n";
        }

        printFrames(frames, capacity);
        cout << "--------------------------\n";
    }

    cout << "\nTotal Page Faults: " << faults << "\n";
    cout << "Page Fault Rate: "<< fixed << setprecision(3)  << (float)faults / n << "\n";
    cout << "Total Page Hits: " << n - faults << "\n";
    cout << "Page Hit Rate: " << fixed << setprecision(3) << (float)(n - faults) / n << "\n";
}

int main() {
    int np;        // Number of page requests
    int capacity; // Capacity of the frame

    cout << "Enter the number of page requests: ";
    cin >> np;

    if (np <= 0) {
        cout << "Error: Invalid number of page requests.\n";
        return 0;
    }

    int pages[np];
    cout << "Enter the page requests: ";
    for (int i = 0; i < np; i++) {
        cin >> pages[i];
    }

    cout << "Enter the capacity of the frame: ";
    cin >> capacity;

    if (capacity <= 0) {
        cout << "Error: Invalid capacity.\n";
        return 0;
    }

    fifo(pages, np, capacity);

    return 0;
}
