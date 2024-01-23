#include <iostream>
#include <cmath>
using namespace std;
void lab1Task1() {
    cout << "Lab 1 Task 1";
}
double power(double n, int p = 2);

int main() {
    double base;
    int exponent;
    cout << "Enter a number: ";
    cin >> base;
    cout << "Do you want to enter the exponent? (1 for yes, 0 for no): ";
    int inputChoice;
    cin >> inputChoice;

    if (inputChoice) {
        cout << "Enter the exponent (>2): ";
        cin >> exponent;

        if (exponent <= 2) {
            cout << "The entered exponent is <= 2";
            return 1;
        }
    }
    else {
        exponent = 2;
    }
    double result = power(base, exponent);
    cout << "Result: " << result << endl;

    return 0;
}

double power(double n, int p) {
    return pow(n, p);
}

