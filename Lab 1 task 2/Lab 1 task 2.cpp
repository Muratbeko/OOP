#include <iostream>
#include <cmath>
using namespace std;
void lab1Task2() {
    // Код для выполнения Lab 1 Task 1
    cout << "Lab 1 Task 2 ";
}
double power(double n, int p = 2);

double power(char n, int p = 2) {
    return pow(static_cast<double>(n), p);
}

double power(short int n, int p = 2) {
    return pow(static_cast<double>(n), p);
}

double power(long int n, int p = 2) {
    return pow(static_cast<double>(n), p);
}

double power(float n, int p = 2) {
    return pow(static_cast<double>(n), p);
}

double power(double n, int p) {
    return pow(n, p);
}

int main() {
    double doubleValue;
    cout << "Enter a double value: ";
    cin >> doubleValue;
    cout << "Result (Double): " << power(doubleValue) << endl;

    char charValue;
    cout << "Enter a char value: ";
    cin >> charValue;
    cout << "Result (Char): " << power(charValue) << endl;

    short int shortIntValue;
    cout << "Enter a short int value: ";
    cin >> shortIntValue;
    cout << "Result (Short Int): " << power(shortIntValue) << endl;

    long int longIntValue;
    cout << "Enter a long int value: ";
    cin >> longIntValue;
    cout << "Result (Long Int): " << power(longIntValue) << endl;

    float floatValue;
    cout << "Enter a float value: ";
    cin >> floatValue;
    cout << "Result (Float): " << power(floatValue) << endl;

    return 0;
}
