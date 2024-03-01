#include <iostream>
#include <limits> 

using namespace std;

class Rectangle {
private:
    double a;
    double b;

public:
    Rectangle(double side1, double side2) : a(side1), b(side2) {}

    double area() {
        return a * b;
    }

    double area(double side) {
        return side * side;
    }
};

int main() {
    double side1, side2;

    cout << "Enter the sides: ";
    cin >> side1;

    if (cin.peek() == '\n') {
        Rectangle square(side1, side1);
        double area = square.area(side1);
        cout << "Area of the square: " << area << endl;
    }
    else {
        cin >> side2;
        Rectangle rectangle(side1, side2);
        double area = rectangle.area();
        cout << "Area of the rectangle: " << area << endl;
    }


    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return 0;
}
