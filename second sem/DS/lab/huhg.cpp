/*WAP to represent the set to computer representation
Hint:
{User read to input universal set}*/

#include<iostream>
using namespace std;
int main ()
{
	//For taking elements from universal set 
	int n,i;
	cout<<"Enter the no. of elements you want in the universal set: ";
	cin>>n;
	int u[n],a[n],c[n],r;
	cout<<"Enter the elements of the universal set: "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"Element "<<i+1<<" = ";
		cin>>u[i];
	}
	
	//For taking elements of set A
	int na;
	cout<<endl<<"Enter the no. of elements that are present in set A: ";
	cin>>na;
		cout<<"Enter the elements of setA: "<<endl;
	for(i=0;i<na;i++)
	{
		cout<<"Element "<<i+1<<" = ";
		cin>>a[i];
	}
	
	//Showing the sets input by user to user
	
	cout<<endl<<"The universal set "<<endl<<"U = {";
	for(i=0;i<n;i++)
	{
		cout<<u[i];
		if(i<n-1)
		cout<<",";
	}
	cout<<"}"<<endl;
	
		cout<<"The set "<<endl<<"A = {";
	for(i=0;i<na;i++)
	{
		cout<<a[i];
			if(i<na-1)
		cout<<",";
	}
	cout<<"}"<<endl;
	
	//Converting set to computer representation
	for(i=0;i<n;i++)
	{
		for(int j=0;j<na;j++)
		{
			if(u[i]==a[j])
			{
				r=1;
			}
			
			}
			if(r==1)
			{
				c[i]=1;
			}
			else
			{
				c[i]=0;
			}
			r=0;
		}
	
	
	//Showing computer representation to the user
	cout<<endl<<"The computer representation of the given set A is "<<endl<<"A = ";
	for(i=0;i<n;i++)
	{
	cout<<c[i];
	}
	return 0;
}