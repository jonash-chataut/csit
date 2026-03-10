//WAP to overload '*' operator
#include<iostream>
using namespace std;
class multiply
{
    int x;
    public:
    multiply()
    {
        x=2;
    }

    multiply(int a)
    {
       this->x=a;
    }
    void show()
    {
        cout<<x;
    }
    multiply operator *(multiply m)
    {
        return x*m.x;
    }
};
int main()
{
    multiply a,c;
    multiply b(9);
    c=a*b;
    c.show();
}