//WAP to find sum of two number using inline function
#include<iostream>
using namespace std;
inline add(int a, int b)
{
	return a+b;
}

int main()
{
	int a,b;
	cout<<"Enter two numbers: "<<endl;
	cin>>a>>b;
	cout<<"Sum is: "<<add(a,b);
	return 0;
}