// WAP to overload '>=' operator
#include <iostream>
using namespace std;
class demo
{
    int x;

public:
    void getdata()
    {
        cout << "Enter a number: ";
        cin >> x;
    }
    void showdata()
    {
        cout << x;
    }
    bool operator>=(demo b)
    {
        if (x >= b.x)
            return true;
        else
            return false;
    }
};
int main()
{
    demo aa, bb;
    aa.getdata();
    bb.getdata();
    aa.showdata();
    if (aa >= bb)
        cout << " is greater than or equal to ";
    else
        cout << " is less than ";
    bb.showdata();
}