//WAP to demonstrate friend class to swap numbers of two classes.
#include <iostream>
using namespace std;
class two;
class one
{
    int n;

public:
    one()
    {
        cout << "Enter the first number ";
        cin >> n;
    }
    friend void swap(one n1, two n2);
};
class two
{
    int n;

public:
    two()
    {
        cout << "Enter the second number ";
        cin >> n;
    }
    friend void swap(one n1, two n2);
};
void swap(one n1, two n2)
{
    int temp;
    cout << "Before swaping " << n1.n << " " << n2.n << endl;
    temp = n2.n;
    n2.n = n1.n;
    n1.n = temp;
    cout << "After swaping " << n1.n << " " << n2.n << endl;
}
int main()
{
    one a;
    two b;
    swap(a, b);
    return 0;
}