// iv) Multilevel
#include<iostream>
using namespace std;
class A
{
    protected:
    int roll;
    public:
    void getroll()
    {
        cout<<"Enter the roll no. ";
        cin>>roll;
    }
    void show_roll()
    {
        cout<<"Roll no. = "<<roll<<endl;
    }
};
class B: public A
{
    protected:
    int sub1,sub2;
    public:
    void getmarks()
    {
        cout<<"Enter the marks in two subjects: "<<endl;
        cin>>sub1>>sub2;
    }
    void show_marks()
    {
        cout<<"The marks in subject 1 = "<<sub1<<endl;
        cout<<"The marks in subject 2 = "<<sub2<<endl;
    }
};
class C: public B{
    public:
    void display()
    {
        show_roll();
        show_marks();
        cout<<"The total marks = "<<sub1+sub2<<endl;   
    }
};
int main()
{
    C obj;
    obj.getroll();
    obj.getmarks();
    obj.display();
}