//WAP to find the area of square and display the result using concept of friend function.
#include<iostream>
using namespace std;
class areasq
{
    int l;
    public:
    areasq()
    {
        cout<<"Enter the length of the square ";
        cin>>l;
    }
    int area()
    {
        return l*l;
    }
    friend void display(areasq s);
};
void display(areasq s)
{
    cout<<"The area of the square is "<<s.area()<<endl;
}
int main()
{
    areasq a;
    a.area();
    display(a);
    return 0;
}