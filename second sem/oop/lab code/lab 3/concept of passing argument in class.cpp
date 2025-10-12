//WAP to find sum of two complex number entered by user using concept of passing object as argument.[Use pass by value]
#include<iostream>
using namespace std;
class complex
{
	int r,i;
	public:
		void get()
		{
			cout<<"Enter the real part of the complex number: ";
			cin>>r;
			cout<<"Enter the imaginary part of the complex number: ";
			cin>>i;
		}
		
		void sum(complex x, complex y)
		{
			r=x.r+y.r;
			i=x.i+y.i;
		}
		
		void show()
		{
			cout<<"The sum of two complex number is "<<r<<"+"<<i<<"i"<<endl;
		}
};

int main()
{
	complex a,b,c;
	a.get();
	b.get();
	c.sum(a,b);
	c.show();
	return 0;
}