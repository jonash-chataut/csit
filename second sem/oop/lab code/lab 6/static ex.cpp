//static and counter example
#include<iostream>
using namespace std;
 class count
 {
 	int x;
 	//int counter=0;
 	static int counter;
 	public:
 	void employe()
 	{
 		cout<<"the id: "<<endl;
 		cin>>x;
counter++;
	 }
	 
	 void show()
	 {
	 	cout<<"Id "<<x<<"This is employe no. "<<counter<<endl;
	 }
 };
 int count:: counter;
 
 int main()
 {
 	count c1,c2;
 	c1.employe();
 	c1.show();
 	c2.employe();
 	c2.show();
 }