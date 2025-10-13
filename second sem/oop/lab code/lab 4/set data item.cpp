/*WAP designing a class to represent itam information. Include following member
-Data members                Member function
Itemid                         Set data
Cost                           Show data*/
#include<iostream>
using namespace std;
class item
{
	int itemid,cost;
	public:
		void setdata();
		void showdata();
};
void item::setdata()
{
	cout<<"Enter the id of the item: ";
	cin>>item::itemid;
	cout<<"Enter the cost of the item: ";
	cin>>item::cost;
}
void item::showdata()
{
	cout<<"The id of the item is "<<item::itemid<<endl;
	cout<<"The cost of the item is "<<item::cost<<endl;
}

int main()
{
	item a;
	a.setdata();
	a.showdata();
	return 0;
}