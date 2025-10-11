//ii) using keyword

#include<iostream>
using namespace std;
namespace jon
{
	int n=17;
	
	int add(int a, int b)
	{
		return a+b;
	}
	
	int sub(int a, int b)
	{
		return a-b;
	}
}
using namespace jon;
int main(){
	cout<<"Using keyword"<<endl;
	cout<<"n from namespace jon "<< n <<endl;
	cout<<"adding 2 and 4 "<<add(2,4)<<endl;
	cout<<"substracting 7 from 8 "<<sub(8,7)<<endl;
	return 0;
}