//WAP to multiply two complex numbers using the concept of pass by reference taking object as an argument.
#include<iostream>
using namespace std;
class complex
{
	int r,i;
	public:
		void get()
		{
			cout<<"Enter the real and imaginary part of the complex number:"<<endl;
			cin>>r>>i;
		}
		
		void show()
		{
			cout<<r<<"+"<<"i"<<i<<endl;
		}
		
		void multiply(complex &x, complex &y)
		{
			r=x.r*y.r-x.i*y.i;
			i=x.r*y.i+x.i*y.r;
		}
};

int main()
{
	cout<<"Using pass by reference concept"<<endl;
	complex a,b,c;
	a.get();
	b.get();
	c.multiply(a,b);
	c.show();
	return 0;
}