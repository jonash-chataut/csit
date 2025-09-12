#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int n, head, cylinders, seek = 0;
    char direction;
    cout << "===================================" << endl;
    cout << "||        SCAN Disk Scheduling    ||" << endl;
    cout << "|| Compiled by :- Jonash Chataut  ||" << endl;
    cout << "===================================" << endl << endl;

    cout << "Enter total number of cylinders: ";
    cin >> cylinders;
    cout << "Enter number of requests: ";
    cin >> n;

    int arr[n], left[20], right[20];
    int lcount = 0, rcount = 0;

    cout << "Enter the request sequence: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter initial head position: ";
    cin >> head;

    cout << "Enter direction (L/R): ";
    cin >> direction;

    // Split requests
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < head)
            left[lcount++] = arr[i];
        else
            right[rcount++] = arr[i];
    }

    if (direction == 'L')
        left[lcount++] = 0;
    else
        right[rcount++] = cylinders - 1;

    // Sort arrays
    for (int i = 0; i < rcount - 1; i++)
        for (int j = i + 1; j < rcount; j++)
            if (right[i] > right[j])
                swap(right[i], right[j]);
    for (int i = 0; i < lcount - 1; i++)
        for (int j = i + 1; j < lcount; j++)
            if (left[i] < left[j])
                swap(left[i], left[j]);

    // Step-by-step movements
    cout << "\nSeek Sequence with Movements:" << endl;
    int current = head;
    int movement[n + 2], mcount = 0;
    if (direction == 'R')
    {
        for (int i = 0; i < rcount; i++)
        {
            int move = abs(current - right[i]);
            cout << "Move from " << current << " -> " << right[i] << " (Seek = " << move << ")" << endl;
            seek += move;
            current = right[i];
            movement[mcount++] = current;
        }
        for (int i = 0; i < lcount; i++)
        {
            int move = abs(current - left[i]);
            cout << "Move from " << current << " -> " << left[i] << " (Seek = " << move << ")" << endl;
            seek += move;
            current = left[i];
            movement[mcount++] = current;
        }
    }
    else
    {
        for (int i = lcount - 1; i >= 0; i--)
        {
            int move = abs(current - left[i]);
            cout << "Move from " << current << " -> " << left[i] << " (Seek = " << move << ")" << endl;
            seek += move;
            current = left[i];
            movement[mcount++] = current;
        }
        for (int i = 0; i < rcount; i++)
        {
            int move = abs(current - right[i]);
            cout << "Move from " << current << " -> " << right[i] << " (Seek = " << move << ")" << endl;
            seek += move;
            current = right[i];
            movement[mcount++] = current;
        }
    }

    // Head movements line
    cout << "\nHead movements: " << head;
    for (int i = 0; i < mcount; i++)
        cout << " -> " << movement[i];

    cout << "\n\nTotal seek time = " << seek << endl;
    cout << "Average seek time = " << fixed << setprecision(2) << (float)seek / n << endl;

    return 0;
}
