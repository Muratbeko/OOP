#include <iostream>
#include <string>
using namespace std;

const int maxFactories = 10;
const int maxEmployees = 10;

struct Employee {
    string surname;
    int age;
    string specialty;
    double averageSalary;
};

int main() {
    int numFactories;

    cout << "Enter the number of factories: ";
    cin >> numFactories;

    Employee allEmployees[maxFactories * maxEmployees];

    int totalEmployees = 0;
    for (int i = 0; i < numFactories && totalEmployees < maxFactories * maxEmployees; ++i) {
        int numEmployees;
        cout << "Factory " << i + 1 << " - Enter the number of employees: ";
        cin >> numEmployees;

        for (int j = 0; j < numEmployees && totalEmployees < maxFactories * maxEmployees; ++j) {
            cout << "Employee " << j + 1 << ":\n";
            Employee& employee = allEmployees[totalEmployees];
            cout << "Surname: ";
            cin >> employee.surname;
            cout << "Age: ";
            cin >> employee.age;
            cout << "Specialty: ";
            cin >> employee.specialty;
            cout << "Average Salary: ";
            cin >> employee.averageSalary;

            totalEmployees++;
        }
    }

    int locksmithCount = 0, turnerCount = 0, otherSpecialtyCount = 0;

    for (int i = 0; i < totalEmployees; ++i) {
        const Employee& employee = allEmployees[i];
        if (employee.specialty == "locksmith") {
            locksmithCount++;
        }
        else if (employee.specialty == "turner") {
            turnerCount++;
        }
        else {
            otherSpecialtyCount++;
        }
    }

    cout << "Number of Locksmiths: " << locksmithCount << endl;
    cout << "Number of Turners: " << turnerCount << endl;
    cout << "Number of Employees with Other Specialties: " << otherSpecialtyCount << endl;

    return 0;
}


