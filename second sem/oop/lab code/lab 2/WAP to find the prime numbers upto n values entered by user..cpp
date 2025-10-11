//WAP to find the prime numbers upto n values entered by user.
#include<iostream>
using namespace std;
int main()
{
int n,count=0;
cout<<"Enter the value upto which you want the prime numbers:"<<endl;
cin>>n;
cout<<"The prime numbers upto "<<n<<" are: "<<endl; 
for(int i=2;i<=n;i++)
{
	count=0;
	for(int j=2;j<i;j++)
	{
		if(i%j==0)
		{
			cout<<i<<endl;
		//	count++;
		}
	}
//	if(count==0)
//{
//	cout<<i<<endl;
//}
}
}