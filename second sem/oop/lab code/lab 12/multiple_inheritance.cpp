// ii) Multiple inheritance
#include <iostream>
using namespace std;
class A
{
protected:
    int a;

public:
    void input()
    {
        cout << "Enter a number: ";
        cin >> a;
    }
};
class B
{
protected:
    int b;
    int y;

public:
    void getdata()
    {
        cout << "Enter another number: ";
        cin >> b;
    }
};
class C : public A, public B
{
public:
    void sum()
    {
        cout << "The sum of given two numbers is " << a + b << endl;
    }
};
int main()
{
    C obj;
    obj.input();
    obj.getdata();
    obj.sum();
    return 0;
}
