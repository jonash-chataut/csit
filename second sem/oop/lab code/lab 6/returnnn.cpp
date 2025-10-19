#include<iostream>
using namespace std;
class comp
{
	int z;
	public:
	void getdata()
	{
		cout<<"Enter the number= ";			
		cin>>z;
	}
	void display()
	{
		cout<<"Multiplication= "<<z<<endl;
	}
	comp mul1(comp a,comp b)
	{//return by value
		comp temp;
		temp.z=a.z*b.z;
		return temp;
	}
	comp &mul2(comp &a,comp &b)
	{//pass by reference
		comp temp;
		temp.z=a.z*b.z;
		return temp;
	}
		comp *mul3(comp *a,comp *b)
	{//pass by pointer ma -> operator use hannu parxa
		comp *temp=new comp;
		temp->z=a->z*b->z;
		return temp;
	}
}c1,c2,c3,*c4;
int main()
{	cout << "Enter first complex number:" << endl;
	c1.getdata();
	cout << "Enter second complex number:" << endl;
	c2.getdata();
	c3=c3.mul1(c1,c2);
	cout<<"Multiplication of the number"<<endl;
	c3.display();
	c3=c3.mul2(c1,c2);
	cout<<"Multiplication of the number"<<endl;
	c3.display();
	c4=c4->mul3(&c1,&c2);
	cout<<"Multiplication of the number"<<endl;
	c4->display();	
}