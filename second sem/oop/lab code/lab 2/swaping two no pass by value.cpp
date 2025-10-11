/*WAP to swap two numbers using 
a) Call by value
b) Call by reference
c) Call by pointer*/

//a)Call by value
#include<iostream>
using namespace std;
void swap(int a, int b)
{
	int c;
	cout<<"Before swaping:"<<a<<" "<<b<<endl;
	c=a;
	a=b;
	b=c;
	cout<<"After swaping:"<<a<<" "<<b<<endl;
}
int main(){
	int n1,n2;
	cout<<"Enter two numbers: "<<endl;
	cin>>n1>>n2;
	swap(n1,n2);
	return 0;
}

