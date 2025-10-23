//WAP to overload '*' operator
#include<iostream>
#include<conio.h>
using namespace std;
class multiply
{
    int a;
    public:
    void getdata()
    {
        cout<<"Enter a number: ";
        cin>>a;
    }
    void putdata()
    {
        cout<<"Multiply of given two numbers is "<<a;
    }
 multiply operator* (multiply b)
    {
        multiply c;
        c.a = a * b.a;
        return c;
    }
};
int main()
{
 multiply aa,bb,cc;
    aa.getdata();
    bb.getdata();
    cc=aa*bb;
    cc.putdata();
    getch();
    return 0;
}