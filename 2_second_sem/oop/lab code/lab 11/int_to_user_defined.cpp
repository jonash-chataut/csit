// WAP to convert int to user defined type [Convert 95 minutes into hours and minutes]
#include <iostream>
using namespace std;
class time
{
    int hour;
    int minute;

public:
    time(int t)
    {
        hour = t / 60;
        minute = t % 60;
    }
    void display()
    {
        cout << "The time is " << hour << "hrs and " << minute << "mins" << endl;
    }
};
int main()
{
    int x = 90;
    time t(x);
    t.display();
}