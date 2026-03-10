// WAP to show constructor and desctructor.
#include <iostream>
using namespace std;
class oop
{
    int x, y;

public:
    oop()
    {
        cout << "Constructor is called" << endl
             << "Enter any two number: ";
        cin >> x >> y;
    }
    ~oop()
    {
        cout << "Destructor is called" << endl<< "The provided numbers are" << endl<< x << endl<< y << endl;
    }
};
int main()
{
    oop a;
    return 0;
}