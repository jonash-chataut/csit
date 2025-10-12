//WAP to show type conscusion iplicit and explicit
#include<iostream>
using namespace std;
int main ()
{
	int a,b;
	float r;
	a=7;
	b=4;
	cout<<"Dividing 7 by 4 in both cases"<<endl;
	cout<<"Implicit case:"<<endl;
	r=a/b;
	cout<<r<<endl;
	cout<<"Explicit case:"<<endl;
	r=float(a)/b;
	cout<<r<<endl;
	return 0;
}