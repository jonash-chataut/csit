/* WAP to show following
i) Single inheritance
ii) Multiple inheritance
iii) Hierarchical inheritance
iv) Multilevel inheritance
v) Hybrid inheritance*/
// i) Single inheritance
#include <iostream>
#include <conio.h>
using namespace std;
class A
{
protected:
    int x;

public:
    void input()
    {
        cout << "Enter a number: ";
        cin >> x;
    }
};
class B : public A
{
    int y;

public:
    void getdata()
    {
        cout << "Enter another number: ";
        cin >> y;
    }
    void sum()
    {
        cout << "The sum of the given two numbers is " << x + y << endl;
    }
};
int main()
{
    B obj;
    obj.input();
    obj.getdata();
    obj.sum();
    return 0;
}