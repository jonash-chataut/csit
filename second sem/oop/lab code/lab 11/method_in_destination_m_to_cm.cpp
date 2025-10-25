// WAP to convert metres into cm.[Use method in destination]
#include <iostream>
using namespace std;
class measurement
{
private:
    int metre, centimeter;

public:
    measurement(int m)
    {
        metre = m;
        centimeter = metre * 100;
    }
    void display()
    {
        cout << "Value of a in centimeter: " << centimeter << "cm" << endl;
    }
};
int main()
{
    measurement t(50);
    t.display();
    return 0;
}