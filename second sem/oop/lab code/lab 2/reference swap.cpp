//reference swap
#include<iostream>
using namespace std;
void swapbyreference(int &a, int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

int main()
{
	int n1=4,n2=10;
	cout<<"By reference:"<<endl;
	cout<<"Before swaping:"<<endl;
	cout<<n1<<" "<<n2<<endl;
	swapbyreference(n1,n2);
	cout<<"After swaping:"<<endl;
	cout<<n1<<" "<<n2<<endl;
	return 0;
}