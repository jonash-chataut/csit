//WAP to overload '==' operator
#include<iostream>
using namespace std;
class equalto
{
int x;
public:
void getdata()
{
    cout<<"Enter a number: ";
    cin>>x;
}
bool operator==(equalto b)
{
    if (x==b.x)
    return true;
    else 
    return false;
}
};
int main()
{
    equalto aa,bb;
    aa.getdata();
    bb.getdata();
    if (aa==bb)
    cout<<"Both are equal";
    else
    cout<<"Not equal";
}