/*WAP to create derived class using different modes of inheritance
i) private
ii) public
iii) protected */

// i) Private
#include <iostream>
#include <conio.h>
using namespace std;
class Base
{
    int privatevar;

protected:
    int protectedvar;

public:
    int publicvar;
};

class Derived : private Base
{
public:
    void setdata()
    {
        // privatevar = 1; not accessible
        protectedvar = 2;
        publicvar = 3;
    }

    void displaydata()
    {
        cout << "Protectedvar = " << protectedvar << endl;
        cout << "Publicvar = " << publicvar << endl;
    }
};
int main()
{
    Derived obj;
    obj.setdata();
    obj.displaydata();
    // obj.publicvar=10; not accessible
    return 0;
}