//WAP to find the area and perimeter of rectangle usnig concept of class and object
#include<iostream>
using namespace std;

class rectangle
{
	int l,b;
	public:
		void get()
		{
			cout<<"Enter the length:"<<endl;
			cin>>l;
			cout<<"Enter the breadth:"<<endl;
			cin>>b;
		}	
		int area()
		{
			return l*b;
		}
		int perimeter()
		{
			return 2*(l+b);
		}
};
int main()
{
	rectangle r;
	r.get();
	cout<<"The area of the rectangle is "<<r.area()<<endl;
	cout<<"The perimeter of the rectangle is "<<r.perimeter()<<endl;
	return 0;
}