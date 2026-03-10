//WAP to find factorial of a number using 
//non-recursive function
#include<iostream>
using namespace std;
int facto(int n)
{
	int fac=1;
	for(int i=1;i<=n;i++)
	{
		fac=fac*i;
	}
	return fac;
}
int main()
{
	int num;
	cout<<"Using non-recurisve function:"<<endl;
	cout<<"Enter a number:"<<endl;
	cin>>num;
	cout<<"The factorial is: "<<facto(num)<<endl;
	return 0;
}