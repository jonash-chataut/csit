#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int n, head, cylinders, seek = 0;
    cout << "===================================" << endl;
    cout << "||        FCFS Disk Scheduling    ||" << endl;
    cout << "|| Compiled by :- Jonash Chataut  ||" << endl;
    cout << "===================================" << endl
         << endl;

    cout << "Enter total number of cylinders: ";
    cin >> cylinders;
    cout << "Enter number of requests: ";
    cin >> n;

    int arr[n];
    cout << "Enter the request sequence: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter initial head position: ";
    cin >> head;

    int current = head;
    cout << "\nSeek Sequence with Movements:" << endl;
    for (int i = 0; i < n; i++)
    {
        int move = abs(current - arr[i]);
        cout << "Move from " << current << " -> " << arr[i] << " (Seek = " << move << ")" << endl;
        seek += move;
        current = arr[i];
    }

    // Print head movements 
    current = head;
    cout << "\nHead movements: " << current;
    for (int i = 0; i < n; i++)
        cout << " -> " << arr[i];

    cout << "\n\nTotal seek time = " << seek << endl;
    cout << "Average seek time = " << fixed << setprecision(2) << (float)seek / n << endl;

    return 0;
}
