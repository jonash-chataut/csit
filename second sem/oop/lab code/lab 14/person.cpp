// Create a class named person with data members name and code. Derive a class named account with data member pay(flaot). Also derive, another class named admin with data member experience from person. Now derive class master from account and admin with data member company name. Create function to input data from user for each class. Also create function to display each data.
// Create object of derived master class to input and display data. What problem do you face? Solve the problem as well.
#include <iostream>
#include <string>
using namespace std;
class person
{
protected:
    int code;
    string name;

public:
    void input()
    {
        cout << "Enter the name of the person: ";
        getline(cin, name);
        cout << "Enter the code of the person: ";
        cin >> code;
    }
    void display()
    {
        cout << "The name of the person is " << name << endl
             << "Code = " << code << endl;
    }
};
class account : public virtual person
{
protected:
    float pay;

public:
    void get_pay()
    {
        cout << "Enter the payment: ";
        cin >> pay;
    }
    void show_pay()
    {
        cout << "The payment is " << pay << endl;
    }
};
class admin : public virtual person
{
protected:
    int exp;

public:
    void get_exp()
    {
        cout << "Enter the experience of the person: ";
        cin >> exp;
    }
    void show_exp()
    {
        cout << "The experience of the person is " << exp << " yrs" << endl;
    }
};
class master : public admin, public account
{
    string comp_name;

public:
    void get_name()
    {
        cin.ignore();
        cout << "Enter the name of the company: ";
        getline(cin, comp_name);
    }
    void show_name()
    {
        cout << "The name of the company is '" << comp_name << "'" << endl;
    }
};
int main()
{
    master aa;
    aa.input();
    aa.get_pay();
    aa.get_exp();
    aa.get_name();
    aa.display();
    aa.show_pay();
    aa.show_exp();
    aa.show_name();
}