/*wap and create namespace with different function and data. Perform following 
i) scope resolution to access data and function 
ii) using keyword*/

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
int main(){
	/*std::cout<<"n from namespace jon "<<jon::n<<std::endl;
	std::cout<<"adding 2 and 4 "<<jon::add(2,4)<<std::endl;
	std::cout<<"substracting 7 from 8 "<<jon::sub(8,7)<<std::endl;*/
	cout<<"Using scope resolution"<<endl;
	cout<<"n from namespace jon "<<jon::n<<endl;
	cout<<"adding 2 and 4 "<<jon::add(2,4)<<endl;
	cout<<"substracting 7 from 8 "<<jon::sub(8,7)<<endl;
	return 0;
}