/*WAP to create class named calculator that contains private data members x and y of integers type. Also define following member functions.
a) Add to return the result summing x and y.
b) Multi to return of multiply x and y.
c) Constructor to initialize object data members x and y.
d) Parameterized constructor to initialize the value of x and y given by user.
e) Copy constructor to initialize the value of another object.
f) In the above code make y as static data member and mul as static member function and perform operation.*/

#include<iostream>
using namespace std;
class calculator
{
	int x;
	static int y;
	public:
		//default constructor
		/*calculator()
		{
			x=0;
			//cin>>x>>y;
		}*/
		
		calculator()
		{
			cout<<"Enter two numbers:"<<endl;
			cin>>x>>y;
		}
		
		//parametrized constructor
		calculator(int a, int b)
		{
			x=a;
			y=b;
		}
		
		//copy constructor
		calculator(calculator &cal)
		{
			x=cal.x;
			y=cal.y;
		}
		
		int add()
		{
			return x+y;
		}
		
		static int mul(int n1, int n2)
		{
			return n1*n2;
		}
		
		int multi()
		{
			return mul(x,y);
		}
};
int calculator::y;

int main()
{
	//default constructor
	calculator c1;
	cout<<"The addition of two numbers is "<<c1.add()<<endl<<"The multiplication of two numbers is "<<c1.multi()<<endl;
	
	//parametrized constructor
	calculator c2(4,5);
	cout<<"The addition of two numbers is "<<c2.add()<<endl;
	cout<<"The multiplication of two numbers is "<<c2.multi()<<endl;
	
	//copy constructor
	calculator c3(c2);
	cout<<"The addition (copy) of two numbers is "<<c3.add()<<endl;
	cout<<"The multiplication (copy) of two numbers is "<<c3.multi()<<endl;
}