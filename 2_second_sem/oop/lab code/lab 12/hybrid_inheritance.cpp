#include <iostream>
using namespace std;
class A
{
public:
    void putdata()
    {
        cout << "****** Inside class A ******" << endl;
    }
};
class B : public A
{
public:
    void display()
    {
        cout << "****** Inside class B ******" << endl;
    }
};
class C
{
public:
    void message()
    {
        cout << "****** Inside class C ******" << endl;
    }
};
class D : public B, public C
{
public:
    void print()
    {
        cout << "****** Inside class D ******" << endl;
    }
};
int main()
{
    D aa;
    aa.putdata();
    aa.display();
    aa.message();
    aa.print();
    return 0;
}