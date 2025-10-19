//b) return by reference
#include<iostream>
using namespace std;
class multiply
{
	int n;
	public:
		void get()
		{
			cout<<"Enter a number: ";
			cin>>n;
		}
		
		multiply multi(multiply &x, multiply &y)
		{
			multiply mul;
			mul.n=x.n*y.n;
			return mul;
		}
		
		void display()
		{
			cout<<n<<endl;
		}
};

int main()
{
	multiply a,b,c;
	cout<<"Using return by reference concept"<<endl;
	cout<<"First number"<<endl;
	a.get();
	cout<<"Second number"<<endl;
	b.get();
	c=c.multi(a,b);
	cout<<"The multiplication is: ";
	c.display();
}