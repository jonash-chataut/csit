//WAP to find the sum of two data members of two different classes with the help of friend function.
#include<iostream>
using namespace std;
class second;
//creating first class
class first
{
    int n;
    public:
    first ()
    {
        cout<<"Enter the first number ";
        cin>>n;
    }
    friend void sum(first a, second b);
};
//creating second class
class second
{
    int n;
    public:
    second ()
    {
        cout<<"Enter the second number ";
        cin>>n;
    }
    friend void sum(first a, second b);
};
//class friend function
void sum(first a, second b)
{
    cout<<"The sum of two numbers from two data members is "<<a.n+ b.n<<endl;
}
int main()
{
    first c1;
    second c2;
    sum(c1,c2);
    return 0;
}