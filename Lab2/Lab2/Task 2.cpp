#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Student
{
public:
    string Surname;
    string Name;
    string DateOfBirth;
    string PhoneNumber;

    void setStudent(string SN, string N, string DB, string PN)
    {
        Surname = SN;
        Name = N;
        DateOfBirth = DB;
        PhoneNumber = PN;
    }

    void showStudent() const
    {
        cout << left << setw(20) << Surname
            << left << setw(15) << Name
            << left << setw(20) << DateOfBirth
            << left << setw(15) << PhoneNumber << endl;
    }
};

class StudentGroup
{
private:
    const int maxSize = 100;
    Student students[100];
    int numberOfStudents;

public:
    StudentGroup() : numberOfStudents(0) {}

    void addStudent(const Student& newStudent)
    {
        if (numberOfStudents < maxSize)
        {
            students[numberOfStudents++] = newStudent;
        }
        else
        {
            cout << "������ �����, ���������� �������� ������ ��������." << endl;
        }
    }

    void removeStudent(const string& surname)
    {
        Student* it = nullptr;

        for (Student* i = students; i != students + numberOfStudents; ++i)
        {
            if (i->Surname == surname)
            {
                it = i;
                break;
            }
        }

        if (it != nullptr)
        {
            *it = students[--numberOfStudents];
        }
        else
        {
            cout << "������� � �������� " << surname << " �� ������." << endl;
        }
    }

    Student findStudentBySurname(const string& surname) const
    {
        const Student* it = nullptr;

        for (const Student* i = students; i != students + numberOfStudents; ++i)
        {
            if (i->Surname == surname)
            {
                it = i;
                break;
            }
        }

        if (it != nullptr)
        {
            return *it;
        }
        else
        {
            return Student{};
        }
    }

    void sortStudentsBySurname()
    {
        sort(students, students + numberOfStudents,
            [](const Student& a, const Student& b) {
                return a.Surname < b.Surname;
            });
    }

    void displayAllStudents() const
    {
        cout << left << setw(20) << "�������"
            << left << setw(15) << "���"
            << left << setw(20) << "���� �������� "
            << left << setw(15) << " ����� ��������" << endl;

        for (int i = 0; i < numberOfStudents; ++i)
        {
            students[i].showStudent();
        }
    }
};

void printMenu()
{
    cout << "����:" << endl;
    cout << "1. �������� ��������" << endl;
    cout << "2. ������� ��������" << endl;
    cout << "3. ����� �������� �� �������" << endl;
    cout << "4. ���������� ��������� �� �������" << endl;
    cout << "5. �������� ���� ���������" << endl;
    cout << "0. �����" << endl;
    cout << "�������� ��������: ";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    StudentGroup group;

    while (true)
    {
        printMenu();

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "������� ���������� � ��������:" << endl;
            string surname, name, dateOfBirth, phoneNumber;
            cout << "�������: ";
            cin >> surname;
            cout << "���: ";
            cin >> name;
            cout << "���� ��������: ";
            cin >> dateOfBirth;
            cout << "����� ��������: ";
            cin >> phoneNumber;

            Student newStudent;
            newStudent.setStudent(surname, name, dateOfBirth, phoneNumber);
            group.addStudent(newStudent);
            break;
        }
        case 2:
        {
            cout << "������� ������� �������� ��� ��������: ";
            string surname;
            cin >> surname;
            group.removeStudent(surname);
            break;
        }
        case 3:
        {
            cout << "������� ������� �������� ��� ������: ";
            string surname;
            cin >> surname;

            Student foundStudent = group.findStudentBySurname(surname);
            if (!foundStudent.Surname.empty())
            {
                cout << "\n������ �������:\n";
                foundStudent.showStudent();
            }
            else
            {
                cout << "������� � �������� " << surname << " �� ������." << endl;
            }
            break;
        }
        case 4:
            group.sortStudentsBySurname();
            cout << "�������� ������������� �� �������." << endl;
            break;
        case 5:
            group.displayAllStudents();
            break;
        case 0:
            cout << "����� �� ���������." << endl;
            return 0;
        default:
            cout << "������������ ����. ���������� �����." << endl;
            break;
        }
    }

    return 0;
}
