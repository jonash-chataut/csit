//WAP to find factorial of a number using 
//recursive function
#include<iostream>
using namespace std;
int facto(int n)
{
	int fac;
	if(n<=1)
	{
		return 1;
	}
	else 
	return n*facto(n-1);
}
int main()
{
	int num;
	cout<<"Using recurisve function:"<<endl;
	cout<<"Enter a number:"<<endl;
	cin>>num;
	cout<<"The factorial is: "<<facto(num)<<endl;
	return 0;
}