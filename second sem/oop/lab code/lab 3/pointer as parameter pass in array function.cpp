/*WAP to pass array in function to find maximum element of the array entered by user using 
a) pointer as parameter 
b) sized array as parameter 
c) unsized array as parameter*/

//a) pointer as parameter
#include<iostream>
using namespace std;
 int array(int *ptr)
 {
 	int lar;
 	lar=*ptr;
 	for (int i=0;i<5;i++)
 	{
 		if(*(ptr+i)>lar)
 		{
 			lar=*(ptr+i);
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