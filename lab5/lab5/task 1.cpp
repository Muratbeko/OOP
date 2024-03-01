#include <iostream>
#include <stdexcept>
#include <climits> // For INT_MIN and INT_MAX

using namespace std;

class Int {
private:
    int value;
public:
    Int(int value) : value(value) {}

    Int operator+(const Int& other) const {
        long long result = static_cast<long long>(value) + static_cast<long long>(other.value);
        if (result > INT_MAX || result < INT_MIN) {
            throw overflow_error("Overflow occurred");
        }
        return Int(static_cast<int>(result));
    }

    Int operator-(const Int& other) const {
        long long result = static_cast<long long>(value) - static_cast<long long>(other.value);
        if (result > INT_MAX || result < INT_MIN) {
            throw overflow_error("Overflow occurred");
        }
        return Int(static_cast<int>(result));
    }

    Int operator*(const Int& other) const {
        long long result = static_cast<long long>(value) * static_cast<long long>(other.value);
        if (result > INT_MAX || result < INT_MIN) {
            throw overflow_error("Overflow occurred");
        }
        return Int(static_cast<int>(result));
    }

    Int operator/(const Int& other) const {
        if (other.value == 0) {
            throw invalid_argument("Division by zero");
        }
        return Int(value / other.value);
    }

    friend ostream& operator<<(ostream& os, const Int& obj) {
        return os << obj.value;
    }
};

int main() {
    while (true) {
        try {
            int choice;
            int x, y;

            cout << "Choose an operation:" << endl;
            cout << " +" << endl;
            cout << "-" << endl;
            cout << " *" << endl;
            cout << " /" << endl;
            cout << "0 Exit" << endl;
            cout << "Your choice: ";
            cin >> choice;

            if (choice == 0) {
                cout << "Exiting program" << endl;
                break;
            }

            cout << "Enter two integers: ";
            cin >> x >> y;

            Int a(x);
            Int b(y);
            Int result(0);

            switch (choice) {
            case '+':
                result = a + b;
                cout << "Sum: " << result << endl;
                break;
            case  '-':
                result = a - b;
                cout << "Difference: " << result << endl;
                break;
            case '*':
                result = a * b;
                cout << "Product: " << result << endl;
                break;
            case '/':
                result = a / b;
                cout << "Quotient: " << result << endl;
                break;
            default:
                cout << "Invalid operation choice" << endl;
            }
        }
        catch (const overflow_error& e) {
            cout << "Overflow error: " << e.what() << endl;
        }
        catch (const invalid_argument& e) {
            cout << "error: " << e.what() << endl;
        }
    }

    return 0;
}

