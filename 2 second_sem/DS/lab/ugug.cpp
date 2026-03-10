#include<iostream>
using namespace std;
int main()
{
	int n1,n2,i,j,r;
	cout<<"Enter the no. of elements in the set A : ";
	cin>>n1;
	cout<<"Enter the no. of elements in the set B : ";
	cin>>n2;
	int A[n1],B[n2];
	
	cout<<"Enter the members of the set A"<<endl;
	for(i=0;i<n1;i++)
	{
		cout<<"Element "<<i+1<<" = ";
		cin>>A[i];
	}
	
	cout<<"Enter the members of the set B"<<endl;
	for(i=0;i<n2;i++)
	{
		cout<<"Element "<<i+1<<" = ";
		cin>>B[i];
	}

	
	//Showing set A and B to user
	cout<<"The set A = "<<"{";
	for(i=0;i<n1;i++)
	{
		cout<<A[i];
		if(i<n1-1)
		cout<<",";
	}
	cout<<"}"<<endl;
	
	cout<<"The set B = "<<"{";
	for(i=0;i<n2;i++)
	{
		cout<<B[i];
		if(i<n2-1)
		cout<<",";
	}
	cout<<"}"<<endl;
	
	//Union
	
	cout<<"The union of set A and B is: "<<endl<<"AUB = {";
    for (i = 0; i < n1; i++) {
        if (i>0)
		cout<<",";
        cout << A[i];
    }
    for(i=0;i<n2;i++) {
    
        for(j=0;j<n1;j++) {
            if (A[j]==B[i]) {
                r=1;
                
                else
                r=0;
            }
            
        }
        if (r==0) {
            cout<<","<<B[i];
        }
    }
    cout<<"}"<<endl;
	
	//Intersection
	
		cout<<"The intersection of set A and B is: "<<endl<<"AnB = {";
		for(i=0;i<n1;i++)
		{
			for(j=0;j<n2;j++)
			{
				if(A[i]==B[j])
				{
					cout<<A[i];
					if (i<n1-1)cout<<",";
					break;
				}
			}
		}
	cout<<"}"<<endl;
	
	 // Difference A - B
	 
		cout<<"The difference of set A and B is: "<<endl<<"A-B = {";
		for(i=0;i<n1;i++) {
        r=0;
        for(j=0;j<n2;j++) {
            if (A[i] == B[j]) {
                r=1;
                break;
            }
        }
        if (r==0) {
            cout << A[i];
            if (i>=0)
			cout<<",";
        }
    }
    cout<<"}"<<endl;

	return 0;
}