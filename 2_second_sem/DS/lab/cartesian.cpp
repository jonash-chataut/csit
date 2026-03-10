#include <iostream>

using namespace std;

int main(){

int n1, n2,i;

cout<<"*****CARTESIAN PRODUCT*****"<<endl;

	cout<<"___________________________________________________________"<<endl;
cout<<"enter the total elements of set a: ";

cin>>n1;

cout<<"enter the total elements of set b: ";

cin>>n2;

int a1[n1],a2[n2];

	cout<<"___________________________________________________________"<<endl;
cout<<endl<<"Enter the elements of set A:"<<endl;
for(i=0;i<n1;i++) {

cout<<"element "<<i+1<<": ";

cin>>a1[i];
}

	cout<<"___________________________________________________________"<<endl;
cout<<endl<<"Enter the elements of set B:"<<endl;
for(int j=0;j<n2;j++){
	cout<<"element "<<j+1<<": ";
	cin>>a2[j];
}

	cout<<"___________________________________________________________"<<endl;
cout<<endl<<"The elements of the set A are: "<<endl;
cout<<"{";
for (i=0;i<n1;i++)
{
	cout<<a1[i];
	if(i<n1-1)
	cout<<",";
}
cout<<"}"<<endl;

	cout<<"___________________________________________________________"<<endl;
cout<<endl<<"The elements of the set B are: "<<endl;
cout<<"{";
for (i=0;i<n2;i++)
{
	cout<<a2[i];
	if(i<n2-1)
	cout<<",";
}
cout<<"}"<<endl;

	cout<<"___________________________________________________________"<<endl;
cout<<"The cartesian product of set A and B is"<<endl<<"A"<<"x"<<"B"<<"=";
	cout<<"{";
	for(i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		{
			cout<<"("<<a1[i]<<","<<a2[j]<<")";
			if(j<n2-1)
	cout<<",";
		}
	}
	cout<<"}";
	return 0;
}