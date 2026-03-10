// WAP to convert user defined to basic type. [Convert hour into minutes]
#include <iostream>
using namespace std;
class time
{
    int hour;
    int minute;

public:
    void get()
    {
        cout << "Enter the time in hours: ";
        cin >> hour;
        cout << "And the minutes: ";
        cin >> minute;
    }
    /* time()
     {
         hour=0;
         minute=0;
     } */
   operator int()
    {
        return (hour * 60 + minute);
    }

    /*int convert()
    {
        int m;
        m=hour*60+minute;
        return m;
    } */
};
int main()
{
    time t;
    t.get();
    int min = t;
    // or do as this
    // int min;
    // min=t;
    cout << "The time in minute is " << min << "minutes" << endl;
}