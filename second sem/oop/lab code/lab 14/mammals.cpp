// Create two classes named mammals and marineanimals. Create another class named bluewhale which inherits both the above classes. Now, create function with same name on each of these classes which prints "I am Mammals", "I am marine animal" and "I belong to both the categories" respectively. Now create an object of derived class and try calling each function. What problem do you face. How would you solve this

#include <iostream>
using namespace std;
class Mammals
{
public:
    void display()
    {
        cout << "I am Mammal" << endl;
    }
};
class MarineAnimals
{
public:
    void display()
    {
        cout << "I am marine animal" << endl;
    }
};
class Bluewhale : public Mammals, public MarineAnimals
{
public:
    void display()
    {
        cout << "I belong to both the categories" << endl;
    }
};
int main()
{
    Bluewhale bb;
    bb.Mammals::display();
    bb.MarineAnimals::display();
    bb.display();
}