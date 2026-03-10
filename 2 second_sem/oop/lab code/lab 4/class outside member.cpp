//WAP to set and show data by using concept of class. Define member function outside class.
#include<iostream>
using namespace std;

class concept
{
	int x;
	public:
		void getdata();
};

void concept::getdata()
{
	cout<<"Enter a number: ";
	cin>>x;
	cout<<"The entered number is "<<x<<endl;
}

int main ()
{
	concept a;
	a.getdata();
	return 0;
}