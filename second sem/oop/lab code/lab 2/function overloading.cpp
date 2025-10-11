//WAP to overload area function to calculate area of triangle, rectangle, square and circle
#include <iostream>
#include<cmath>
const float PI = 3.14159;

using namespace std;

float area(float radius) {
    return PI * radius * radius;
}

float area(float length, float width) {
    return length * width;
}

float area_sq(float side) {
    return side * side;
}

float area(float side1, float side2, float side3) {
    float s = (side1 + side2 + side3) / 2;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

int main() {
    cout << "Area of circle (radius = 5): " << area(5) << endl;//area(5.0f) point lekhe vane chai f use garne natra pardaina
    cout << "Area of rectangle (length = 4, width = 6): " << area(4, 6) << endl;
    cout << "Area of square (side = 5): " << area_sq(5) << endl;
    cout << "Area of triangle (side1 = 3, side2 = 4, side3 = 5): " << area(3, 4, 5) << endl;

    return 0;
}
