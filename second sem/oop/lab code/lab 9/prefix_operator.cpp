// WAP to overload ++ (prefix) operator to increase data members by 2.
#include <iostream>
using namespace std;
class increment
{
    int n = 7;

public:
    increment operator++()
    {
        // increment a;
        // n = n + 2;
        // a.n = n;
        n=n+2;
    }
    void show()
    {
        cout << n << endl;
    }
};
int main()
{
    increment c1, c2;
    cout << "Before prefix operator" << endl
         << "Value of n is ";
    c1.show();
    cout << "After prefix operator" << endl
         << "Value of n is ";
    // c2 = ++c1;
    // c2.show();
    ++c1;
    c1.show();
    return 0;
}