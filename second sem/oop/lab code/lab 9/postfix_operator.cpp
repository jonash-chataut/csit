// WAP to overload -- (postfix) operator to descrease data members by 5.
#include <iostream>
using namespace std;
class decrement
{
    int n = 17;

public:
    decrement operator--(int)
    {
        decrement a;
        n = n - 5;
        a.n = n;
    }
    void show()
    {
        cout << n << endl;
    }
};
int main()
{
    decrement c1, c2;
    cout << "Before postfix operator" << endl
         << "Value of n is ";
    c1.show();
    cout << "After postfix operator" << endl
         << "Value of n is ";
    c2 = c1--;
    c2.show();
    return 0;
}