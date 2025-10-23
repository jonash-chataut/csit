// WAP to overload '=' operator
#include <iostream>
using namespace std;
class demo
{
    int a;

public:
    void getdata()
    {
        cout << "Enter a number: ";
        cin >> a;
    }
    void putdata()
    {
        cout << "Value =" << a << endl;
    }
    void operator=(demo bb)
    {
        a = bb.a;
    }
};
int main()
{
    demo aa, cc;
    aa.getdata();
    cc = aa;
    cc.putdata();
    return 0;
}