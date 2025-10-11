//WAP to overloaded function to find area of triangle with three sides, square and circle. Note for triangle take one side fixed value of 5
#include <iostream>
#include<cmath>
const float PI = 3.14159;

using namespace std;

float area(float radius) {
    return PI * radius * radius;
}

float area_sq(float side) {
    return side * side;
}

float area(float s1, float s2, float s3=5) {
    float s = (s1 + s2 + s3) / 2;
    return sqrt(s * (s - s1) * (s - s2) * (s - s3));
}

int main() {
	int r,l,s1,s2;
	cout<<"Enter the radius of the circle: "<<endl;
	cin>>r;
	cout<<"Enter the length of the side of square: "<<endl;
	cin>>l;
	cout<<"Enter the value of remaining two sides of triangle one side is fixed at 5:"<<endl;
    cin>>s1>>s2;
    cout << "Area of circle: " << area(r) << endl;
    cout << "Area of square: " << area_sq(l) << endl;
    cout << "Area of triangle: " << area(s1,s2) << endl;
    return 0;
}
