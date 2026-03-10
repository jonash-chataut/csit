// iii) Hierarchical inheritance
#include <iostream>
using namespace std;
class A
{
public:
    void message()
    {
        cout << "Welcome to hierarchical inheritance" << endl;
    }
};
class B : public A
{
public:
    void display()
    {
        cout << "Inisde class B" << endl;
    }
};
class C : public A
{
public:
    void output()
    {
        cout << "Inside class C" << endl;
    }
};
int main()
{
    B objb;
    C objc;
    objb.display();
    objb.message();
    objc.output();
    objc.message();
    return 0;
}