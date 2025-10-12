/*WAP to pass array in function to find maximum element of the array entered by user using 
a) pointer as parameter 
b) sized array as parameter 
c) unsized array as parameter*/

//c) unsized array as parameter
#include<iostream>
using namespace std;
 int array(int ary[])
 {
 	int lar;
 	lar=*ary;
 	for (int i=0;i<5;i++)
 	{
 		if(ary[i]>lar)
 		{
 			lar=ary[i];
		 }
	}
	 return lar;
 }
 
 int main()
 {
 	int ar[5];
 	cout<<"Enter the elements of array"<<endl;
 	for(int i=0;i<5;i++)
 	{
 		cin>>ar[i];
	}
	 cout<<"The largest element of the array is "<<array(ar)<<endl;
	 return 0;
 }