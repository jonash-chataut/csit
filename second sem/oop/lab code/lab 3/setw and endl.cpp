//WAP to demonstrate use of endl and setw manipulator.
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int num=7;
	cout<<"Use of endl"<<endl<<"Demonstrated"<<endl;
	cout<<"Use of setw"<<endl;
	cout<<"Before setting width"<<num<<endl;
	cout<<"Setting width to 10"<<setw(10)<<num<<endl;
	return 0;
}