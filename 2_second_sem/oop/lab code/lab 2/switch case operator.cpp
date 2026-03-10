//WAP to perform arthmetic operation on two numbers using switch case
#include<iostream>
using namespace std;
int main(){
	float a,b,r;
	char c;
	cout<<"Input two number: "<<endl;
	cin>>a>>b;
	cout<<"Enter the operator you want to do: "<<endl;
	cin>>c;
	switch(c)
	{
		case'+':
			r=a+b;
			cout<<"The result is "<<a<<"+"<<b<<"="<<r;
			break;
			
			case'-':
			r=a-b;
			cout<<"The result is "<<a<<"-"<<b<<"="<<r;
			break;
			
			case'*':
			r=a*b;
			cout<<"The result is "<<a<<"*"<<b<<"="<<r;
			break;
			
			case'/':
			r=a/b;
			cout<<"The result is "<<a<<"/"<<b<<"="<<r;
			break;
			default:
				cout<<"Error"<<endl;
				break;
	}
	return 0;
}