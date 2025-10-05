//WAP to find SI
#include<iostream>
using namespace std;
int main()
{
	int r,t,p;
	float SI;
	cout<<"Enter the principal value, time and rate"<<endl;
	cin>>p>>t>>r;
	SI=(p*t*r)/100;
	cout<<"The simple interest is "<<SI<<endl;
	return 0;
}