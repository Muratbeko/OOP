#include <iostream>

using namespace std;

class Fraction {
private:
    double chislo;
public:
    Fraction() : chislo(0) {}

    Fraction(double value) : chislo(value) {}

    Fraction operator+(const Fraction& other) const {
        return Fraction(chislo + other.chislo);
    }

    Fraction operator+(double value) const {
        return Fraction(chislo + value);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(chislo - other.chislo);
    }

    Fraction operator-(double value) const {
        return Fraction(chislo - value);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(chislo * other.chislo);
    }

    Fraction operator*(double value) const {
        return Fraction(chislo * value);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.chislo == 0) {
            cerr << "Division by zero!" << endl;
            return *this;
        }
        return Fraction(chislo / other.chislo);
    }

    Fraction operator/(double value) const {
        if (value == 0) {
            cerr << "Division by zero!" << endl;
            return *this;
        }
        return Fraction(chislo / value);
    }

    Fraction operator++(int) {
        Fraction temp(*this);
        chislo++;
        return temp;
    }

    Fraction& operator++() {
        chislo++;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Fraction& frac) {
        os << frac.chislo;
        return os;
    }

    friend Fraction operator*(int value, const Fraction& frac) {
        return Fraction(value * frac.chislo);
    }
};

int main() {
    double num1, num2;
    char operation;

    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the operation (+, -, *, /): ";
    cin >> operation;
    cout << "Enter the second number: ";
    cin >> num2;

    Fraction f1(num1);
    Fraction f2(num2);
    Fraction result;

    switch (operation) {
    case '+':
        result = f1 + f2;
        break;
    case '-':
        result = f1 - f2;
        break;
    case '*':
        result = f1 * f2;
        break;
    case '/':
        result = f1 / f2;
        break;
    default:
        cerr << "Invalid operation!" << endl;
        return 1;
    }

    cout << "Result: " << result << endl;

    return 0;
}


